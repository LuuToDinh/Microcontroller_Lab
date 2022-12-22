#ifndef INC_UART_FSM_H_
#define INC_UART_FSM_H_

#include "main.h"
#include "Software_timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT 0
#define READING 1
#define STOP 2
#define RST 6
#define OK 7

#define TIME_WAITING 300

#define MAX_BUFFER_SIZE 30

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

void command_parser_fsm();
void uart_communiation_fsm();

#endif /* INC_UART_FSM_H_ */
