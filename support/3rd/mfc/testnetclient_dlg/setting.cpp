// setting.cpp: implementation of the setting class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "setting.h"
#include <iostream>
#include <shlwapi.h>

const DWORD buf_len = 2048;

static std::string GetCurrentDirectory()
{
    char path[MAX_PATH];
    path[::GetCurrentDirectory(MAX_PATH, path) ] = 0;
    return path;
}

//////////////////////////////////////////////////////////////////////
setting::setting(const std::string &filename)
{
    std::string filepath;
    if(::PathIsRelative(filename.c_str()) )
        filepath = GetCurrentDirectory() + "\\" + filename;
    else
        filepath = filename;

    char section_buf[buf_len];
    char item_buf[buf_len];
    char *section_ptr = section_buf;
    char *item_ptr;
    std::string key;
    std::string item;
    std::string value;
    unsigned pos;
    DWORD len;
    len = ::GetPrivateProfileSectionNames( section_buf, buf_len, filepath.c_str() );
    while ( *section_ptr != '\0' )
    {
        len = ::GetPrivateProfileSection( section_ptr, item_buf, buf_len, filepath.c_str() );
        item_ptr = item_buf;
        while ( *item_ptr != '\0' )
        {
            key = section_ptr;
            item = item_ptr;
            pos = item.find('=');
            key.append(item, 0, pos);
            value.assign(item, pos + 1, item.size() - pos);
            _values.insert( std::pair<std::string, std::string>(key, value) );
            item_ptr += strlen(item_ptr) + 1;
        }
        section_ptr += strlen(section_ptr) + 1;
    }
}

//////////////////////////////////////////////////////////////////////
std::string setting::get_string(const std::string &section, const std::string &entry, const std::string &default_str )
{
    setting_map::iterator it = _values.find(section + entry);
    if( it == _values.end() )
    {
        return default_str;
    }
    else
    {
        return (*it).second;
    }
}

void setting::set_string(const std::string &section, const std::string &entry, const std::string &value)
{
    _values[section + entry] = value;
}

long setting::get_long(const std::string &section, const std::string &entry, long default_int )
{
    setting_map::iterator it = _values.find(section + entry);
    if( it == _values.end() )
    {
        return default_int;
    }
    else
    {
        return atol( (*it).second.c_str() );
    }
}

void setting::set_long(const std::string &section, const std::string &entry, long value )
{
    char out[16];
    _ultoa(value, out, 10);

    _values[section + entry] = out;
}

bool setting::get_bool(const std::string &section, const std::string &entry, bool default_bool )
{
    setting_map::iterator it = _values.find(section + entry);
    if( it == _values.end() )
    {
        return default_bool;
    }
    else
    {
        return atol( (*it).second.c_str() ) != 0;
    }
}

void setting::set_bool(const std::string &section, const std::string &entry, bool value)
{
    char out[16];
    _ultoa(value, out, 10);

    _values[section + entry] = out;
}