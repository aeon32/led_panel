// -*- coding:utf8 -*-
// -*- кодировка:utf8 -*-


#include <iostream>

#include <libledmatrix/ledmatrix.h>
#include <yqnet/yqlib.h>

#include <unistd.h>

#include "config.h"

#include <string>

const char * IP = "192.168.0.199";
const uint16_t PORT = 80;
const char * LOGIN = "guest";



void test1()
{


    struct LEDDevice * device = leddevice_new(IP, PORT, LOGIN);
    if (device)
    {

        struct LEDProgram * program = ledprogram_new(device, "program 1");

        led_program_add_text(program, "mytest", 0, 0, 30, 20, 100);

        ledprogram_send_to_player(program);


        sleep(1);

        ledprogram_free(program);
        leddevice_free(device);
    };




    //int err = check_time(IP, PORT, LOGIN, LOGIN);
    //std::cout <<"error "<<err<<std::endl;

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


void test2()
{
    std::string file = std::string(PROJECT_DATADIR) + "/" + "1.bmp";

    struct LEDDevice * device = leddevice_new(IP, PORT, LOGIN);
    if (device)
    {
        struct LEDProgram * program = ledprogram_new(device, "program 5");


        led_program_clear(program);

        //led_program_add_dynamics(program, "Hi Вася asdgg!", 0, 0, 64, 32, 100);
        led_program_add_dynamics_picture(program, file.c_str(), 0, 0, 128, 96, 100);



        led_program_send(program);




        ledprogram_free(program);
        leddevice_free(device);



    };


}

int main(int argc, char **argv)
{
    test2();
    return 0;
}
