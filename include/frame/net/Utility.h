///////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_UTILITY_NET_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_)
#define AFX_UTILITY_NET_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_
/*****************************************************************************
Copyright (c) netsecsp 2012-2032, All rights reserved.

Developer: Shengqian Yang, from China, E-mail: netsecsp@hotmail.com, last updated 01/15/2024
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
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

NAMESPACE_BEGIN(asynsdk)

///////////////////////////////////////////////////////////////////////////////
class CPortAllocator_simple : public CAsynMessageEvents_base
{// for IAsynUdpSocket/IAsynTcpSocketListener
public:
    CPortAllocator_simple( /*[in ]*/uint32_t dwRef = 0 )
      : CAsynMessageEvents_base(dwRef)
    {
    }
    virtual ~CPortAllocator_simple() { }

protected: //for subclass
    STDMETHOD(OnMessage)( /*[in ]*/uint32_t message, /*[in ]*/uint64_t lparam1, /*[in ]*/uint64_t lparam2, /*[in, out]*/IUnknown** objects )
    {
        if( message == AF_QUERY_RESULT )
        {// allocate: AF_QUERY_RESULT x port null
            *((PORT*)lparam2) = m_next ++;
            if( m_next > m_nMaxPort ) m_next = m_nMinPort;
        }
        else
        {// released: AF_EVENT_NOTIFY 0 port null 
        }
        return S_OK;
    }

public:
    CPortAllocator_simple *Set(PORT basePort, uint32_t size)
    {// size > 0
        m_nMinPort = basePort;
        m_nMaxPort = basePort + size - 1;
        m_next     = basePort;
        return this;
    }

protected:
    PORT m_nMinPort, m_nMaxPort; //port range
    PORT m_next;
};

///////////////////////////////////////////////////////////////////////////////
//检测pSocket是否ISsl类型
bool IsSslSocket( /*[in ]*/IUnknown *pSocket );

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_UTILITY_NET_H__8A503072_4124_4233_9BEF_3671D8669695__INCLUDED_)