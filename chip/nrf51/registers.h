/* Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Register map for STM32 processor
 */

#ifndef __CROS_EC_REGISTERS_H
#define __CROS_EC_REGISTERS_H

#include "common.h"

/*
 *  Peripheral IDs
 *
 *  nRF51 has very good design that the peripheral IDs is actually the IRQ#.
 *  Thus, the following numbers are used in DECLARE_IRQ(), task_enable_irq()
 *  and task_disable_irq().
 */
#define NRF51_PERID_POWER   0
#define NRF51_PERID_CLOCK   0
#define NRF51_PERID_RADIO   1
#define NRF51_PERID_USART   2
#define NRF51_PERID_SPI0    3
#define NRF51_PERID_TWI0    3
#define NRF51_PERID_SPI1    4
#define NRF51_PERID_TWI1    4
#define NRF51_PERID_SPIS    4
#define NRF51_PERID_GPIOTE  6
#define NRF51_PERID_ADC     7
#define NRF51_PERID_TIMER0  8
#define NRF51_PERID_TIMER1  9
#define NRF51_PERID_TIMER2  10
#define NRF51_PERID_RTC     11
#define NRF51_PERID_TEMP    12
#define NRF51_PERID_RNG     13
#define NRF51_PERID_ECB     14
#define NRF51_PERID_CCM     15
#define NRF51_PERID_AAR     16
#define NRF51_PERID_WDT     17
#define NRF51_PERID_QDEC    18
#define NRF51_PERID_LPCOMP  19
#define NRF51_PERID_NVMC    30
#define NRF51_PERID_PPI     31

/*
 * The nRF51 allows any pin to be mapped to any function.  This
 * doesn't fit well with the notion of the alternate function table.
 * Implement an alternate function table.  See ./gpio.c.
 */

	/* UART */
#define NRF51_UART_ALT_FUNC_RTS        0
#define NRF51_UART_ALT_FUNC_TXD        1
#define NRF51_UART_ALT_FUNC_CTS        2
#define NRF51_UART_ALT_FUNC_RXD        3
	/* SPI1 (SPI Master) */
#define NRF51_SPI0_ALT_FUNC_SCK        4
#define NRF51_SPI0_ALT_FUNC_MOSI       5
#define NRF51_SPI0_ALT_FUNC_MISO       6
	/* TWI0 (I2C) */
#define NRF51_TWI0_ALT_FUNC_SCL        7
#define NRF51_TWI0_ALT_FUNC_SDA        8
	/* SPI1 (SPI Master) */
#define NRF51_SPI1_ALT_FUNC_SCK        9
#define NRF51_SPI1_ALT_FUNC_MOSI       10
#define NRF51_SPI1_ALT_FUNC_MISO       11
	/* TWI1 (I2C) */
#define NRF51_TWI1_ALT_FUNC_SCL        12
#define NRF51_TWI1_ALT_FUNC_SDA        13
	/* SPIS1 (SPI SLAVE) */
#define NRF51_SPIS1_ALT_FUNC_SCK       14
#define NRF51_SPIS1_ALT_FUNC_MISO      15
#define NRF51_SPIS1_ALT_FUNC_MOSI      16
#define NRF51_SPIS1_ALT_FUNC_CSN       17
	/* QDEC (ROTARY DECODER) */
#define NRF51_QDEC_ALT_FUNC_LED        18
#define NRF51_QDEC_ALT_FUNC_A          19
#define NRF51_QDEC_ALT_FUNC_B          20
	/* LPCOMP (Low Power Comparator) */
#define NRF51_LPCOMP_ALT_FUNC          21
#define NRF51_MAX_ALT_FUNCS            22

/*
 *  Power
 */
