#ifndef OVERRIDE_RTEMS_H
#define OVERRIDE_RTEMS_H

#include "OCS_rtems.h"
#include "OCS_sem.h"
#include "rtems/sem.h"
#include "rtems/rtems/options.h"
#include "rtems/rtems/types.h"
#include "rtems/rtems/intr.h"
#include "rtems/rtems/attr.h"
#include "rtems/rtems/status.h"


#define rtems_task_priority OCS_rtems_task_priority
#define rtems_id            OCS_rtems_id
#define rtems_name          OCS_rtems_name

#define rtems_status_code OCS_rtems_status_code
#define RTEMS_SUCCESSFUL  OCS_RTEMS_SUCCESSFUL
#define RTEMS_TIMEOUT     OCS_RTEMS_TIMEOUT
#define RTEMS_UNSATISFIED OCS_RTEMS_UNSATISFIED

#define rtems_bsdnet_ifconfig  OCS_rtems_bsdnet_ifconfig
#define rtems_bsdnet_config    OCS_rtems_bsdnet_config

#endif
