/*****************************************************************************
Copyright (c) 2012 - 2032, All rights reserved.

Author: Shengqian Yang, netsecsp@hotmail.com, China, last updated 05/01/2022
http://asynframe.sf.net

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
#pragma once

#define PER_DATA_SIZE	32768

class CFileEvent : public asynsdk::asyn_message_events_impl
{
public:
    CFileEvent(IAsynFrameThread *lpAsynFrameThread, IAsynFileSystem *lpAsynFileSystems)
    {
        m_spAsynFileSystems = lpAsynFileSystems;
        m_spAsynFrameThread = lpAsynFrameThread;
        CreateAsynFrame(m_spAsynFrameThread, 0, &m_spAsynFrame);
        m_hNotify = CreateEvent(NULL, TRUE, FALSE, NULL);
        m_spAsynFileSystems->CreateAsynFile(&m_spSrcAsynFile );
        m_spAsynFileSystems->CreateAsynFile(&m_spDstAsynFile );
    }

public:
    STDMETHOD(OnMessage)( /*[in]*/uint32_t lMessageId, /*[in]*/uint64_t lParam1, /*[in]*/uint64_t lParam2, /*[in]*/IUnknown **object )
    {
        if( lMessageId != AF_IOMSG_NOTIFY )
        {
            printf("lMsg: %d, param: %I64d/%I64d\n", lMessageId, lParam1, lParam2);
        }
        else
        {
            IAsynIoOperation *lpAsynIoOperation = object == 0 ? 0 : (IAsynIoOperation *)*object;
            uint32_t lErrorCode, lTransferedBytes;
            lpAsynIoOperation->GetCompletedResult(&lErrorCode, &lTransferedBytes, 0);

            if( lParam2 == Io_recv )
            {
                if( lErrorCode )
                {
                    if( lErrorCode == AE_RESET ) //读到文件结尾
                        printf("copy completed\n");
                    else
                        printf("read, error: %d\n", lErrorCode);
                    SetEvent(m_hNotify);
                    m_spSrcAsynIoOperation = 0;
                    return E_NOTIMPL;
                }
                else
                {
                    uint64_t lOffset;
                    m_spDstAsynIoOperation->GetPosition(&lOffset );
                    printf("write  to pos: %I64d, len: %d\n", lOffset, lTransferedBytes);
                    m_spDstAsynIoOperation->SetIoParams(0, lTransferedBytes, lTransferedBytes);
                    m_spDstAsynFile->Write(m_spDstAsynIoOperation, 0);
                    return S_OK;
                }
            }
            if( lParam2 == Io_send )
            {
                if( lErrorCode )
                {
                    printf("send, error: %d\n", lErrorCode);
                    SetEvent(m_hNotify);
                    return E_NOTIMPL;
                }
                else
                {
                    uint64_t lOffset;
                    m_spSrcAsynIoOperation->GetPosition(&lOffset );
                    printf("read from pos: %I64d\n", lOffset);
                    m_spSrcAsynIoOperation->SetIoParams(0, PER_DATA_SIZE, 0);
                    m_spSrcAsynFile->Read(m_spSrcAsynIoOperation);
                    return S_OK;
                }
            }
        }
        return E_FAIL;
    }

public:
    bool Copy(IBuffer *lpBuffer, uint32_t max_recvspeed = -1)
    {
        CComPtr<IObjectHolder> spObjectHolder; //设置全局读文件速度B/s
        m_spAsynFileSystems->QueryInterface(IID_IObjectHolder, (void **)&spObjectHolder);
        HRESULT r1 = spObjectHolder->Get(DT_GetRecvSpeedController, 0, IID_ISpeedController, (void **)&m_spSpeedController);
        m_spSpeedController->SetMaxSpeed(max_recvspeed);

        m_spAsynFileSystems->CreateAsynIoOperation(m_spAsynFrame, 0, 0, IID_IAsynFileIoOperation, (void **)&m_spSrcAsynIoOperation);
        m_spAsynFileSystems->CreateAsynIoOperation(m_spAsynFrame, 0, 0, IID_IAsynFileIoOperation, (void **)&m_spDstAsynIoOperation);

        m_spSrcAsynIoOperation->SetIoBuffer(0, lpBuffer);
        m_spDstAsynIoOperation->SetIoBuffer(0, lpBuffer);

        m_spDstAsynIoOperation->SetPosition(0);
        m_spSrcAsynIoOperation->SetPosition(0);
        m_spSrcAsynIoOperation->NewIoBuffer(0, 0, 0, 0, PER_DATA_SIZE, 0);
        m_spSrcAsynIoOperation->SetIoParams(0, PER_DATA_SIZE, 0);

        printf("read from pos: 0\n");
        m_spSrcAsynFile->Read(m_spSrcAsynIoOperation);
        return true;
    }

    void Shutdown()
    {
        Stop(m_spAsynFrame);
        m_spAsynFrame = NULL;
    }

public:
    CComPtr<IAsynFileSystem > m_spAsynFileSystems;
    CComPtr<IAsynFrameThread> m_spAsynFrameThread;
    CComPtr<IAsynFrame      > m_spAsynFrame;
    HANDLE m_hNotify;

    CComPtr<ISpeedController> m_spSpeedController;

    CComPtr<IAsynFile> m_spSrcAsynFile;
    CComPtr<IAsynFile> m_spDstAsynFile;
    CComPtr<IAsynFileIoOperation> m_spSrcAsynIoOperation;
    CComPtr<IAsynFileIoOperation> m_spDstAsynIoOperation;
};
