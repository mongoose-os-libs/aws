/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

#include "mgos_sys_config.h"
#include "mgos_aws.h"
#include "mgos_aws_greengrass.h"

const char *mgos_aws_get_thing_name(void) {
  struct sys_config *cfg = get_cfg();

  if (cfg->aws.thing_name != NULL) {
    return cfg->aws.thing_name;
  } else if (cfg->device.id != NULL) {
    return cfg->device.id;
  }
  return NULL;
}

bool mgos_aws_init(void) {
  struct sys_config *cfg = get_cfg();
  struct sys_config_aws_greengrass *gcfg = &cfg->aws.greengrass;
  struct sys_config_mqtt *mcfg = &cfg->mqtt;

  LOG(LL_INFO, ("AWS Greengrass enable (%d)", gcfg->enable));

  if (gcfg->enable && !mcfg->enable) {
    mgos_mqtt_set_max_qos(0); /* TODO(lsm): remove when AWS GG supports QoS1 */
    mgos_net_add_event_handler(aws_gg_net_ready, NULL);
  }
  return true;
}
