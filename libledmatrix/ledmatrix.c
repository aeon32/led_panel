//
// Created by user on 14.11.20.
//

#include "ledmatrix.h"



#include <yqnet/yqlib.h>
#include "cutf.h"



//unsigned long playlist = create_playlist(1024, 600, 8792);
const int WIDTH = 1024;
const int HEIGHT = 600;
const int TYPE = 8792;



struct LEDDevice
{
    char * ipaddr;
    char * username;
    uint16_t port;

    unsigned long playlist;
    unsigned long dynamicId;

};

bool leddevice_ctor(struct LEDDevice * device, const char * ipaddr, uint16_t port, const char * username )
{
    memset(device, 0, sizeof(struct LEDDevice) );
    device->ipaddr = strdup(ipaddr);

    device->username = strdup(username);
    device->port = port;



    bool ok = check_time(device->ipaddr , port, device->username, device->username) == 0;
    if (ok)
    {
        device->playlist = create_playlist(WIDTH, HEIGHT, TYPE);
        ok = device->playlist != 0;

    }
    return ok;

};


void leddevice_dtor(struct LEDDevice * device )
{
    if (device->ipaddr)
        free(device->ipaddr);
    if (device->username)
        free(device->username);
    if (device->playlist)
        delete_playlist(device->playlist);


};


struct LEDDevice * leddevice_new(const char * ipaddr, uint16_t port, const char * username)
{
  struct LEDDevice * device = (struct LEDDevice *) malloc(sizeof(struct LEDDevice));
  if (device )
  {
     bool ok = leddevice_ctor(device, ipaddr, port, username);
     if (!ok)
     {
         leddevice_free(device);
         device = NULL;

     }

  };
  return device;

};

void leddevice_free(struct LEDDevice * leddevice)
{
    if (leddevice)
    {
       leddevice_dtor(leddevice);
       free(leddevice);
    };

};


struct LEDProgram
{
    struct LEDDevice * device;
    unsigned  long program;

};


bool ledprogram_ctor(struct LEDProgram * self, struct LEDDevice * device, const char * name)
{

    memset(self, 0, sizeof(struct LEDProgram) );
    self->device = device;
    self->program = create_program((char *) name);

    char * m_aging_start_time = "1970-11-01";
    char * m_aging_stop_time = "2099-12-01";
    char * m_period_ontime = "00:00:00";
    char * m_period_offtime = "23:59:59";

    int err = add_program_in_playlist(self->device->playlist, self->program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);


    return true;

};

void ledprogram_dtor(struct LEDProgram * self)
{


};


struct LEDProgram * ledprogram_new(struct LEDDevice * device, const char * name)
{
    struct LEDProgram * program = ( struct LEDProgram *) malloc(sizeof(struct LEDProgram ));
    if (device )
    {
        bool ok = ledprogram_ctor(program, device, name);
        if (!ok)
        {
            ledprogram_free(program);
            program = NULL;

        }

    };
    return program;


};

void ledprogram_free(struct LEDProgram * self)
{
    if (self)
    {
        ledprogram_dtor(self);
        free(self);
    }

};


void ledprogram_send_to_player(struct LEDProgram * self)
{
    long long  free_size=0, total_size=0;
    int send_style = 0;

    int err;
    char * m_aging_start_time = "2020-11-01";
    char * m_aging_stop_time = "2020-12-01";
    char * m_period_ontime = "00:00:00";
    char * m_period_offtime = "23:59:59";
    err = add_program_in_playlist(self->device->playlist, self->program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);


    err = send_program(self->device->ipaddr,
                       self->device->port,
                       self->device->username,
                       self->device->username,
                       "/tmp/",
                       self->device->playlist,
                       send_style,
                       &free_size, &total_size
    );



    cancel_send_program(self->device->playlist);

};

