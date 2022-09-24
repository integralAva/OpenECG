/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32h7xx_hal.h"

#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_ll_system.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_exti.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_cortex.h"
#include "stm32h7xx_ll_utils.h"
#include "stm32h7xx_ll_pwr.h"
#include "stm32h7xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cmsis_os.h"
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
#define ECA_Pin LL_GPIO_PIN_0
#define ECA_GPIO_Port GPIOA
#define ECA_EXTI_IRQn EXTI0_IRQn
#define ECB_Pin LL_GPIO_PIN_1
#define ECB_GPIO_Port GPIOA
#define ECS_Pin LL_GPIO_PIN_4
#define ECS_GPIO_Port GPIOA
#define ECS_EXTI_IRQn EXTI4_IRQn
#define TRST_Pin LL_GPIO_PIN_7
#define TRST_GPIO_Port GPIOA
#define TWR_Pin LL_GPIO_PIN_4
#define TWR_GPIO_Port GPIOC
#define TCS_Pin LL_GPIO_PIN_5
#define TCS_GPIO_Port GPIOC
#define TSDI_Pin LL_GPIO_PIN_0
#define TSDI_GPIO_Port GPIOB
#define TRS_Pin LL_GPIO_PIN_1
#define TRS_GPIO_Port GPIOB
#define TRD_Pin LL_GPIO_PIN_2
#define TRD_GPIO_Port GPIOB
#define PWGD_Pin LL_GPIO_PIN_11
#define PWGD_GPIO_Port GPIOB
#define PWCH_Pin LL_GPIO_PIN_12
#define PWCH_GPIO_Port GPIOB
#define PWCH_EXTI_IRQn EXTI15_10_IRQn
#define L4_Pin LL_GPIO_PIN_8
#define L4_GPIO_Port GPIOD
#define LR_Pin LL_GPIO_PIN_2
#define LR_GPIO_Port GPIOD
#define LG_Pin LL_GPIO_PIN_3
#define LG_GPIO_Port GPIOD
#define LB_Pin LL_GPIO_PIN_4
#define LB_GPIO_Port GPIOD
#define L1_Pin LL_GPIO_PIN_5
#define L1_GPIO_Port GPIOD
#define L2_Pin LL_GPIO_PIN_6
#define L2_GPIO_Port GPIOD
#define L3_Pin LL_GPIO_PIN_7
#define L3_GPIO_Port GPIOD
#define ADC_CS_Pin LL_GPIO_PIN_6
#define ADC_CS_GPIO_Port GPIOB
#define ADC_DR_Pin LL_GPIO_PIN_7
#define ADC_DR_GPIO_Port GPIOB
#define KFA_Pin LL_GPIO_PIN_8
#define KFA_GPIO_Port GPIOB
#define KFA_EXTI_IRQn EXTI9_5_IRQn
#define KFB_Pin LL_GPIO_PIN_9
#define KFB_GPIO_Port GPIOB
#define KFB_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
