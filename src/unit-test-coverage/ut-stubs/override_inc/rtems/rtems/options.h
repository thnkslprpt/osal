#ifndef OVERRIDE_RTEMS_OPTIONS_H
#define OVERRIDE_RTEMS_OPTIONS_H

#include "OCS_rtems_options.h"

#define rtems_option OCS_rtems_option

#define RTEMS_NO_WAIT OCS_RTEMS_NO_WAIT
#define RTEMS_WAIT    OCS_RTEMS_WAIT

#endif