#define NRF51_POWER_BASE    0x40000000
/* Tasks */
#define NRF51_POWER_CONSTLAT  REG32(NRF51_POWER_BASE + 0x078)
#define NRF51_POWER_LOWPWR    REG32(NRF51_POWER_BASE + 0x07C)
/* Events */
#define NRF51_POWER_POFWARN   REG32(NRF51_POWER_BASE + 0x108)
/* Registers */
#define NRF51_POWER_INTENSET  REG32(NRF51_POWER_BASE + 0x304)
#define NRF51_POWER_INTENCLR  REG32(NRF51_POWER_BASE + 0x308)
#define NRF51_POWER_RESETREAS REG32(NRF51_POWER_BASE + 0x400)
#define NRF51_POWER_SYSTEMOFF REG32(NRF51_POWER_BASE + 0x500)
#define NRF51_POWER_POFCON    REG32(NRF51_POWER_BASE + 0x510)
#define NRF51_POWER_GPREGRET  REG32(NRF51_POWER_BASE + 0x51C)
#define NRF51_POWER_RAMON     REG32(NRF51_POWER_BASE + 0x524)
#define NRF51_POWER_RESET     REG32(NRF51_POWER_BASE + 0x544)
#define NRF51_POWER_DCDCEN    REG32(NRF51_POWER_BASE + 0x578)


/*
 *  Clock
 */
#define NRF51_CLOCK_BASE    0x40000000
/* Tasks */
#define NRF51_CLOCK_HFCLKSTART REG32(NRF51_CLOCK_BASE + 0x000)
#define NRF51_CLOCK_HFCLKSTOP  REG32(NRF51_CLOCK_BASE + 0x004)
#define NRF51_CLOCK_LFCLKSTART REG32(NRF51_CLOCK_BASE + 0x008)
#define NRF51_CLOCK_LFCLKSTOP  REG32(NRF51_CLOCK_BASE + 0x00C)
#define NRF51_CLOCK_CAL     REG32(NRF51_CLOCK_BASE + 0x010)
#define NRF51_CLOCK_CTSTART REG32(NRF51_CLOCK_BASE + 0x014)
#define NRF51_CLOCK_CTSTOP  REG32(NRF51_CLOCK_BASE + 0x018)
/* Events */
#define NRF51_CLOCK_HFCLKSTARTED REG32(NRF51_CLOCK_BASE + 0x100)
#define NRF51_CLOCK_LFCLKSTARTED REG32(NRF51_CLOCK_BASE + 0x104)
#define NRF51_CLOCK_DONE    REG32(NRF51_CLOCK_BASE + 0x10C)
#define NRF51_CLOCK_CCTO    REG32(NRF51_CLOCK_BASE + 0x110)
/* Registers */
#define NRF51_CLOCK_INTENSET  REG32(NRF51_CLOCK_BASE + 0x304)
#define NRF51_CLOCK_INTENCLR  REG32(NRF51_CLOCK_BASE + 0x308)
#define NRF51_CLOCK_HFCLKSTAT REG32(NRF51_CLOCK_BASE + 0x40C)
#define NRF51_CLOCK_LFCLKSTAT REG32(NRF51_CLOCK_BASE + 0x418)
#define NRF51_CLOCK_LFCLKSRC  REG32(NRF51_CLOCK_BASE + 0x518)
#define NRF51_CLOCK_CTIV      REG32(NRF51_CLOCK_BASE + 0x538)
#define NRF51_CLOCK_XTALFREQ  REG32(NRF51_CLOCK_BASE + 0x550)

/*
 *  UART
 */
#define NRF51_UART_BASE     0x40002000
/* Tasks */
#define NRF51_UART_STARTRX  REG32(NRF51_UART_BASE + 0x000)
#define NRF51_UART_STOPRX   REG32(NRF51_UART_BASE + 0x004)
#define NRF51_UART_STARTTX  REG32(NRF51_UART_BASE + 0x008)
#define NRF51_UART_STOPTX   REG32(NRF51_UART_BASE + 0x00C)
/* Events */
#define NRF51_UART_RXDRDY   REG32(NRF51_UART_BASE + 0x108)
#define NRF51_UART_TXDRDY   REG32(NRF51_UART_BASE + 0x11C)
#define NRF51_UART_ERROR    REG32(NRF51_UART_BASE + 0x124)
#define NRF51_UART_RXTO     REG32(NRF51_UART_BASE + 0x144)
/* Registers */
#define NRF51_UART_INTENSET REG32(NRF51_UART_BASE + 0x304)
#define NRF51_UART_INTENCLR REG32(NRF51_UART_BASE + 0x308)
#define NRF51_UART_ERRORSRC REG32(NRF51_UART_BASE + 0x480)
#define NRF51_UART_ENABLE   REG32(NRF51_UART_BASE + 0x500)
#define NRF51_UART_PSELRTS  REG32(NRF51_UART_BASE + 0x508)
#define NRF51_UART_PSELTXD  REG32(NRF51_UART_BASE + 0x50C)
#define NRF51_UART_PSELCTS  REG32(NRF51_UART_BASE + 0x510)
#define NRF51_UART_PSELRXD  REG32(NRF51_UART_BASE + 0x514)
#define NRF51_UART_RXD      REG32(NRF51_UART_BASE + 0x518)
#define NRF51_UART_TXD      REG32(NRF51_UART_BASE + 0x51C)
#define NRF51_UART_BAUDRATE REG32(NRF51_UART_BASE + 0x524)
#define NRF51_UART_CONFIG   REG32(NRF51_UART_BASE + 0x56C)
/* For UART.INTEN bits */
#define NRF55_UART_RXDRDY_BIT  ((0x108 - 0x100) / 4)
#define NRF55_UART_TXDRDY_BIT  ((0x11C - 0x100) / 4)

