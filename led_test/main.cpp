// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-


#include <iostream>

#include <yqnet/yqlib.h>

char * IP = "127.0.0.1";
const int PORT = 80;
wchar_t * LOGIN = L"guest";



void test1()
{

    int err = check_time(IP, PORT, LOGIN, LOGIN);
    std::cout <<"error "<<err<<std::endl;

    /*
    char* ip = "192.168.89.156";
    int port = 80;
    LPCWSTR str = L"guest";

    err = check_time(ip, port, str, str);
    cout<<"check_time:"<<err<<endl;
    Program_cleardynamic(ip, port, str);
    Program_bmp(ip, port, str);

    Program_dynamic_small(ip, port, str);
    Sleep(5000);
    Program_dynamic_uint_small(ip, port, str);

    err=release_sdk();
*/



}


int main(int argc, char **argv)
{
    test1();
    return 0;
}
