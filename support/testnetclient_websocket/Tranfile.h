#ifndef __TRANFILE_H__
#define __TRANFILE_H__
/*****************************************************************************
Copyright (c) netsecsp 2012-2032, All rights reserved.

Developer: Shengqian Yang, from China, E-mail: netsecsp@hotmail.com, last updated 05/01/2022
http://ahttp.sf.net

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the
above copyright notice, this list of conditions
and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/
#include <frame/AsynNetwork_internal.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace asynsdk;

class CTranfile :
        public asyn_message_events_impl
{
public:
    CTranfile(IAsynFrameThread *lpAsynFrameThread, IAsynIoOperation *lpAsynIoOperation, IAsynRawSocket* lpAsynRawSocket)
      : m_spAsynPtlSocket(lpAsynRawSocket)
    {
        CreateAsynFrame(lpAsynFrameThread, 0, &m_spAsynFrame);

        m_spAsynFrame->CreateAsynIoOperation(0, 0, &m_spAsynIoOperation);
        lpAsynFrameThread->BindAsynIoOperation(lpAsynIoOperation, m_spAsynIoOperation, BM_Oneway, 0);
    }
    virtual ~CTranfile()
    {
        asyn_message_events_impl::Stop(m_spAsynFrame);
        if( m_hFile >= 0 ) _close(m_hFile);
    }

public: // interface of asyn_message_events_impl
    STDMETHOD(OnMessage)( /*[in]*/uint32_t lMessageId, /*[in]*/uint64_t lParam1, /*[in]*/uint64_t lParam2, /*[in]*/IUnknown **objects )
    {
        if( lMessageId == AF_IOMSG_NOTIFY )
        {
            IAsynIoOperation *lpAsynIoOperation = (IAsynIoOperation *)objects[0];
            uint32_t lErrorCode, lTransferedBytes;
            lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);
            
            if( lParam2 == Io_recv )
            {
                if( lErrorCode )
                {
                    printf("recv error: %d\n", lErrorCode);
                    asynsdk::PostBindIoOperation(lpAsynIoOperation, lErrorCode);
                    return E_NOTIMPL;
                }

                if( lParam1 == 0x81 )
                {
                    lpAsynIoOperation->GetIoBuffer(0, 0, &m_frame);
                    std::string file((char*)m_frame, lTransferedBytes);
                    printf("recv: %s\n", file.c_str());
                    m_hFile = _open(file.c_str(), O_BINARY|O_RDWR|O_CREAT, 0666);
                    if( m_hFile < 0 ) {
                        printf("open %s: %s\n", file.c_str(), strerror(errno));
                        return E_NOTIMPL;
                    }

                    return m_spAsynPtlSocket->Read(lpAsynIoOperation); //接收数据
                }
                if( lParam1 == 0x08 )
                {
                    printf("recv shutdown\n");
                    asynsdk::PostBindIoOperation(lpAsynIoOperation, lErrorCode);
                    return E_NOTIMPL;
                }
                else
                {
                    printf("recv: %d\n", lTransferedBytes);
                    lpAsynIoOperation->GetIoBuffer(0, 0, &m_frame);
                    int ret = _write(m_hFile, m_frame, lTransferedBytes);
                    return m_spAsynPtlSocket->Read(lpAsynIoOperation); //接收数据
                }
            }
            else
            {
                if( lErrorCode )
                {
                    printf("send error: %d\n", lErrorCode);
                    asynsdk::PostBindIoOperation(lpAsynIoOperation, lErrorCode);
                    return E_NOTIMPL;
                }
                if( m_hFile < 0 )
                {
                    return E_NOTIMPL;
                }

                int ret = _read(m_hFile, m_frame, 4096);
                if(!ret )
                {
                    printf("send file completed\n");
                    _close(m_hFile); m_hFile = -1;
                    m_spAsynPtlSocket->Write(lpAsynIoOperation, 0x08); //发送断开
                    asynsdk::PostBindIoOperation(lpAsynIoOperation, NO_ERROR);
                    return S_OK;
                }

                if( ret < 0 )
                {
                    printf("read error: %d\n", errno);
                    asynsdk::PostBindIoOperation(lpAsynIoOperation, errno);
                    return E_NOTIMPL;
                }
                else
                {
                    printf("send: %d\n", ret);
                    lpAsynIoOperation->SetIoParams(0, ret, 0);
                    return m_spAsynPtlSocket->Write(lpAsynIoOperation, 0x82); //发送数据
                }
            }
        }
        return E_NOTIMPL;
    }

public:
    void Sendfile(const std::string &file)
    {
        m_hFile = _open(file.c_str(), O_BINARY|O_RDONLY);
        if( m_hFile < 0 ) {
            printf("open %s: %s\n", file.c_str(), strerror(errno));
            return;
        }

        m_spAsynIoOperation->NewIoBuffer(0, (BYTE*)file.c_str(), 0, file.size(), 4096, &m_frame);
        m_spAsynIoOperation->SetIoParams(0, file.size(), 0);
        m_spAsynPtlSocket->Write(m_spAsynIoOperation, 0x81); //发送文件名字
    }

    void Recvfile()
    {
        m_hFile = -1;
        m_spAsynPtlSocket->Read(m_spAsynIoOperation); //接收文件名字
    }

protected:
    CComPtr<IAsynRawSocket  > m_spAsynPtlSocket;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    CComPtr<IAsynIoOperation> m_spAsynIoOperation;
    int   m_hFile;
    BYTE *m_frame;
};

#endif//__TRANFILE_H__
