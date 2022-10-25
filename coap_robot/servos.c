#include <stdio.h>

#include "msg.h"
#include "test_utils/expect.h"
#include "servo_params.h"
#include "kernel_defines.h"

#define SERVO_NUMOF ARRAY_SIZE(servo_params)

#include "robot.h"

servo_t servos[SERVO_NUMOF];

void servos_init(void)
{
    for (unsigned i = 0; i < SERVO_NUMOF; i++) {
        expect(0 == servo_init(&servos[i], &servo_params[i]));
    }
}
