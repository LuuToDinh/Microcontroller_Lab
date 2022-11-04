/*
 * displayled7seg.h
 *
 *  Created on: Nov 1, 2022
 *      Author: Dinh Luu
 */

#ifndef SRC_DISPLAYLED7SEG_H_
#define SRC_DISPLAYLED7SEG_H_
#include "global.h"

void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer(int time, int state);
#endif /* SRC_DISPLAYLED7SEG_H_ */
