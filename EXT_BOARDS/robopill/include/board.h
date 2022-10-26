/*
 * Copyright (C) 2022 Otto-von-Guericke-Universität Magdeburg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_robopill
 *
 * @{
 *
 * @file
 * @brief       Peripheral MCU configuration for the robopill board
 *
 * @author      Marian Buschsieweke <marian.buschsieweke@ovgu.de>
 */

#ifndef BOARD_H
#define BOARD_H

#include "board_common.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SERVO_PARAMS \
    { \
        .pwm        = &servo_pwm_params[0], \
        .min_us     = 900, \
        .max_us     = 2100, \
        .pwm_chan   = 0, \
    }, \
    { \
        .pwm        = &servo_pwm_params[0], \
        .min_us     = 900, \
        .max_us     = 2100, \
        .pwm_chan   = 1, \
    }, \
    { \
        .pwm        = &servo_pwm_params[0], \
        .min_us     = 900, \
        .max_us     = 2100, \
        .pwm_chan   = 2, \
    }, \
    { \
        .pwm        = &servo_pwm_params[0], \
        .min_us     = 900, \
        .max_us     = 2100, \
        .pwm_chan   = 3, \
    },

#define NRF24L01P_NG_PARAM_CS               GPIO_PIN(PORT_B, 12)
#define NRF24L01P_NG_PARAM_CE               GPIO_PIN(PORT_C, 14)
#define NRF24L01P_NG_PARAM_IRQ              GPIO_PIN(PORT_A, 15)
#define NRF24L01P_NG_PARAM_SPI_CLK          SPI_CLK_1MHZ

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H */
/** @} */
