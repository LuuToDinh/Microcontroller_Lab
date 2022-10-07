/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE BEGIN 0 */
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

const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1 , 2 , 3 , 4};
int hour = 15 , minute = 4 , second = 50;

void update7SEG (int index) {
	switch (index) {
	 	 case 0:
	 		 // Display the first 7 SEG with led_buffer [0]
			 HAL_GPIO_WritePin(P2_GPIO_Port, P2_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P3_GPIO_Port, P3_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P4_GPIO_Port, P4_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P1_GPIO_Port, P1_Pin, GPIO_PIN_RESET);
			 if(led_buffer[0] <= 9 && led_buffer[0] >= 0)
			 display7SEG(led_buffer[0]);
	 		 break;
	 	 case 1:
	 		 // Display the second 7 SEG with led_buffer [1]
			 HAL_GPIO_WritePin(P1_GPIO_Port, P1_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P3_GPIO_Port, P3_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P4_GPIO_Port, P4_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P2_GPIO_Port, P2_Pin, GPIO_PIN_RESET);
			 if(led_buffer[1] <= 9 && led_buffer[1] >= 0)
			 display7SEG(led_buffer[1]);
	 		 break;
	 	 case 2:
	 		 // Display the third 7 SEG with led_buffer [2]
			 HAL_GPIO_WritePin(P2_GPIO_Port, P2_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P1_GPIO_Port, P1_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P4_GPIO_Port, P4_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P3_GPIO_Port, P3_Pin, GPIO_PIN_RESET);
			 if(led_buffer[2] <= 9 && led_buffer[2] >= 0)
			 display7SEG(led_buffer[2]);
	 		 break ;
	 	 case 3:
	 		 // Display the forth 7 SEG with led_buffer [3]
			 HAL_GPIO_WritePin(P2_GPIO_Port, P2_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P3_GPIO_Port, P3_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P1_GPIO_Port, P1_Pin, GPIO_PIN_SET);
			 HAL_GPIO_WritePin(P4_GPIO_Port, P4_Pin, GPIO_PIN_RESET);
			 if(led_buffer[3] <= 9 && led_buffer[3] >= 0)
				 display7SEG(led_buffer[3]);
	 		 break;
	 	 default :
			 display7SEG(8);
	 		 break;
	 }
 }

void updateClockBuffer(){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	if((minute % 10) <= 9 && (minute % 10) >= 0)
		led_buffer[3] = minute % 10;
}

const int MAX_LED_MATRIX = 8;
int indxLedMat = 0;
int idxLedOffset = 0;
uint8_t matrix_buffer[8] = {0xFF, 0x01, 0x00, 0xEC,
						    0xEC, 0x00, 0x01, 0xFF};
