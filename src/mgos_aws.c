/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

#include "mgos_sys_config.h"
#include "mgos_aws.h"
#include "mgos_aws_greengrass.h"

const char *mgos_aws_get_thing_name(void) {
  if (mgos_sys_config_get_aws_thing_name() != NULL) {
    return mgos_sys_config_get_aws_thing_name();
  } else if (mgos_sys_config_get_device_id() != NULL) {
    return mgos_sys_config_get_device_id();
  }
  return NULL;
}

bool mgos_aws_init(void) {
  LOG(LL_INFO, ("AWS Greengrass enable (%d)",
                mgos_sys_config_get_aws_greengrass_enable()));

  if (mgos_sys_config_get_aws_greengrass_enable() &&
      !mgos_sys_config_get_mqtt_enable()) {
    mgos_mqtt_set_max_qos(0); /* TODO(lsm): remove when AWS GG supports QoS1 */
    mgos_net_add_event_handler(aws_gg_net_ready, NULL);
  }
  return true;
}
