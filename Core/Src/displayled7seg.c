/*
 * displayled7seg.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Dinh Luu
 */
#include "displayled7seg.h"

void display7SEG(int num){
  	  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_SET );
  	  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_SET );
  	  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_SET );
  	  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_SET );
  	  HAL_GPIO_WritePin( L5_GPIO_Port , L5_Pin ,GPIO_PIN_SET );
  	  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_SET );
  	  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_SET );
  	  if(num<=0){
  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L5_GPIO_Port , L5_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==1){
  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==2){
  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L5_GPIO_Port , L5_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==3){
  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==4){
  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==5){
  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==6){
  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L5_GPIO_Port , L5_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==7){
  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==8){
  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L5_GPIO_Port , L5_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_RESET );
  	  }
  	  else if(num==9){
  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_RESET );
  		  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_RESET );
  	  }
    }

void update7SEG (int index) {
	switch (index) {
	 	 case 0:
	 		 // Display the first 7 SEG with led_buffer [0]
			 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			 if(led_buffer[0] <= 9 && led_buffer[0] >= 0)
			 display7SEG(led_buffer[0]);
	 		 break;
	 	 case 1:
	 		 // Display the second 7 SEG with led_buffer [1]
			 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			 if(led_buffer[1] <= 9 && led_buffer[1] >= 0)
			 display7SEG(led_buffer[1]);
	 		 break;
	 	 case 2:
	 		 // Display the third 7 SEG with led_buffer [2]
			 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			 if(led_buffer[2] <= 9 && led_buffer[2] >= 0)
			 display7SEG(led_buffer[2]);
	 		 break ;
	 	 case 3:
	 		 // Display the forth 7 SEG with led_buffer [3]
			 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			 if(led_buffer[3] <= 9 && led_buffer[3] >= 0)
				 display7SEG(led_buffer[3]);
	 		 break;
	 	 default :
			 display7SEG(8);
	 		 break;
	 }
 }

void updateClockBuffer(int time, int state){
	led_buffer[0] = time / 10;
	led_buffer[1] = time % 10;
	led_buffer[2] = state / 10;
	if((state % 10) <= 9 && (state % 10) >= 0)
		led_buffer[3] = state % 10;
}
