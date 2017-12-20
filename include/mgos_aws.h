/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

/*
 * AWS API.
 */

#ifndef CS_FW_SRC_MGOS_AWS_H_
#define CS_FW_SRC_MGOS_AWS_H_

#include <stdbool.h>

/* mqtt lib should be included */
#include "mgos_mqtt.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

bool mgos_aws_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_FW_SRC_MGOS_AWS_H_ */
