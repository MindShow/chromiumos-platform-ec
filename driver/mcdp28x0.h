/* Copyright (c) 2014 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Megachips DisplayPort to HDMI protocol converter / level shifter driver.
 */

#ifndef MCDP28X0_H
#define MCDP28X0_H

#include <util.h>

#define MCDP_OUTBUF_MAX 16
#define MCDP_INBUF_MAX 16

#define MCDP_CHIPID(chipid) ((chipid[0] << 8) | chipid[1])
#define MCDP_FAMILY(family) ((family[0] << 8) | family[1])

#define MCDP_CMD_GETINFO 0x40
#define MCDP_LEN_GETINFO 12

/* length byte + cmd byte + data len */
#define MCDP_RSP_LEN(len) (len + 2)

struct mcdp_version {
	uint8_t major;
	uint8_t minor;
	uint16_t build;
};

struct mcdp_info {
	uint8_t family[2];
	uint8_t chipid[2];
	struct mcdp_version irom;
	struct mcdp_version fw;
};

/**
 * Enable mcdp driver.
 */
void mcdp_enable(void);

/**
 * Disable mcdp driver.
 */
void mcdp_disable(void);

/**
 * get get information command from mcdp.
 *
 * @info pointer to mcdp_info structure
 * @return zero if success, error code otherwise.
 */
int mcdp_get_info(struct mcdp_info  *info);

#endif
