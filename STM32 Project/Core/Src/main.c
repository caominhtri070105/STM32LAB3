/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
#include "button.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
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

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
// Bảng tra cứu cho LED 7 đoạn (hiển thị số từ 0 đến 9)
const uint8_t seven_seg_digits[] = {
    0b0000001, // 0
    0b1001111, // 1
    0b0010010, // 2
    0b0000110, // 3
    0b1001100, // 4
    0b0100100, // 5
    0b0100000, // 6
    0b0001111, // 7
    0b0000000, // 8
    0b0000100  // 9
};

void display7SEG1(int number) {
    if (number < 0 || number > 9) return;  // Kiểm tra số hợp lệ

    uint8_t digit = seven_seg_digits[number];  // Lấy trạng thái từ bảng tra cứu

    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (digit & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (digit & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (digit & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (digit & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (digit & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (digit & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (digit & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void display7SEG2(int number) {
    if (number < 0 || number > 9) return;  // Kiểm tra số hợp lệ

    uint8_t digit = seven_seg_digits[number];  // Lấy trạng thái từ bảng tra cứu

    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, (digit & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, (digit & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, (digit & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, (digit & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, (digit & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, (digit & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, (digit & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void display7SEGMODE(int number) {
    if (number < 0 || number > 9) return;  // Kiểm tra số hợp lệ

    uint8_t digit = seven_seg_digits[number];  // Lấy trạng thái từ bảng tra cứu

    HAL_GPIO_WritePin(SEGM0_GPIO_Port, SEGM0_Pin, (digit & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM1_GPIO_Port, SEGM1_Pin, (digit & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM2_GPIO_Port, SEGM2_Pin, (digit & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM3_GPIO_Port, SEGM3_Pin, (digit & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM4_GPIO_Port, SEGM4_Pin, (digit & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM5_GPIO_Port, SEGM5_Pin, (digit & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(SEGM6_GPIO_Port, SEGM6_Pin, (digit & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
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
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  status=INIT;
  status1=INIT;
  while (1)
  {
	  fsm_automatic_run();
	  fsm_manual_run();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  HAL_GPIO_WritePin(GPIOA, EN0_Pin|Button1_Pin|Button2_Pin|Button3_Pin
                          |GREEN_LED_Pin|YELLOW_LED_Pin|RED_LED_Pin|GREEN_LED1_Pin
                          |YELLOW_LED1_Pin|RED_LED1_Pin|SEGM0_Pin|SEGM1_Pin
                          |SEGM2_Pin|SEGM3_Pin|SEGM4_Pin|SEGM5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEGM6_Pin|SEG0_Pin|SEG1_Pin|SEG_2_Pin
                          |SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin
                          |EN1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin
                          |SEG5_Pin|SEG6_Pin|SEG_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : EN0_Pin Button1_Pin Button2_Pin Button3_Pin
                           GREEN_LED_Pin YELLOW_LED_Pin RED_LED_Pin GREEN_LED1_Pin
                           YELLOW_LED1_Pin RED_LED1_Pin SEGM0_Pin SEGM1_Pin
                           SEGM2_Pin SEGM3_Pin SEGM4_Pin SEGM5_Pin */
  GPIO_InitStruct.Pin = EN0_Pin|Button1_Pin|Button2_Pin|Button3_Pin
                          |GREEN_LED_Pin|YELLOW_LED_Pin|RED_LED_Pin|GREEN_LED1_Pin
                          |YELLOW_LED1_Pin|RED_LED1_Pin|SEGM0_Pin|SEGM1_Pin
                          |SEGM2_Pin|SEGM3_Pin|SEGM4_Pin|SEGM5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEGM6_Pin SEG0_Pin SEG1_Pin SEG_2_Pin
                           SEG_3_Pin SEG_4_Pin SEG_5_Pin SEG_6_Pin
                           EN1_Pin SEG2_Pin SEG3_Pin SEG4_Pin
                           SEG5_Pin SEG6_Pin SEG_1_Pin */
  GPIO_InitStruct.Pin = SEGM6_Pin|SEG0_Pin|SEG1_Pin|SEG_2_Pin
                          |SEG_3_Pin|SEG_4_Pin|SEG_5_Pin|SEG_6_Pin
                          |EN1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin
                          |SEG5_Pin|SEG6_Pin|SEG_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : SEG_0_Pin */
  GPIO_InitStruct.Pin = SEG_0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SEG_0_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	timerRun();
	getKeyInput();
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
