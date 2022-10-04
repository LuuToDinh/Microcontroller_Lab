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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void setNumberOnClock(int count){
	      if(count==0){
	  		  HAL_GPIO_WritePin( L0_GPIO_Port , L0_Pin ,GPIO_PIN_SET );
	  	  }
	      else if(count==1){
	  		  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==2){
	  		  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==3){
	  		  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==4){
	  		  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==5){
	  		  HAL_GPIO_WritePin( L5_GPIO_Port , L5_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==6){
	  		  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==7){
	  		  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==8){
	  		  HAL_GPIO_WritePin( L8_GPIO_Port , L8_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==9){
	  		  HAL_GPIO_WritePin( L9_GPIO_Port , L9_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==10){
	  		  HAL_GPIO_WritePin( L10_GPIO_Port , L10_Pin ,GPIO_PIN_SET );
	  	  }
	  	  else if(count==11){
	  		  HAL_GPIO_WritePin( L11_GPIO_Port , L11_Pin ,GPIO_PIN_SET );
	  	  }
  }


void clearNumberOnClock(int count){
	  if(count==0) HAL_GPIO_WritePin( L0_GPIO_Port , L0_Pin ,GPIO_PIN_RESET );
	  else if(count==1)  HAL_GPIO_WritePin( L1_GPIO_Port , L1_Pin ,GPIO_PIN_RESET );
	  else if(count==2)  HAL_GPIO_WritePin( L2_GPIO_Port , L2_Pin ,GPIO_PIN_RESET );
	  else if(count==3)  HAL_GPIO_WritePin( L3_GPIO_Port , L3_Pin ,GPIO_PIN_RESET );
	  else if(count==4)  HAL_GPIO_WritePin( L4_GPIO_Port , L4_Pin ,GPIO_PIN_RESET );
	  else if(count==5)  HAL_GPIO_WritePin( L5_GPIO_Port , L5_Pin ,GPIO_PIN_RESET );
	  else if(count==6)  HAL_GPIO_WritePin( L6_GPIO_Port , L6_Pin ,GPIO_PIN_RESET );
	  else if(count==7)  HAL_GPIO_WritePin( L7_GPIO_Port , L7_Pin ,GPIO_PIN_RESET );
	  else if(count==8)	 HAL_GPIO_WritePin( L8_GPIO_Port , L8_Pin ,GPIO_PIN_RESET );
	  else if(count==9)  HAL_GPIO_WritePin( L9_GPIO_Port , L9_Pin ,GPIO_PIN_RESET );
	  else if(count==10) HAL_GPIO_WritePin( L10_GPIO_Port , L10_Pin ,GPIO_PIN_RESET );
	  else if(count==11) HAL_GPIO_WritePin( L11_GPIO_Port , L11_Pin ,GPIO_PIN_RESET );

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int s=0, sClock=0, m=0, mClock=0, h=0;
    while (1)
    {
  	  setNumberOnClock(h);
  	  setNumberOnClock(m);
  	  setNumberOnClock(s);

  	  if(s==0 && (h!=11 && m!=11))  clearNumberOnClock(11);
  	  if(m==0 && (h!=11 && s!=11))  clearNumberOnClock(11);
  	  if(h==0 && (s!=11 && m!=11))  clearNumberOnClock(11);
  	  if((s-1)!=m && (s-1)!=h) clearNumberOnClock(s-1);

  	  if(s==12) {
  		  mClock++;
              if(mClock / 5 > m) m++;
              if(mClock >= 60) mClock = 0;
              s=0;
  	  	  if((m-1)!=h && (m-1)!=s) clearNumberOnClock(m-1);
  	  }
  	  if(m==12) {
  		  h++; m=0;
  	  	  if((h-1)!=m && (h-1)!=s) clearNumberOnClock(h-1);

  	  }
  	  if(h==12) h=0;

  	  sClock++;
          if(sClock / 5 > s) s++;
          if(sClock >= 60) sClock = 0;
  	  HAL_Delay(50);
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, L0_Pin|L1_Pin|L2_Pin|L10_Pin
                          |L11_Pin|L3_Pin|L4_Pin|L5_Pin
                          |L6_Pin|L7_Pin|L8_Pin|L9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : L0_Pin L1_Pin L2_Pin L10_Pin
                           L11_Pin L3_Pin L4_Pin L5_Pin
                           L6_Pin L7_Pin L8_Pin L9_Pin */
  GPIO_InitStruct.Pin = L0_Pin|L1_Pin|L2_Pin|L10_Pin
                          |L11_Pin|L3_Pin|L4_Pin|L5_Pin
                          |L6_Pin|L7_Pin|L8_Pin|L9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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