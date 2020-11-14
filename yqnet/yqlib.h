// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-
/**
 *
 *
**/
#ifndef YQLIB_H
#define YQLIB_H



#include <string>
#include <strstream>

#ifdef _UNICODE  
//typedef boost::property_tree::wptree tptree;
//typedef std::wstring tstring;
//typedef std::wstringstream tstringstream;
#define _TEXT_CHAR	wchar_t
#define _TEXT_T(x)	L ## x
#define tcout	wcout
#else  
typedef boost::property_tree::ptree tptree;
typedef std::string tstring;
typedef std::stringstream tstringstream;
#define _TEXT_CHAR	char
#define _TEXT_T(x)	x	
#define tcout	cout
#endif   

#include "YQNetCom.h"

#endif

