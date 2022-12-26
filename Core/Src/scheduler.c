#include "scheduler.h"
#include "main.h"
sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

int printTime = 0;

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

void SCH_Init(void){
	current_index_task = 0;
	for(int i = 0; i < SCH_MAX_TASKS; i++)
	{
		SCH_tasks_G[i].State = EMPTY;
	}
}

void SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	for(int i = 0; i < SCH_MAX_TASKS; i++)
	{
		current_index_task = i;

		if(SCH_tasks_G[i].State != ACTIVE && current_index_task < SCH_MAX_TASKS){
			SCH_tasks_G[current_index_task].pTask = pFunction;
			SCH_tasks_G[current_index_task].Delay = DELAY;
			SCH_tasks_G[current_index_task].Period =  PERIOD;
			SCH_tasks_G[current_index_task].RunMe = 0;

			SCH_tasks_G[current_index_task].State = ACTIVE;

			// not important now
			SCH_tasks_G[current_index_task].TaskID = current_index_task;


			current_index_task++;

			break;
		}
	}
}


void SCH_Update(void){
	for(int i = 0; SCH_tasks_G[i].State != EMPTY && i < SCH_MAX_TASKS; i++)
	{
		if(SCH_tasks_G[i].State == ACTIVE){
			if (SCH_tasks_G[i].Delay > 0)
			{
//				display7SEG(SCH_tasks_G[4].Delay / 10);
				SCH_tasks_G[i].Delay--;
			}
			else
			{
				SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				SCH_tasks_G[i].RunMe++;
			}
			if (SCH_tasks_G[i].Delay > 0 && printTime == 50)
			{
				display7SEG(SCH_tasks_G[4].Delay / 100);
				printTime = 0;
			}
		}
	}
			printTime++;
}

void SCH_Dispatch_Tasks(void){
	for(int i = 0; SCH_tasks_G[i].State != EMPTY && i < SCH_MAX_TASKS; i++){
		if(SCH_tasks_G[i].State == ACTIVE && SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if( SCH_tasks_G [i] . Period == 0 )
			 {
				SCH_Delete_Task(i) ;
			 }
		}
	}
}

void SCH_Delete_Task(uint32_t taskID) {
	if(SCH_tasks_G[taskID].State == ACTIVE && taskID < SCH_MAX_TASKS){
		SCH_tasks_G[taskID].pTask = 0x0000;
		SCH_tasks_G[taskID].Delay = 0;
		SCH_tasks_G[taskID].Period =  0;
		SCH_tasks_G[taskID].RunMe = 0;

		SCH_tasks_G[taskID].State = DELETED;
	}
}
