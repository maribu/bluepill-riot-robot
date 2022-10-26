#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fmt.h"
#include "kernel_defines.h"
#include "net/gcoap.h"
#include "net/utils.h"
#include "od.h"

#include "robot.h"

#define ENABLE_DEBUG 0
#include "debug.h"

static ssize_t _servo_handler(coap_pkt_t* pdu, uint8_t *buf, size_t len, coap_request_ctx_t *ctx);
static uint8_t servo_states[ARRAY_SIZE(servos)];

static const coap_resource_t _resources[] = {
    { "/arm/rotate", COAP_GET | COAP_POST | COAP_PUT, _servo_handler, &servos[0] },
    { "/arm/extend", COAP_GET | COAP_POST | COAP_PUT, _servo_handler, &servos[1] },
    { "/arm/lift", COAP_GET | COAP_POST | COAP_PUT, _servo_handler, &servos[2] },
    { "/arm/grab", COAP_GET | COAP_POST | COAP_PUT, _servo_handler, &servos[3] },
};

static gcoap_listener_t _listener = {
    &_resources[0],
    ARRAY_SIZE(_resources),
    GCOAP_SOCKET_TYPE_UNDEF,
    gcoap_encode_link,
    NULL,
    NULL
};

static ssize_t _servo_handler(coap_pkt_t* pdu, uint8_t *buf, size_t len, coap_request_ctx_t *ctx)
{
    servo_t *servo = coap_request_ctx_get_context(ctx);
    unsigned idx = index_of(servos, servo);

    unsigned method_flag = coap_method2flag(coap_get_code_detail(pdu));

    switch (method_flag) {
    case COAP_GET:
        gcoap_resp_init(pdu, buf, len, COAP_CODE_CONTENT);
        coap_opt_add_format(pdu, COAP_FORMAT_TEXT);
        size_t resp_len = coap_opt_finish(pdu, COAP_OPT_FINISH_PAYLOAD);

        /* write the response buffer with the request count value */
        resp_len += fmt_u16_dec((char *)pdu->payload, servo_states[idx]);
        return resp_len;

    case COAP_PUT:
        /* convert the payload to an integer and update the internal
           value */
        if (pdu->payload_len <= 3) {
            char payload[4] = { 0 };
            memcpy(payload, (char *)pdu->payload, pdu->payload_len);
            uint8_t pos = (uint8_t)strtoul(payload, NULL, 10);
            servo_states[idx] = pos;
            servo_set(servo, pos);
            return gcoap_response(pdu, buf, len, COAP_CODE_CHANGED);
        }
        else {
            return gcoap_response(pdu, buf, len, COAP_CODE_BAD_REQUEST);
        }

    case COAP_POST:
        /* convert the payload to an integer and update the internal
           value */
        if (pdu->payload_len <= 3) {
            char payload[4] = { 0 };
            memcpy(payload, (char *)pdu->payload, pdu->payload_len);
            int32_t offset = strtol(payload, NULL, 10);
            int32_t pos = servo_states[idx];
            pos += offset;
            if (pos < 0) {
                pos = 0;
            }
            if (pos > UINT8_MAX) {
                pos = UINT8_MAX;
            }
            servo_states[idx] = pos;
            servo_set(servo, pos);
            return gcoap_response(pdu, buf, len, COAP_CODE_CHANGED);
        }
        else {
            return gcoap_response(pdu, buf, len, COAP_CODE_BAD_REQUEST);
        }
    }

    return 0;
}

void server_init(void)
{
    gcoap_register_listener(&_listener);
}