/*
 *  TWI (I2C) Instances
 */
#define NRF51_TWI_BASE(port)     (0x40003000 + ((port == 0) ? 0 : 0x1000))
/* Tasks */
#define NRF51_TWI_STARTRX(port)   REG32(NRF51_TWI_BASE(port) + 0x000)
#define NRF51_TWI_STARTTX(port)   REG32(NRF51_TWI_BASE(port) + 0x008)
#define NRF51_TWI_STOP(port)      REG32(NRF51_TWI_BASE(port) + 0x014)
#define NRF51_TWI_SUSPEND(port)   REG32(NRF51_TWI_BASE(port) + 0x01C)
#define NRF51_TWI_RESUME(port)    REG32(NRF51_TWI_BASE(port) + 0x020)
/* Events */
#define NRF51_TWI_STOPPED(port)   REG32(NRF51_TWI_BASE(port) + 0x104)
#define NRF51_TWI_RXDRDY(port)    REG32(NRF51_TWI_BASE(port) + 0x108)
#define NRF51_TWI_TXDSENT(port)   REG32(NRF51_TWI_BASE(port) + 0x11C)
#define NRF51_TWI_ERROR(port)     REG32(NRF51_TWI_BASE(port) + 0x124)
#define NRF51_TWI_BB(port)        REG32(NRF51_TWI_BASE(port) + 0x138)
/* Registers */
/* SHORTS not implemented for TWI (See nRF51822-PAN v2.4)  */
#define NRF51_TWI_INTEN(port)     REG32(NRF51_TWI_BASE(port) + 0x300)
#define NRF51_TWI_INTENSET(port)  REG32(NRF51_TWI_BASE(port) + 0x304)
#define NRF51_TWI_INTENCLR(port)  REG32(NRF51_TWI_BASE(port) + 0x308)
#define NRF51_TWI_ERRORSRC(port)  REG32(NRF51_TWI_BASE(port) + 0x4C4)
#define NRF51_TWI_ENABLE(port)    REG32(NRF51_TWI_BASE(port) + 0x500)
#define NRF51_TWI_PSELSCL(port)   REG32(NRF51_TWI_BASE(port) + 0x508)
#define NRF51_TWI_PSELSDA(port)   REG32(NRF51_TWI_BASE(port) + 0x50C)
#define NRF51_TWI_RXD(port)       REG32(NRF51_TWI_BASE(port) + 0x518)
#define NRF51_TWI_TXD(port)       REG32(NRF51_TWI_BASE(port) + 0x51C)
#define NRF51_TWI_FREQUENCY(port) REG32(NRF51_TWI_BASE(port) + 0x524)
#define NRF51_TWI_ADDRESS(port)   REG32(NRF51_TWI_BASE(port) + 0x588)
#define NRF51_TWI_POWER(port)     REG32(NRF51_TWI_BASE(port) + 0xFFC)

#define NRF51_TWI_100KBPS         0x01980000
#define NRF51_TWI_250KBPS         0x40000000
#define NRF51_TWI_400KBPS         0x06680000

#define NRF51_TWI_ENABLE_VAL      0x5
#define NRF51_TWI_DISABLE_VAL     0x0

#define NRF51_TWI_ERRORSRC_ANACK  (1<<1) /* Address NACK */
#define NRF51_TWI_ERRORSRC_DNACK  (1<<2) /* Data NACK */

/*
 *  TWI (I2C) Instance 0
 */
