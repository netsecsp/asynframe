#if !defined(AFX_OBJPTR_H__851C326A_2624_4852_9D04_1C02CA7859EB__INCLUDED_)
#define AFX_OBJPTR_H__851C326A_2624_4852_9D04_1C02CA7859EB__INCLUDED_
/*****************************************************************************
Copyright (c) netsecsp 2012-2032, All rights reserved.

Developer: Shengqian Yang, from China, E-mail: netsecsp@hotmail.com, last updated 07/01/2016
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

template <class T>
class CObjPtr
{
public:
    CObjPtr(T *v = NULL, bool doAddref = true) throw()
    {
        p = v;
        if( p )
        {
            if( doAddref ) p->AddRef();
        }
    }
    CObjPtr(const CObjPtr<T> &v) throw()
    {
        p = v.p;
        if( p )
        {
            p->AddRef();
        }
    }
    ~CObjPtr() throw()
    {
        if( p )
        {
            p->Release();
        }
    }

public:
    void Attach(T *v) throw()
    {
        if( p )
        {
            p->Release();
        }
        p = v;
    }
    // Detach the interface (does not Release)
    T  *Detach() throw()
    {
        T *t = p;
        p = NULL;
        return t;
    }

    template<class C>
    C  *Docast()
    {
        return static_cast<C *>(p);
    }

    void Swap(CObjPtr<T> &v)
    {
        T* t = p; p = v.p; v.p = t;
    }

    T  *From(IUnknown *v)
    {
        if( p )
        {
            p->Release();
        }
        if(!v ||
            v->QueryInterface(__uuidof(T), (void**)&p) != S_OK )
        {
            p = 0;
        }
        return p;
    }

public:
    operator T *() const throw()
    {
        return p;
    }

    bool operator==(T *v) const throw()
    {
        return p == v;
    }
    T  *operator->() const throw()
    {
        return p;
    }

    T  *operator=(T *v) throw()
    {
        if( p )
        {
            p->Release();
        }

        p = v;   if( p ) p->AddRef();
        return p;
    }
    T  *operator=(const CObjPtr<T> &v) throw()
    {
        if( p )
        {
            p->Release();
        }

        p = v.p; if( p ) p->AddRef();
        return p;
    }

public:
    T *p;
};

#endif //__OBJPTR_H__