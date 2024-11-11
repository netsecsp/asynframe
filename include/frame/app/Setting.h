// Setting.h: Definition of the CSetting class
//
/////////////////////////////////////////////////////////////////////////////////
#if !defined(AFX_SETTING_H__C98615AD_6DF5_4F69_92AE_BE46B4D3DDFE__INCLUDED_)
#define AFX_SETTING_H__C98615AD_6DF5_4F69_92AE_BE46B4D3DDFE__INCLUDED_
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

#include <string>
NAMESPACE_BEGIN(asynsdk)

class CSetting
{
public:
    CSetting(IKeyvalSetter* keyval = NULL)
      : m_key2vals(keyval)
    {
    }

public:
    bool from(IUnknown* keyval)
    {
         return m_key2vals.From(keyval) != 0;
    }

public:
    std::string getString(const std::string &key, const std::string &default_value = "");
    void        setString(const std::string &key, const std::string &value);

    int64_t     getNumber(const std::string &key, int64_t default_value= 0);
    void        setNumber(const std::string &key, int64_t value );

    bool hasExist(const std::string &key);

    void save()
    {
         m_key2vals->Travel(0);
    }

private:
    CObjPtr<IKeyvalSetter> m_key2vals;
};

NAMESPACE_END(asynsdk)

#endif // !defined(AFX_SETTING_H__C98615AD_6DF5_4F69_92AE_BE46B4D3DDFE__INCLUDED_)