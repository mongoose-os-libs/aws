/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

/*
 * View this file on GitHub:
 * [mgos_aws_greengrass.h](https://github.com/mongoose-os-libs/aws/blob/master/src/mgos_aws_greengrass.h)
 */

#ifndef CS_MOS_LIBS_AWS_SRC_MGOS_AWS_GREENGRASS_H_
#define CS_MOS_LIBS_AWS_SRC_MGOS_AWS_GREENGRASS_H_

#include <mgos_net.h>

#include "mgos_aws.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if MG_ENABLE_SSL

void aws_gg_net_ready(enum mgos_net_event ev,
                      const struct mgos_net_event_data *ev_data, void *arg);
void aws_gg_reconnect(void);

#endif /* MG_ENABLE_SSL */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CS_MOS_LIBS_AWS_SRC_MGOS_AWS_GREENGRASS_H_ */