#define NRF51_TWI0_BASE     0x40003000
/* Tasks */
#define NRF51_TWI0_STARTRX   REG32(NRF51_TWI0_BASE + 0x000)
#define NRF51_TWI0_STARTTX   REG32(NRF51_TWI0_BASE + 0x008)
#define NRF51_TWI0_STOP      REG32(NRF51_TWI0_BASE + 0x014)
#define NRF51_TWI0_SUSPEND   REG32(NRF51_TWI0_BASE + 0x01C)
#define NRF51_TWI0_RESUME    REG32(NRF51_TWI0_BASE + 0x020)
/* Events */
#define NRF51_TWI0_STOPPED   REG32(NRF51_TWI0_BASE + 0x104)
#define NRF51_TWI0_RXDRDY    REG32(NRF51_TWI0_BASE + 0x108)
#define NRF51_TWI0_TXDSENT   REG32(NRF51_TWI0_BASE + 0x11C)
#define NRF51_TWI0_ERROR     REG32(NRF51_TWI0_BASE + 0x124)
#define NRF51_TWI0_BB        REG32(NRF51_TWI0_BASE + 0x138)
/* Registers */
/* SHORTS not implemented for TWI (See nRF51822-PAN v2.4)  */
#define NRF51_TWI0_INTENSET  REG32(NRF51_TWI0_BASE + 0x304)
#define NRF51_TWI0_INTENCLR  REG32(NRF51_TWI0_BASE + 0x308)
#define NRF51_TWI0_ERRORSRC  REG32(NRF51_TWI0_BASE + 0x4C4)
#define NRF51_TWI0_ENABLE    REG32(NRF51_TWI0_BASE + 0x500)
#define NRF51_TWI0_PSELSCL   REG32(NRF51_TWI0_BASE + 0x508)
#define NRF51_TWI0_PSELSDA   REG32(NRF51_TWI0_BASE + 0x50C)
#define NRF51_TWI0_RXD       REG32(NRF51_TWI0_BASE + 0x518)
#define NRF51_TWI0_TXD       REG32(NRF51_TWI0_BASE + 0x51C)
#define NRF51_TWI0_FREQUENCY REG32(NRF51_TWI0_BASE + 0x524)
#define NRF51_TWI0_ADDRESS   REG32(NRF51_TWI0_BASE + 0x588)

/* For TWI0.INTEN bits */
#define NRF55_TWI0_RXDRDY_BIT  ((0x108 - 0x100) / 4)
#define NRF55_TWI0_TXDRDY_BIT  ((0x11C - 0x100) / 4)

/*
 *  TWI (I2C) Instance 1
 */
#define NRF51_TWI1_BASE     0x40004000
/* Tasks */
#define NRF51_TWI1_STARTRX   REG32(NRF51_TWI1_BASE + 0x000)
#define NRF51_TWI1_STARTTX   REG32(NRF51_TWI1_BASE + 0x008)
#define NRF51_TWI1_STOP      REG32(NRF51_TWI1_BASE + 0x014)
#define NRF51_TWI1_SUSPEND   REG32(NRF51_TWI1_BASE + 0x01C)
#define NRF51_TWI1_RESUME    REG32(NRF51_TWI1_BASE + 0x020)
/* Events */
#define NRF51_TWI1_STOPPED   REG32(NRF51_TWI1_BASE + 0x104)
#define NRF51_TWI1_RXDRDY    REG32(NRF51_TWI1_BASE + 0x108)
#define NRF51_TWI1_TXDSENT   REG32(NRF51_TWI1_BASE + 0x11C)
#define NRF51_TWI1_ERROR     REG32(NRF51_TWI1_BASE + 0x124)
#define NRF51_TWI1_BB        REG32(NRF51_TWI1_BASE + 0x138)
/* Registers */
/* SHORTS not implemented for TWI (See nRF51822-PAN v2.4)  */
#define NRF51_TWI1_INTENSET  REG32(NRF51_TWI1_BASE + 0x304)
#define NRF51_TWI1_INTENCLR  REG32(NRF51_TWI1_BASE + 0x308)
#define NRF51_TWI1_ERRORSRC  REG32(NRF51_TWI1_BASE + 0x4C4)
#define NRF51_TWI1_ENABLE    REG32(NRF51_TWI1_BASE + 0x500)
#define NRF51_TWI1_PSELSCL   REG32(NRF51_TWI1_BASE + 0x508)
#define NRF51_TWI1_PSELSDA   REG32(NRF51_TWI1_BASE + 0x50C)
#define NRF51_TWI1_RXD       REG32(NRF51_TWI1_BASE + 0x518)
#define NRF51_TWI1_TXD       REG32(NRF51_TWI1_BASE + 0x51C)
#define NRF51_TWI1_FREQUENCY REG32(NRF51_TWI1_BASE + 0x524)
#define NRF51_TWI1_ADDRESS   REG32(NRF51_TWI1_BASE + 0x588)

