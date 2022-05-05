//////////////////////////////////////////////////////////////////////
#if !defined(AFX_SETTING_H__C98615AD_6DF5_4F69_92AE_BE46B4D3DDFF__INCLUDED_)
#define AFX_SETTING_H__C98615AD_6DF5_4F69_92AE_BE46B4D3DDFF__INCLUDED_
/*****************************************************************************
Copyright (c) 2012 - 2016, All rights reserved.

Author: Shengqian Yang, China, last updated 07/01/2016
Email:  netsecsp@hotmail.com
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

#pragma warning(disable:4786)
#include <string>

#ifdef HASH_MAP
#include <hash_map>
typedef std::hash_map<std::string, std::string> setting_map;
#else
#include <map>
typedef std::map<std::string, std::string> setting_map;
#endif

class setting
{
public:
    setting(const std::string &filename);

    std::string get_string(const std::string &section, const std::string &entry, const std::string &default_str = "" );
    void set_string(const std::string &section, const std::string &entry, const std::string &value);

    long get_long(const std::string &section, const std::string &entry, long default_long = 0);
    void set_long(const std::string &section, const std::string &entry, long value );

    bool get_bool(const std::string &section, const std::string &entry, bool default_bool = 0);
    void set_bool(const std::string &section, const std::string &entry, bool value );

private:
    setting_map _values;
};

#endif // !defined(AFX_SETTING_H__C98615AD_6DF5_4F69_92AE_BE46B4D3DDFF__INCLUDED_)