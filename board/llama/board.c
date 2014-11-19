/* Copyright (c) 2014 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
/* Llama board configuration */

#include "chipset.h"
#include "common.h"
#include "gpio.h"
#include "hooks.h"
#include "registers.h"
#include "task.h"
#include "util.h"
#include "i2c.h"
#include "spi.h"
#include "keyboard_raw.h"
#include "extpower.h"
#include "charger.h"
#include "power_button.h"
#include "lid_switch.h"
#include "power.h"
#include "console.h"
#include "pwm.h"
#include "pwm_chip.h"
#include "battery.h"

#define CPRINTS(format, args...) cprints(CC_CHIPSET, format, ## args)
#define CPRINTF(format, args...) cprintf(CC_CHIPSET, format, ## args)

 #define GPIO_ALT_I2C                 0x4

void button_event(enum gpio_signal signal);
#ifdef CONFIG_I2C
void i2c2_event_interrupt(void);
#endif

#define GPIO_KB_INPUT  (GPIO_INPUT | GPIO_PULL_UP | GPIO_INT_BOTH)
#define GPIO_KB_OUTPUT GPIO_ODR_HIGH

#include "gpio_list.h"

/* power signal list.  Must match order of enum power_signal. */
const struct power_signal_info power_signal_list[] = {
	{GPIO_SOC_POWER_GOOD_L, 0, "POWER_GOOD#"}, //Active low
	{GPIO_SUSPEND_L,      0, "SUSPEND#_ASSERTED"}, //Active low
};
BUILD_ASSERT(ARRAY_SIZE(power_signal_list) == POWER_SIGNAL_COUNT);

#ifdef CONFIG_PWM
/* PWM channels. Must be in the exactly same order as in enum pwm_channel. */
const struct pwm_t pwm_channels[] = {
	{STM32_TIM(2), STM32_TIM_CH(3),
	 PWM_CONFIG_ACTIVE_LOW, GPIO_LED_POWER_L},
};
BUILD_ASSERT(ARRAY_SIZE(pwm_channels) == PWM_CH_COUNT);
#endif

#ifdef CONFIG_I2C
/* I2C ports */
const struct i2c_port_t i2c_ports[] = {
	{"master", I2C_PORT_MASTER, 100, GPIO_MASTER_I2C_SCL, GPIO_MASTER_I2C_SDA},
#ifdef CONFIG_HOSTCMD_I2C_SLAVE_ADDR
	{"slave",  I2C_PORT_SLAVE,  100, GPIO_SLAVE_I2C_SCL,  GPIO_SLAVE_I2C_SDA}
#endif
};
const unsigned int i2c_ports_used = ARRAY_SIZE(i2c_ports);
#endif


/**
 * Discharge battery when on AC power for factory test.
 */
int board_discharge_on_ac(int enable)
{
	return charger_discharge_on_ac(enable);
}

void board_config_pre_init(void)
{
	//CPRINTF("pre_init\n");
	/* enable SYSCFG clock */
	//STM32_RCC_APB2ENR |= 1 << 0;

	/* Remap USART DMA to match the USART driver */
	/*
	 * the DMA mapping is :
	 *  Chan 2 : TIM1_CH1
	 *  Chan 3 : SPI1_TX
	 *  Chan 4 : USART1_TX
	 *  Chan 5 : USART1_RX
	 */
	//STM32_SYSCFG_CFGR1 |= (1 << 9) | (1 << 10); /* Remap USART1 RX/TX DMA */

	/* Remap SPI2 to DMA channels 6 and 7 */
	//STM32_SYSCFG_CFGR1 |= (1 << 24) | (1 <<30);
	//Because define DMA channel in registers.h
	//STM32_DMAC_SPI2_RX = STM32_DMAC_CH6,
	//STM32_DMAC_SPI2_TX = STM32_DMAC_CH7,

	/* Remap DMA channels*/
	//Because define DMA channel in registers.h
	//STM32_SYSCFG_CFGR1 |= (1 << 29) | (1 <<28)| (1 <<27)| (1 <<10);
}

/* Initialize board. */
static void board_init(void)
{
	ccprintf("board_init\n");
}
DECLARE_HOOK(HOOK_INIT, board_init, HOOK_PRIO_DEFAULT);


