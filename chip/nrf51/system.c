/* Copyright (c) 2014 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* System module for Chrome EC : hardware specific implementation */

#include "common.h"
#include "console.h"
#include "registers.h"
#include "system.h"

/* Console output macros */
#define CPUTS(outstr) cputs(CC_SYSTEM, outstr)
#define CPRINTS(format, args...) cprints(CC_SYSTEM, format, ## args)

const char *system_get_chip_vendor(void)
{
	return "nrf";
}

const char *system_get_chip_name(void)
{
	return "nrf51822";
}

const char *system_get_chip_revision(void)
{
	return "";
}

void system_hibernate(uint32_t seconds, uint32_t microseconds)
{
	/* Flush console before hibernating */
	cflush();

	/* chip specific standby mode */
	CPRINTS("TODO: implement %s()", __func__);
}


static void check_reset_cause(void)
{
	uint32_t flags = 0;
	uint32_t raw_cause = NRF51_POWER_RESETREAS;

	if (raw_cause & 0x00000001)
		flags |= RESET_FLAG_RESET_PIN;

	if (raw_cause & 0x00000002)
		flags |= RESET_FLAG_WATCHDOG;

	/*
	 * According to the data sheet, this bit is set by AIRCR.SYSRESETREQ.
	 * However, th reset from J-Link also sets this bit. This could mislead
	 * us.
	 */
	if (raw_cause & 0x00000004)
		flags |= RESET_FLAG_SOFT;

	if (raw_cause & 0x00070008)
		flags |= RESET_FLAG_OTHER;

	system_set_reset_flags(flags);

	/* clear it by writing 1's */
	NRF51_POWER_RESETREAS = raw_cause;
}


void system_reset(int flags)
{
	CPRINTS("TODO: implement %s(). Infinite loop.", __func__);
	while (1)
		;
}

int system_get_vbnvcontext(uint8_t *block)
{
	CPRINTS("TODO: implement %s()", __func__);
	return EC_ERROR_UNIMPLEMENTED;
}

int system_set_vbnvcontext(const uint8_t *block)
{
	CPRINTS("TODO: implement %s()", __func__);
	return EC_ERROR_UNIMPLEMENTED;
}

void system_pre_init(void)
{
	check_reset_cause();
}
