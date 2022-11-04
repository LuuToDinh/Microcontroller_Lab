/*
 * fsm_automatic.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Dinh Luu
 */

#include "fsm_automatic.h"
#include "displayled7seg.h"

void redMode() {
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
	statusX= MAN_RED;
	setTimerX(MAN_RED_TIME);
	setTimer2(LED_TIME);
	runY = 0;
}

void fsm_automatic_run_x(){
	switch(statusX){
	case AUTO_RED:
//		led_buffer[1] = 1;
		updateClockBuffer(timeX, timeY);
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
		if(timerX_flag == 1){
			statusX = AUTO_GREEN;
			setTimerX(GREEN_TIME);
		}
		if(button1_flag == 1){
			redMode();
			button1_flag = 0;
		}
		break;
	case AUTO_GREEN:
		updateClockBuffer(timeX, timeY);
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
		if(timerX_flag == 1){
			statusX = AUTO_YELLOW;
			setTimerX(YELLOW_TIME);

		}
		if(button1_flag == 1){
			redMode();
			button1_flag = 0;
		}
		break;
	case AUTO_YELLOW:
		updateClockBuffer(timeX, timeY);
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
		if(timerX_flag == 1){
			statusX = AUTO_RED;
			setTimerX(RED_TIME);
		}
		if(button1_flag == 1){
			redMode();
			button1_flag = 0;
		}
		break;
	default:
		break;

	}
}

void fsm_automatic_run_y(){
	if(runY){
		switch(statusY){
		case AUTO_RED:
				HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
			if(timerY_flag == 1){
				statusY = AUTO_GREEN;
				setTimerY(GREEN_TIME);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_SET);
			if(timerY_flag == 1){
				statusY = AUTO_YELLOW;
				setTimerY(YELLOW_TIME);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
			if(timerY_flag == 1){
				statusY = AUTO_RED;
				setTimerY(RED_TIME);
			}
			break;
		default:
			break;

		}
	}
}
