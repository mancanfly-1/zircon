// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <ddk/binding.h>
#include <ddk/debug.h>
#include <ddk/platform-defs.h>

#include <zircon/types.h>

extern zx_status_t mt8167_gpio_bind(void* ctx, zx_device_t* parent);

static zx_driver_ops_t mt8167_gpio_driver_ops = {
    .version = DRIVER_OPS_VERSION,
    .bind = mt8167_gpio_bind,
};

ZIRCON_DRIVER_BEGIN(mt8167_gpio, mt8167_gpio_driver_ops, "zircon", "0.1", 4)
    BI_ABORT_IF(NE, BIND_PROTOCOL, ZX_PROTOCOL_PLATFORM_DEV),
    BI_ABORT_IF(NE, BIND_PLATFORM_DEV_VID, PDEV_VID_MEDIATEK),
    BI_ABORT_IF(NE, BIND_PLATFORM_DEV_PID, PDEV_PID_MEDIATEK_8167S_REF),
    BI_MATCH_IF(EQ, BIND_PLATFORM_DEV_DID, PDEV_DID_MEDIATEK_GPIO),
ZIRCON_DRIVER_END(mt8167_gpio)
