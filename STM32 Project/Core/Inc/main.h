/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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
#define EN0_Pin GPIO_PIN_0
#define EN0_GPIO_Port GPIOA
#define Button1_Pin GPIO_PIN_1
#define Button1_GPIO_Port GPIOA
#define Button2_Pin GPIO_PIN_2
#define Button2_GPIO_Port GPIOA
#define Button3_Pin GPIO_PIN_3
#define Button3_GPIO_Port GPIOA
#define GREEN_LED_Pin GPIO_PIN_4
#define GREEN_LED_GPIO_Port GPIOA
#define YELLOW_LED_Pin GPIO_PIN_5
#define YELLOW_LED_GPIO_Port GPIOA
#define RED_LED_Pin GPIO_PIN_6
#define RED_LED_GPIO_Port GPIOA
#define GREEN_LED1_Pin GPIO_PIN_7
#define GREEN_LED1_GPIO_Port GPIOA
#define SEGM6_Pin GPIO_PIN_0
#define SEGM6_GPIO_Port GPIOB
#define SEG0_Pin GPIO_PIN_1
#define SEG0_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_2
#define SEG1_GPIO_Port GPIOB
#define SEG_2_Pin GPIO_PIN_10
#define SEG_2_GPIO_Port GPIOB
#define SEG_3_Pin GPIO_PIN_11
#define SEG_3_GPIO_Port GPIOB
#define SEG_4_Pin GPIO_PIN_12
#define SEG_4_GPIO_Port GPIOB
#define SEG_5_Pin GPIO_PIN_13
#define SEG_5_GPIO_Port GPIOB
#define SEG_6_Pin GPIO_PIN_14
#define SEG_6_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_15
#define EN1_GPIO_Port GPIOB
#define YELLOW_LED1_Pin GPIO_PIN_8
#define YELLOW_LED1_GPIO_Port GPIOA
#define RED_LED1_Pin GPIO_PIN_9
#define RED_LED1_GPIO_Port GPIOA
#define SEGM0_Pin GPIO_PIN_10
#define SEGM0_GPIO_Port GPIOA
#define SEGM1_Pin GPIO_PIN_11
#define SEGM1_GPIO_Port GPIOA
#define SEGM2_Pin GPIO_PIN_12
#define SEGM2_GPIO_Port GPIOA
#define SEGM3_Pin GPIO_PIN_13
#define SEGM3_GPIO_Port GPIOA
#define SEGM4_Pin GPIO_PIN_14
#define SEGM4_GPIO_Port GPIOA
#define SEGM5_Pin GPIO_PIN_15
#define SEGM5_GPIO_Port GPIOA
#define SEG2_Pin GPIO_PIN_3
#define SEG2_GPIO_Port GPIOB
#define SEG3_Pin GPIO_PIN_4
#define SEG3_GPIO_Port GPIOB
#define SEG4_Pin GPIO_PIN_5
#define SEG4_GPIO_Port GPIOB
#define SEG5_Pin GPIO_PIN_6
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_7
#define SEG6_GPIO_Port GPIOB
#define SEG_0_Pin GPIO_PIN_8
#define SEG_0_GPIO_Port GPIOB
#define SEG_1_Pin GPIO_PIN_9
#define SEG_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
