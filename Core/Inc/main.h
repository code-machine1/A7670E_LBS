/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
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
#define A7670E_STATUS_Pin GPIO_PIN_14
#define A7670E_STATUS_GPIO_Port GPIOC
#define A7670E_PWIO_Pin GPIO_PIN_1
#define A7670E_PWIO_GPIO_Port GPIOA
#define LPUART1_TX_Pin GPIO_PIN_2
#define LPUART1_TX_GPIO_Port GPIOA
#define LPUART1_RX_Pin GPIO_PIN_3
#define LPUART1_RX_GPIO_Port GPIOA
#define LPUART1_RTS_Pin GPIO_PIN_4
#define LPUART1_RTS_GPIO_Port GPIOA
#define ULN2003_INC_Pin GPIO_PIN_5
#define ULN2003_INC_GPIO_Port GPIOA
#define ULN2003_IND_Pin GPIO_PIN_6
#define ULN2003_IND_GPIO_Port GPIOA
#define BQ__GPOUT_Pin GPIO_PIN_7
#define BQ__GPOUT_GPIO_Port GPIOA
#define BO_SDA_Pin GPIO_PIN_0
#define BO_SDA_GPIO_Port GPIOB
#define BO_SCL_Pin GPIO_PIN_1
#define BO_SCL_GPIO_Port GPIOB
#define SP3485_PWIO_Pin GPIO_PIN_8
#define SP3485_PWIO_GPIO_Port GPIOA
#define STM32_UART2_TX_Pin GPIO_PIN_9
#define STM32_UART2_TX_GPIO_Port GPIOA
#define STM32_UART2_RX_Pin GPIO_PIN_10
#define STM32_UART2_RX_GPIO_Port GPIOA
#define ULN2003_INB_Pin GPIO_PIN_11
#define ULN2003_INB_GPIO_Port GPIOA
#define ULN2003_INA_Pin GPIO_PIN_12
#define ULN2003_INA_GPIO_Port GPIOA
#define VIN_READ_Pin GPIO_PIN_15
#define VIN_READ_GPIO_Port GPIOA
#define TP4056_STDBY_Pin GPIO_PIN_3
#define TP4056_STDBY_GPIO_Port GPIOB
#define TP4056_CHRG_Pin GPIO_PIN_4
#define TP4056_CHRG_GPIO_Port GPIOB
#define TP4056_CE_Pin GPIO_PIN_5
#define TP4056_CE_GPIO_Port GPIOB
#define PWRKEY_IO_Pin GPIO_PIN_6
#define PWRKEY_IO_GPIO_Port GPIOB
#define A7670E_RST_IO_Pin GPIO_PIN_7
#define A7670E_RST_IO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define A7670E_PWIO_EN(x) ((x==1) ? (A7670E_PWIO_GPIO_Port->BSRR=A7670E_PWIO_Pin) : (A7670E_PWIO_GPIO_Port->BRR=A7670E_PWIO_Pin))//1£º¿ªÆô 0£º¹Ø±Õ
#define GET_A7670E_STATUS   HAL_GPIO_ReadPin(A7670E_STATUS_GPIO_Port,A7670E_STATUS_Pin)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
