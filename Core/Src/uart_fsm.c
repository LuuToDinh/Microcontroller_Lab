#include "uart_fsm.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

int status = INIT;
int command_status = INIT;
int ADC_value = 0;
char str[50];

uint8_t temp;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t command_data[3];
uint8_t index_command = 0;

void command_parser_fsm() {
	switch (status) {
	case INIT:
		if (temp == '!')
			status = READING;
		break;
	case READING:
		if (temp != '!' && temp != '#') {
			command_data[index_command] = temp;
			index_command++;
		}
		if (temp == '#') {
			status = STOP;
			index_command = 0;
		}
		break;
	case STOP:
//		str = RST
		if (command_data[0] == 'R' && command_data[1] == 'S' && command_data[2] == 'T') {
			command_status = RST;
			setTimer1(1);
		}
//		str = OK
		else if (command_data[0] == 'O' && command_data[1] == 'K') {
			command_status = OK;
		}
		status = INIT;
		break;
	default:
		break;
	}
}

void uart_communiation_fsm() {
	switch (command_status) {
	case INIT:
		break;
	case RST:
		if (timer1_flag == 1) {
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!ADC=%d#\r\n", ADC_value), 1000);
			setTimer1(TIME_WAITING);
		}
		break;
	case OK:
		ADC_value = 0;
		command_status = INIT;
		break;
	default:
		break;
	}
}