/* For TWI1.INTEN bits */
#define NRF55_TWI1_RXDRDY_BIT  ((0x108 - 0x100) / 4)
#define NRF55_TWI1_TXDRDY_BIT  ((0x11C - 0x100) / 4)

/*
 *  GPIOTE - GPIO Tasks and Events
 */
#define NRF51_GPIOTE_BASE   0x40006000
/* Tasks */
#define NRF51_GPIOTE_OUT(n)    REG32(NRF51_GPIOTE_BASE + ((n) * 4))
/* Events */
#define NRF51_GPIOTE_IN(n)     REG32(NRF51_GPIOTE_BASE + 0x100 + ((n) * 4))
#define NRF51_GPIOTE_PORT      REG32(NRF51_GPIOTE_BASE + 0x17C)
/* Registers */
#define NRF51_GPIOTE_INTENSET  REG32(NRF51_GPIOTE_BASE + 0x304)
#define NRF51_GPIOTE_INTENCLR  REG32(NRF51_GPIOTE_BASE + 0x308)
#define NRF51_GPIOTE_CONFIG(n) REG32(NRF51_GPIOTE_BASE + 0x510 + ((n) * 4))
#define NRF51_GPIOTE_POWER     REG32(NRF51_GPIOTE_BASE + 0xFFC)

/* Number of IN events */
#define NRF51_GPIOTE_IN_COUNT  4

/* Bits */
/* For GPIOTE.INTEN */
#define NRF51_GPIOTE_IN_BIT(n) (n)
#define NRF51_GPIOTE_PORT_BIT  31
/* For GPIOTE.CONFIG */
#define NRF51_GPIOTE_MODE_DISABLED     (0<<0)
#define NRF51_GPIOTE_MODE_EVENT        (1<<0)
#define NRF51_GPIOTE_MODE_TASK         (3<<0)
#define NRF51_GPIOTE_PSEL_POS          (8)
#define NRF51_GPIOTE_POLARITY_LOTOHI   (1<<16)
#define NRF51_GPIOTE_POLARITY_HITOLO   (2<<16)
#define NRF51_GPIOTE_POLARITY_TOGGLE   (3<<16)
#define NRF51_GPIOTE_OUTINIT_LOW       (0<<20)
#define NRF51_GPIOTE_OUTINIT_HIGH      (1<<20)

/*
 *  Timer / Counter
 */
