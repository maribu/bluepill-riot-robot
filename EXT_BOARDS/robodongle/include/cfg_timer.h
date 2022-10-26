#ifndef CFG_TIMER_H
#define CFG_TIMER_H

#include "periph_cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

static const timer_conf_t timer_config[] = {
    {
        .dev      = NRF_TIMER1,
        .channels = 3,
        .bitmode  = TIMER_BITMODE_BITMODE_32Bit,
        .irqn     = TIMER1_IRQn
    },
    {
        .dev      = NRF_TIMER2,
        .channels = 3,
        .bitmode  = TIMER_BITMODE_BITMODE_08Bit,
        .irqn     = TIMER2_IRQn
    },
    {
        .dev      = NRF_TIMER3,
        .channels = 3,
        .bitmode  = TIMER_BITMODE_BITMODE_08Bit,
        .irqn     = TIMER3_IRQn
    },
    {
        .dev      = NRF_TIMER4,
        .channels = 6,
        .bitmode  = TIMER_BITMODE_BITMODE_32Bit,
        .irqn     = TIMER4_IRQn
    }
};

#define TIMER_0_ISR         isr_timer1
#define TIMER_1_ISR         isr_timer2
#define TIMER_2_ISR         isr_timer3
#define TIMER_3_ISR         isr_timer4

#define TIMER_NUMOF         ARRAY_SIZE(timer_config)

#ifdef __cplusplus
}
#endif

#endif /* CFG_TIMER_H */
/** @} */
