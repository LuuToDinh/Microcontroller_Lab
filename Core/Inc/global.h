/*
 * global.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Dinh Luu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer_software.h"
#include "button.h"
#include "displayled7seg.h"

//extern int statusMain;
extern int statusX;
extern int statusY;
extern int timeX;
extern int timeY;
extern int runY;
extern int ledIndex;
extern int led_buffer[4];
extern int MAN_RED_TIME;
extern int MAN_GREEN_TIME;
extern int MAN_YELLOW_TIME;
extern int MAN_RED_TIME_SUM;
extern int MAN_GREEN_TIME_SUM;
extern int MAN_YELLOW_TIME_SUM;


#define LED_TIME 50

#define AUTO_RED 1
#define  AUTO_GREEN 5
#define  AUTO_YELLOW 6

#define MAN_RED 2
#define MAN_YELLOW 3
#define MAN_GREEN 4

#define RED_TIME 700
#define GREEN_TIME 400
#define YELLOW_TIME 300

#define RED_EDIT 600
#define GREEN_EDIT 500
#define YELLOW_EDIT 400

#define LED2HZ 25;


#endif /* INC_GLOBAL_H_ */