void updateLEDMatrix(int index, int offset){
	//set 8 high bits (PB15 -> PB8) of GPIOB's output data register to according buffer
	GPIOB->ODR = (GPIOB->ODR & 0x00FF) | (matrix_buffer[(index + offset) % MAX_LED_MATRIX] << 8);
	//scan each column one-by-one
	switch (index){
		case 0:
			HAL_GPIO_WritePin(GPIOA, BUF2_Pin|BUF3_Pin|BUF4_Pin
									|BUF5_Pin|BUF6_Pin|BUF7_Pin
									|BUF8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BUF1_GPIO_Port, BUF1_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, BUF1_Pin|BUF3_Pin|BUF4_Pin
									|BUF5_Pin|BUF6_Pin|BUF7_Pin
									|BUF8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BUF2_GPIO_Port, BUF2_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, BUF2_Pin|BUF1_Pin|BUF4_Pin
									|BUF5_Pin|BUF6_Pin|BUF7_Pin
									|BUF8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BUF3_GPIO_Port, BUF3_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, BUF2_Pin|BUF3_Pin|BUF1_Pin
									|BUF5_Pin|BUF6_Pin|BUF7_Pin
									|BUF8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BUF4_GPIO_Port, BUF4_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, BUF2_Pin|BUF3_Pin|BUF4_Pin
									|BUF1_Pin|BUF6_Pin|BUF7_Pin
									|BUF8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BUF5_GPIO_Port, BUF5_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, BUF2_Pin|BUF3_Pin|BUF4_Pin
									|BUF5_Pin|BUF1_Pin|BUF7_Pin
									|BUF8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BUF6_GPIO_Port, BUF6_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA, BUF2_Pin|BUF3_Pin|BUF4_Pin
									|BUF5_Pin|BUF6_Pin|BUF1_Pin
									|BUF8_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BUF7_GPIO_Port, BUF7_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOA, BUF2_Pin|BUF3_Pin|BUF4_Pin
									|BUF5_Pin|BUF6_Pin|BUF7_Pin
									|BUF1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BUF8_GPIO_Port, BUF8_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


  int ledIndex = 0;
  int scanC = 0;
  updateClockBuffer();
  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
  HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, RESET);
  setTimer1(25);
  setTimer2(100);
  setTimer3(50);
//	setTimer3(10);
	 while (1) {
		 if(timer1_flag == 1){
		 		  setTimer1(25);
		 		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		 		  update7SEG(ledIndex);
		 		  ledIndex++;
		 		  if(ledIndex > 3)
		 			  	  ledIndex = 0;
		 	  }
		 	  if(timer2_flag == 1){
		 		  setTimer2(100);
		 		  second ++;
		 		  if ( second >= 60) {
					  second = 0;
					  minute ++;
		 		  }
		 		  if( minute >= 60) {
					  minute = 0;
					  hour ++;
		 		  }
		 		  if( hour >=24) {
					  hour = 0;
		 		  }
		 		  updateClockBuffer();
		 		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		 	  }
		 	  if (timer3_flag == 1){
				  setTimer3(50);
				  //increase scan counter for each column scanned
				  scanC++;
				  indxLedMat %= MAX_LED_MATRIX;
				  updateLEDMatrix(indxLedMat++, idxLedOffset);
			  }

			  if (scanC >= 8){
				  //increase offset after scanning all 8 columns
				  idxLedOffset++;
				  idxLedOffset %= MAX_LED_MATRIX;
				  //reset scan counter
				  scanC = 0;
			  }
	 }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, EXB1_Pin|EXB2_Pin|DOT_Pin|LED_RED_Pin
                          |P1_Pin|P2_Pin|P3_Pin|P4_Pin
                          |EXB3_Pin|EXB4_Pin|EXB5_Pin|EXB6_Pin
                          |EXB7_Pin|EXB8_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, L1_Pin|L2_Pin|L3_Pin|BUF3_Pin
                          |BUF4_Pin|BUF5_Pin|BUF6_Pin|BUF7_Pin
                          |BUF8_Pin|L4_Pin|L5_Pin|L6_Pin
                          |L7_Pin|BUF1_Pin|BUF2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : EXB1_Pin EXB2_Pin DOT_Pin LED_RED_Pin
                           P1_Pin P2_Pin P3_Pin P4_Pin
                           EXB3_Pin EXB4_Pin EXB5_Pin EXB6_Pin
                           EXB7_Pin EXB8_Pin */
  GPIO_InitStruct.Pin = EXB1_Pin|EXB2_Pin|DOT_Pin|LED_RED_Pin
                          |P1_Pin|P2_Pin|P3_Pin|P4_Pin
                          |EXB3_Pin|EXB4_Pin|EXB5_Pin|EXB6_Pin
                          |EXB7_Pin|EXB8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : L1_Pin L2_Pin L3_Pin BUF3_Pin
                           BUF4_Pin BUF5_Pin BUF6_Pin BUF7_Pin
                           BUF8_Pin L4_Pin L5_Pin L6_Pin
                           L7_Pin BUF1_Pin BUF2_Pin */
  GPIO_InitStruct.Pin = L1_Pin|L2_Pin|L3_Pin|BUF3_Pin
                          |BUF4_Pin|BUF5_Pin|BUF6_Pin|BUF7_Pin
                          |BUF8_Pin|L4_Pin|L5_Pin|L6_Pin
                          |L7_Pin|BUF1_Pin|BUF2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef* htim )
{
	timerRun();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
