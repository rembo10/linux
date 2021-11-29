// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Device Tree support for Rockchip SoCs
 *
 * Copyright (c) 2013 MundoReader S.L.
 * Author: Heiko Stuebner <heiko@sntech.de>
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/of_clk.h>
#include <linux/of_platform.h>
#include <linux/irqchip.h>
#include <linux/clocksource.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>
#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/hardware/cache-l2x0.h>
#include "core.h"
#include "pm.h"

static void __init rockchip_timer_init(void)
{
	of_clk_init(NULL);
	timer_probe();
}

static void __init rockchip_dt_init(void)
{
	rockchip_suspend_init();
}

static const char * const rockchip_board_dt_compat[] = {
	"rockchip,rk2928",
	"rockchip,rk3066a",
	"rockchip,rk3066b",
	"rockchip,rk3188",
	"rockchip,rk3228",
	"rockchip,rk3288",
	"rockchip,rv1108",
	NULL,
};

DT_MACHINE_START(ROCKCHIP_DT, "Rockchip (Device Tree)")
	.l2c_aux_val	= 0,
	.l2c_aux_mask	= ~0,
	.init_time	= rockchip_timer_init,
	.dt_compat	= rockchip_board_dt_compat,
	.init_machine	= rockchip_dt_init,
MACHINE_END
