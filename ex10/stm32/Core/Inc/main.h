/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EXB1_Pin GPIO_PIN_2
#define EXB1_GPIO_Port GPIOA
#define EXB2_Pin GPIO_PIN_3
#define EXB2_GPIO_Port GPIOA
#define DOT_Pin GPIO_PIN_4
#define DOT_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define P1_Pin GPIO_PIN_6
#define P1_GPIO_Port GPIOA
#define P2_Pin GPIO_PIN_7
#define P2_GPIO_Port GPIOA
#define L1_Pin GPIO_PIN_0
#define L1_GPIO_Port GPIOB
#define L2_Pin GPIO_PIN_1
#define L2_GPIO_Port GPIOB
#define L3_Pin GPIO_PIN_2
#define L3_GPIO_Port GPIOB
#define BUF3_Pin GPIO_PIN_10
#define BUF3_GPIO_Port GPIOB
#define BUF4_Pin GPIO_PIN_11
#define BUF4_GPIO_Port GPIOB
#define BUF5_Pin GPIO_PIN_12
#define BUF5_GPIO_Port GPIOB
#define BUF6_Pin GPIO_PIN_13
#define BUF6_GPIO_Port GPIOB
#define BUF7_Pin GPIO_PIN_14
#define BUF7_GPIO_Port GPIOB
#define BUF8_Pin GPIO_PIN_15
#define BUF8_GPIO_Port GPIOB
#define P3_Pin GPIO_PIN_8
#define P3_GPIO_Port GPIOA
#define P4_Pin GPIO_PIN_9
#define P4_GPIO_Port GPIOA
#define EXB3_Pin GPIO_PIN_10
#define EXB3_GPIO_Port GPIOA
#define EXB4_Pin GPIO_PIN_11
#define EXB4_GPIO_Port GPIOA
#define EXB5_Pin GPIO_PIN_12
#define EXB5_GPIO_Port GPIOA
#define EXB6_Pin GPIO_PIN_13
#define EXB6_GPIO_Port GPIOA
#define EXB7_Pin GPIO_PIN_14
#define EXB7_GPIO_Port GPIOA
#define EXB8_Pin GPIO_PIN_15
#define EXB8_GPIO_Port GPIOA
#define L4_Pin GPIO_PIN_3
#define L4_GPIO_Port GPIOB
#define L5_Pin GPIO_PIN_4
#define L5_GPIO_Port GPIOB
#define L6_Pin GPIO_PIN_5
#define L6_GPIO_Port GPIOB
#define L7_Pin GPIO_PIN_6
#define L7_GPIO_Port GPIOB
#define BUF1_Pin GPIO_PIN_8
#define BUF1_GPIO_Port GPIOB
#define BUF2_Pin GPIO_PIN_9
#define BUF2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
