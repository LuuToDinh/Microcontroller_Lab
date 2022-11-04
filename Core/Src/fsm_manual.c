/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: Dinh Luu
 */
#include "global.h"
#include "fsm_manual.h"
#include "displayled7seg.h"

void initState(){
	statusX = AUTO_RED;
	statusY = AUTO_GREEN;
	setTimerX(RED_TIME);
	setTimerY(GREEN_TIME);
	runY = 1;
}


void fsm_manual_run(){
	switch(statusX){
	case MAN_RED:
		if(button2_flag == 1){
			MAN_RED_TIME_SUM += 100;
			button2_flag = 0;
		}
		if(button3_flag == 1){
			MAN_RED_TIME = MAN_RED_TIME_SUM;
			button3_flag = 0;
		}
		updateClockBuffer(MAN_RED_TIME_SUM / 100  , MAN_RED);
		if(timer2_flag == 1){
			setTimer2(LED_TIME);
			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
			HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
		}
		if(timerX_flag == 1){
			initState();
		}
		if (button1_flag == 1){
//			Yellow mode
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
			statusX = MAN_YELLOW;
			setTimerX(MAN_YELLOW_TIME);
			setTimer2(LED_TIME);
			button1_flag = 0;
		}
		break;
	case MAN_GREEN:
		if(button2_flag == 1){
			MAN_GREEN_TIME_SUM += 100;
			button2_flag = 0;
		}
		if(button3_flag == 1){
			MAN_GREEN_TIME = MAN_GREEN_TIME_SUM;
			button3_flag = 0;
		}
		updateClockBuffer(MAN_GREEN_TIME_SUM/100  , MAN_GREEN);
//		led_buffer[1] = 4;
		if(timer2_flag == 1){
			setTimer2(LED_TIME);
			HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
		}
		if(timerX_flag == 1){
			initState();
		}
		if (button1_flag == 1){
//			Auto mode
			initState();
			button1_flag = 0;
		}
		break;
	case MAN_YELLOW:
		if(button2_flag == 1){
			MAN_YELLOW_TIME_SUM += 100;
			button2_flag = 0;
		}
		if(button3_flag == 1){
			MAN_YELLOW_TIME = MAN_YELLOW_TIME_SUM;
			button3_flag = 0;
		}
		updateClockBuffer(MAN_YELLOW_TIME_SUM/100  , MAN_YELLOW);
//		led_buffer[1] = 3;
		if(timer2_flag == 1){
			setTimer2(LED_TIME);
			HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
			HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
		}
		if(timerX_flag == 1){
			initState();
		}
		if (button1_flag == 1){
//			Green mode
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_SET);
			setTimer2(LED_TIME);
//			statusX = INIT;
//			setTimerX(500);
			statusX = MAN_GREEN;
			setTimerX(MAN_GREEN_TIME);
			button1_flag = 0;
		}
		break;
	}
}
