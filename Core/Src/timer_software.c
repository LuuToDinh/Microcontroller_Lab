/*
 * software_timer.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Dinh Luu
 */


#include "timer_software.h"
#include "displayled7seg.h"

int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;
int timerX_counter = 0;
int timerX_flag = 0;
int timerY_counter = 0;
int timerY_flag = 0;

void setTimerX(int duration){
	timerX_counter = duration;
	timerX_flag = 0;
}

void setTimerY(int duration){
	timerY_counter = duration;
	timerY_flag = 0;
}

void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2_counter = duration;
	timer2_flag = 0;
}
void timerRun(){
	if(timerX_counter > 0){
		timerX_counter--;
		if(timerX_counter == 0){
			timerX_flag = 1;
		}
		timeX = timerX_counter / 100 + 1;
	}
	if(timerY_counter > 0){
		timerY_counter--;
		if(timerY_counter == 0){
			timerY_flag = 1;
		}
		timeY = timerY_counter / 100 + 1;
	}
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0){
			timer1_flag = 1;
		}
	}
	if(timer2_counter > 0){
			timer2_counter--;
			if(timer2_counter == 0){
				timer2_flag = 1;
			}
		}
}