#define NRF51_TIMER0_BASE   0x40008000
/* Tasks */
#define NRF51_TIMER0_START  REG32(NRF51_TIMER0_BASE + 0x000)
#define NRF51_TIMER0_STOP   REG32(NRF51_TIMER0_BASE + 0x004)
#define NRF51_TIMER0_COUNT  REG32(NRF51_TIMER0_BASE + 0x008)
#define NRF51_TIMER0_CLEAR  REG32(NRF51_TIMER0_BASE + 0x00C)
#define NRF51_TIMER0_CAPTURE0  REG32(NRF51_TIMER0_BASE + 0x040)
#define NRF51_TIMER0_CAPTURE1  REG32(NRF51_TIMER0_BASE + 0x044)
#define NRF51_TIMER0_CAPTURE2  REG32(NRF51_TIMER0_BASE + 0x048)
#define NRF51_TIMER0_CAPTURE3  REG32(NRF51_TIMER0_BASE + 0x04C)
/* Events */
#define NRF51_TIMER0_COMPARE0  REG32(NRF51_TIMER0_BASE + 0x140)
#define NRF51_TIMER0_COMPARE1  REG32(NRF51_TIMER0_BASE + 0x144)
#define NRF51_TIMER0_COMPARE2  REG32(NRF51_TIMER0_BASE + 0x148)
#define NRF51_TIMER0_COMPARE3  REG32(NRF51_TIMER0_BASE + 0x14C)
/* Registers */
#define NRF51_TIMER0_SHORTCUT  REG32(NRF51_TIMER0_BASE + 0x200)
#define NRF51_TIMER0_INTENSET  REG32(NRF51_TIMER0_BASE + 0x304)
#define NRF51_TIMER0_INTENCLR  REG32(NRF51_TIMER0_BASE + 0x308)
#define NRF51_TIMER0_MODE      REG32(NRF51_TIMER0_BASE + 0x504)
#define NRF51_TIMER0_BITMODE   REG32(NRF51_TIMER0_BASE + 0x508)
#define NRF51_TIMER0_PRESCALER REG32(NRF51_TIMER0_BASE + 0x510)
#define NRF51_TIMER0_CC0       REG32(NRF51_TIMER0_BASE + 0x540)
#define NRF51_TIMER0_CC1       REG32(NRF51_TIMER0_BASE + 0x544)
#define NRF51_TIMER0_CC2       REG32(NRF51_TIMER0_BASE + 0x548)
#define NRF51_TIMER0_CC3       REG32(NRF51_TIMER0_BASE + 0x54C)
/* For Timer.INTEN bits */
#define NRF51_TIMER_COMPARE0_BIT  ((0x140 - 0x100) / 4)
#define NRF51_TIMER_COMPARE1_BIT  ((0x144 - 0x100) / 4)
#define NRF51_TIMER_COMPARE2_BIT  ((0x148 - 0x100) / 4)
#define NRF51_TIMER_COMPARE3_BIT  ((0x14C - 0x100) / 4)
/* For Timer Shortcuts */
#define NRF51_TIMER_COMPARE0_CLEAR  (1 << 0)
#define NRF51_TIMER_COMPARE1_CLEAR  (1 << 1)
#define NRF51_TIMER_COMPARE2_CLEAR  (1 << 2)
#define NRF51_TIMER_COMPARE3_CLEAR  (1 << 3)
#define NRF51_TIMER_COMPARE0_STOP   (1 << 8)
#define NRF51_TIMER_COMPARE1_STOP   (1 << 9)
#define NRF51_TIMER_COMPARE2_STOP   (1 << 10)
#define NRF51_TIMER_COMPARE3_STOP   (1 << 11)
/* Timer Mode (NRF51_TIMER0_MODE) */
#define NRF51_TIMER0_MODE_TIMER   0  /* reset default */
#define NRF51_TIMER0_MODE_COUNTER 0
/* Prescaler */
#define NRF51_TIMER0_PRESCALER_MASK (0xf)  /* range: 0-9, reset default: 4 */
/* Bit length (NRF51_TIMER0_BITMODE) */
#define NRF51_TIMER0_BITMODE_16  0  /* reset default */
#define NRF51_TIMER0_BITMODE_8   1
#define NRF51_TIMER0_BITMODE_24  2
#define NRF51_TIMER0_BITMODE_32  3


/*
 *  GPIO
 */
#define NRF51_GPIO_BASE     0x50000000
#define NRF51_GPIO0_BASE    (NRF51_GPIO_BASE + 0x500)
#define NRF51_GPIO0_OUT     REG32(NRF51_GPIO0_BASE + 0x004)
#define NRF51_GPIO0_OUTSET  REG32(NRF51_GPIO0_BASE + 0x008)
#define NRF51_GPIO0_OUTCLR  REG32(NRF51_GPIO0_BASE + 0x00C)
#define NRF51_GPIO0_IN      REG32(NRF51_GPIO0_BASE + 0x010)
#define NRF51_GPIO0_DIR     REG32(NRF51_GPIO0_BASE + 0x014)  /* 1 for output */
#define NRF51_GPIO0_DIRSET  REG32(NRF51_GPIO0_BASE + 0x018)
#define NRF51_GPIO0_DIRCLR  REG32(NRF51_GPIO0_BASE + 0x01C)
#define NRF51_PIN_BASE      (NRF51_GPIO_BASE + 0x700)
#define NRF51_PIN_CNF(n)    REG32(NRF51_PIN_BASE + ((n) * 4))
#define GPIO_0              NRF51_GPIO0_BASE