void led_program_add_text(struct LEDProgram * program, const char * text, int x, int y, int w, int h, int transparency)
{
    unsigned long text_area = create_text();

    int err = add_text_unit_text(text_area, 0, 10, "SimSun", 10, "bold", "normal", "0xffff0000", "0xff000000",  (char *) text);
    err = add_text(program->program, text_area, x, y, w, h, transparency, 0, 0 );

    //LEDNETSDK_API int _CALL_STD add_text_unit_text(unsigned long text_area, int stay_time, int display_speed, _TEXT_CHAR* font_name, int font_size, _TEXT_CHAR* font_attributes, _TEXT_CHAR* font_alignment, _TEXT_CHAR* font_color, _TEXT_CHAR* bg_color, _TEXT_CHAR* content);
    //add_text()
    //add_text(unsigned long program, unsigned long text_area, int x, int y, int w, int h, int transparency, int display_effects, int unit_type);


};



void led_program_add_dynamics(struct LEDProgram * program, const char * text, int x, int y, int w, int h, int transparency)
{
    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    char * bg_color = "0xff000000";
    char * color = "0xffff0000";
    char * font_attributes = "normal";
    char * font = "Arial";
    char * align_h = "0";
    char *  align_v = "0";

    char * tmpFileName = strdup("/tmp/ledpanel-XXXXXX.txt");

    int fd = mkstemps(tmpFileName,4);
    write(fd,text, strlen(text));



    unsigned long dynamic_area = create_dynamic();

    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, tmpFileName, gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0);
    err = add_dynamic(program->program, dynamic_area, program->device->dynamicId++, x, y, w, h, -1, 0, "0", 100);

    delete_dynamic(dynamic_area);


    err = update_dynamic(program->device->ipaddr, program->device->port, program->device->username, program->device->username, program->device->playlist, 0, 1, 0);
    free(tmpFileName);
    close(fd);

    unlink(tmpFileName);


    //cancel_send_program(program->device->playlist);
};


void led_program_add_dynamics_picture(struct LEDProgram * program, const char * filePath, int x, int y, int w, int h, int transparency)
{
    int dynamic_type = 0;  //type is picture
    int display_effects = 2;
    int display_speed = 16;
    int stay_time = 1;
    int gif_flag = 0;
    char * bg_color = "0xff000000";
    char * color = "0xffff0000";
    char * font_attributes = "";
    char * font = "Arial";
    char * align_h = "0";
    char *  align_v = "0";



    unsigned long dynamic_area = create_dynamic();

    int err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, filePath, gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0);
    err = add_dynamic(program->program, dynamic_area, program->device->dynamicId++, x, y, w, h, -1, 0, "0", 100);

    delete_dynamic(dynamic_area);


    err = update_dynamic(program->device->ipaddr, program->device->port, program->device->username, program->device->username, program->device->playlist, 0, 1, 0);


};

void led_program_clear(struct LEDProgram * program)
{
    clear_dynamic(program->device->ipaddr, program->device->port, program->device->username, program->device->username);

};
void test_dynamics(struct LEDDevice * device)
{
    unsigned long program = create_program("program_3");

    int dynamic_type = 1;
    int display_effects = 52;
    int display_speed = 10;
    int stay_time = 0;
    int gif_flag = 0;
    char * bg_color = "0xff000000";
    char * color = "0xffff0000";
    char * font_attributes = "normal";
    char * font = "Arial";
    char * align_h = "0";
    char *  align_v = "0";

    int err;

    unsigned long dynamic_area = create_dynamic();

    char * m_aging_start_time = "2020-11-01";
    char * m_aging_stop_time = "2020-12-01";
    char * m_period_ontime = "00:00:00";
    char * m_period_offtime = "23:59:59";

    err = add_program_in_playlist(device->playlist, program, 0, 10, m_aging_start_time, m_aging_stop_time, m_period_ontime, m_period_offtime, 127);



    err = add_dynamic_unit(dynamic_area, dynamic_type, display_effects, display_speed, stay_time, "/tmp/1.txt", gif_flag, bg_color, 12, font, color, font_attributes, align_h, align_v, 0, 0, 0);
    err = add_dynamic(program, dynamic_area, 0, 0, 0, 64, 32, -1, 0, "", 100);



    delete_dynamic(dynamic_area);





    err = update_dynamic(device->ipaddr, device->port, device->username, device->username, device->playlist, 0, 1, 0);

    cancel_send_program(device->playlist);
    delete_playlist(device->playlist);


};

void led_program_send(struct LEDProgram * program)
{
    cancel_send_program(program->device->playlist);

};