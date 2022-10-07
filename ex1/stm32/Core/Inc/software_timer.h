/*
 * software_timer.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Dinh Luu
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_counter;
extern int timer1_flag;

void setTimer(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