#define NRF51_PIN_CNF_DIR_INPUT        (0)
#define NRF51_PIN_CNF_DIR_OUTPUT       (1)
#define NRF51_PIN_CNF_INPUT_CONNECT    (0<<1)
#define NRF51_PIN_CNF_INPUT_DISCONNECT (1<<1)
#define NRF51_PIN_CNF_PULL_DISABLED    (0<<2)
#define NRF51_PIN_CNF_PULLDOWN         (1<<2)
#define NRF51_PIN_CNF_PULLUP           (3<<2)
/*
 * Logic levels 0 and 1, strengths S=Standard, H=High D=Disconnect
 * for example, S0D1 = Standard drive 0, disconnect on 1
 */
#define NRF51_PIN_CNF_DRIVE_S0S1       (0<<8)
#define NRF51_PIN_CNF_DRIVE_H0S1       (1<<8)
#define NRF51_PIN_CNF_DRIVE_S0H1       (2<<8)
#define NRF51_PIN_CNF_DRIVE_H0H1       (3<<8)
#define NRF51_PIN_CNF_DRIVE_D0S1       (4<<8)
#define NRF51_PIN_CNF_DRIVE_D0H1       (5<<8)
#define NRF51_PIN_CNF_DRIVE_S0D1       (6<<8)
#define NRF51_PIN_CNF_DRIVE_H0D1       (7<<8)

#define NRF51_PIN_CNF_SENSE_DISABLED   (0<<16)
#define NRF51_PIN_CNF_SENSE_HIGH       (2<<16)
#define NRF51_PIN_CNF_SENSE_LOW        (3<<16)

#define DUMMY_GPIO_BANK     GPIO_0  /* for UNIMPLEMENTED() macro */

#define NRF51_PPI_BASE                 0x4001F000
#define NRF51_PPI_CHEN                 REG32(NRF51_PPI_BASE + 0x500)
#define NRF51_PPI_CHENSET              REG32(NRF51_PPI_BASE + 0x504)
#define NRF51_PPI_CHENCLR              REG32(NRF51_PPI_BASE + 0x508)
#define NRF51_PPI_EEP(channel)         REG32(NRF51_PPI_BASE + 0x510 + channel*8)
#define NRF51_PPI_TEP(channel)         REG32(NRF51_PPI_BASE + 0x514 + channel*8)
#define NRF51_PPI_CHG(group)           REG32(NRF51_PPI_BASE + 0x800 + group*4)

/* These will be defined in their respective functions if/when they are used. */
#define NRF51_SPI0_BASE       0x40003000
#define NRF51_SPI0_PSELSCK    REG32(NRF51_SPI0_BASE + 0x508)
#define NRF51_SPI0_PSELMOSI   REG32(NRF51_SPI0_BASE + 0x50C)
#define NRF51_SPI0_PSELMISO   REG32(NRF51_SPI0_BASE + 0x510)
#define NRF51_SPI1_BASE       0x40004000
#define NRF51_SPI1_PSELSCK    REG32(NRF51_SPI1_BASE + 0x508)
#define NRF51_SPI1_PSELMOSI   REG32(NRF51_SPI1_BASE + 0x50C)
#define NRF51_SPI1_PSELMISO   REG32(NRF51_SPI1_BASE + 0x510)
#define NRF51_SPIS1_BASE      0x40004000
#define NRF51_SPIS1_PSELSCK   REG32(NRF51_SPIS1_BASE + 0x508)
#define NRF51_SPIS1_PSELMISO  REG32(NRF51_SPIS1_BASE + 0x50C)
#define NRF51_SPIS1_PSELMOSI  REG32(NRF51_SPIS1_BASE + 0x510)
#define NRF51_SPIS1_PSELCSN   REG32(NRF51_SPIS1_BASE + 0x514)
#define NRF51_QDEC_BASE       0x40012000
#define NRF51_QDEC_PSELLED    REG32(NRF51_QDEC_BASE + 0x51C)
#define NRF51_QDEC_PSELA      REG32(NRF51_QDEC_BASE + 0x520)
#define NRF51_QDEC_PSELB      REG32(NRF51_QDEC_BASE + 0x524)
#define NRF51_LPCOMP_BASE     0x40013000
#define NRF51_LPCOMP_PSEL     REG32(NRF51_LPCOMP_BASE + 0x504)

#endif /* __CROS_EC_REGISTERS_H */

