//
// Created by user on 14.11.20.
//

#ifndef LED_PANEL_LEDMATRIX_H
#define LED_PANEL_LEDMATRIX_H

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include <stdint.h>



#ifdef __cplusplus
extern "C" {
#endif


struct LEDDevice;
struct LEDProgram;


/**
 *  static constructor
 */
bool leddevice_ctor(struct LEDDevice * device, const char * ipaddr, uint16_t port, const char * username );

/**
 * @param device
 * static dtor
 */
void leddevice_dtor(struct LEDDevice * device);


struct LEDDevice * leddevice_new(const char * ipaddr, uint16_t port, const char * username);
void leddevice_free(struct LEDDevice * leddevice);




bool ledprogram_ctor(struct LEDProgram * self, struct LEDDevice * device, const char * name);
void ledprogram_dtor(struct LEDProgram * self);

struct LEDProgram * ledprogram_new(struct LEDDevice * device, const char * name);
void ledprogram_free(struct LEDProgram * self);
void ledprogram_send_to_player(struct LEDProgram * self);


void led_program_clear(struct LEDProgram * program);

void led_program_send(struct LEDProgram * program);

void led_program_add_text(struct LEDProgram * program, const char * test, int x, int y, int w, int h, int transparency);

void led_program_add_dynamics(struct LEDProgram * program, const char * text, int x, int y, int w, int h, int transparency);

void led_program_add_dynamics_picture(struct LEDProgram * program, const char * filePath, int x, int y, int w, int h, int transparency);



void test_dynamics(struct LEDDevice * device);


#ifdef __cplusplus
}
#endif

#endif //LED_PANEL_LEDMATRIX_H


