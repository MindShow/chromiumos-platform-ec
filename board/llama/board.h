/* Copyright (c) 2014 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* STM32F072-discovery board configuration */

#ifndef __BOARD_H
#define __BOARD_H

#define CONFIG_BOARD_PRE_INIT

#define CONFIG_SPI_CS_GPIO GPIO_SPI_CS_GPIO

#define CONFIG_BRINGUP

/* 48 MHz SYSCLK clock frequency */
#define CPU_CLOCK 48000000

/* Hibernate is not supported on STM32F0.*/
#undef CONFIG_HIBERNATE 

#define CONFIG_PMIC_FW_LONG_PRESS_TIMER

/* the UART console is on USART2 (PA14/PA15) */
#undef CONFIG_UART_CONSOLE
#define CONFIG_UART_CONSOLE 1
#undef CONFIG_UART_RX_DMA
#undef CONFIG_UART_TX_DMA

/*#define CONFIG_PWM*/
#define CONFIG_LED_COMMON

#define CONFIG_KEYBOARD_PROTOCOL_MKBP

/* Optional features */
#define CONFIG_STM_HWTIMER32
#define CONFIG_HW_CRC
#define CONFIG_KEYBOARD_PROTOCOL_MKBP

#undef CONFIG_WATCHDOG_HELP
#undef CONFIG_WATCHDOG
/* #define CONFIG_COMMON_TIMER */

#define CONFIG_POWER_BUTTON
#define CONFIG_LID_SWITCH
#define CONFIG_SWITCH
#define CONFIG_HOST_COMMAND_STATUS
#define CONFIG_BOARD_VERSION

#define CONFIG_I2C
#define CONFIG_I2C_DEBUG
/* #define I2C_PORT_EC STM32_I2C2_PORT */

/* Single I2C port, where the EC is the master. */
#define I2C_PORT_MASTER 0
#define I2C_PORT_BATTERY I2C_PORT_MASTER
#define I2C_PORT_CHARGER I2C_PORT_MASTER
/* #define I2C_PORT_SLAVE  1 */

#define CONFIG_SPI
#define CONFIG_POWER_COMMON
#define CONFIG_EXTPOWER_GPIO

/* Add for AC adaptor, charger, battery */
#define CONFIG_BATTERY_SMART
#undef CONFIG_BATTERY_CUT_OFF
#define CONFIG_CHARGER
#define CONFIG_CHARGER_V2
#define CONFIG_CHARGER_DISCHARGE_ON_AC
#define CONFIG_CHARGER_BQ24715
#define CONFIG_CHARGER_SENSE_RESISTOR 10 /* Charge sense resistor, mOhm */
#define CONFIG_CHARGER_SENSE_RESISTOR_AC 10 /* Input sensor resistor, mOhm */
#define CONFIG_CHARGER_INPUT_CURRENT 2150 /* mA, based on Link HW design */


/* slave address for host commands */
#ifdef HAS_TASK_HOSTCMD
/* #define CONFIG_HOSTCMD_I2C_SLAVE_ADDR 0x3c */
#endif

/* Keyboard output port list */
#define KB_OUT_PORT_LIST GPIO_A, GPIO_B, GPIO_C

/*
 * Allow dangerous commands all the time, since we don't have a write protect
 * switch.
 */
#define CONFIG_SYSTEM_UNLOCKED

#ifndef __ASSEMBLER__

/* Timer selection */
#define TIM_CLOCK32 2

#include "gpio_signal.h"

enum power_signal {
	POWER_GOOD = 0,
	SUSPEND_ASSERTED,

	/* Number of power signals */
	POWER_SIGNAL_COUNT
};

enum pwm_channel {
	PWM_CH_POWER_LED = 0,
	/* Number of PWM channels */
	PWM_CH_COUNT
};


/* Discharge battery when on AC power for factory test. */
int board_discharge_on_ac(int enable);


#endif /* !__ASSEMBLER__ */

#endif /* __BOARD_H */
