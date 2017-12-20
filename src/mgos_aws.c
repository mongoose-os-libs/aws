/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

#include "mgos_aws.h"
#include "mgos_aws_greengrass.h"
#include "mgos_aws_shadow.h"
#include "mgos_event.h"
#include "mgos_sys_config.h"

const char *mgos_aws_get_thing_name(void) {
  if (mgos_sys_config_get_aws_thing_name() != NULL) {
    return mgos_sys_config_get_aws_thing_name();
  } else if (mgos_sys_config_get_device_id() != NULL) {
    return mgos_sys_config_get_device_id();
  }
  return NULL;
}

bool mgos_aws_init(void) {
  /*
   * If thing_name is set explicitly, persist expanded MAC placeholders in it
   */
  if (mgos_sys_config_get_aws_thing_name() != NULL) {
    char *thing_name = strdup(mgos_sys_config_get_aws_thing_name());
    mgos_expand_mac_address_placeholders(thing_name);
    mgos_sys_config_set_aws_thing_name(thing_name);
    free(thing_name);
  }

  LOG(LL_INFO, ("AWS Greengrass enable (%d)",
                mgos_sys_config_get_aws_greengrass_enable()));

  mgos_event_add_handler(MGOS_EVENT_INIT_DONE,
                         (mgos_event_handler_t) mgos_aws_shadow_init, NULL);

  if (mgos_sys_config_get_aws_greengrass_enable() &&
      !mgos_sys_config_get_mqtt_enable()) {
    mgos_net_add_event_handler(aws_gg_net_ready, NULL);
  }
  return true;
}
