#ifndef ROBOT_H
#define ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "servo.h"

extern servo_t servos[4];

void server_init(void);

void servos_init(void);


#ifdef __cplusplus
}
#endif

#endif /* ROBOT_H */
/** @} */
