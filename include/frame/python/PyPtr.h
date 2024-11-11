#if !defined(AFX_PYPTR_H__851C326A_2624_4852_9D04_1C02CA7859EB__INCLUDED_)
#define AFX_PYPTR_H__851C326A_2624_4852_9D04_1C02CA7859EB__INCLUDED_
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
class CPyPtr
{
public:
    CPyPtr(PyObject *v = NULL, bool addref = true)
    {
        p = v;
        if( p && addref )
        {
            Py_INCREF(p);
        }
    }
    CPyPtr(const CPyPtr &v)
    {
        p = v.p;
        Py_XINCREF(p);
    }
    ~CPyPtr() throw()
    {
        Py_XDECREF(p);
    }

public:
    PyObject *Attach(PyObject *v) throw()
    {
        Py_XDECREF(p);
        p = v;
        return p;
    }
    // Detach the interface (does not Release)
    PyObject *Detach()
    {
        PyObject *t = p;
        p = NULL;
        return t;
    }

    PyObject *AddRef()
    {
        if( p )
        {
            Py_INCREF(p);
        }
        return p;
    }
    void Releae()
    {
        if( p )
        {
            Py_DECREF(p);
            p = NULL;
        }
    }

    void Swap(CPyPtr &v)
    {
        PyObject* t = p; p = v.p; v.p = t;
    }

public:
    operator PyObject *() const throw()
    {
        return p;
    }
    bool operator==(PyObject *v) const throw()
    {
        return p == v;
    }
    PyObject *operator->() const throw()
    {
        return p;
    }

    PyObject *operator=(PyObject *v) throw()
    {
        if( p )
        {
            Py_DECREF(p);
        }

        p = v;   Py_XINCREF(p);
        return p;
    }
    PyObject *operator=(const CPyPtr &v) throw()
    {
        if( p )
        {
            Py_DECREF(p);
        }

        p = v.p; Py_XINCREF(p);
        return p;
    }

public:
    PyObject *p;
};

#endif //AFX_PYPTR_H__851C326A_2624_4852_9D04_1C02CA7859EB__INCLUDED_