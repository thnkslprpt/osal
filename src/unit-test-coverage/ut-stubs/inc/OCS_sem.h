#ifndef OCS_SEM_H
#define OCS_SEM_H

//#include "OCS_basetypes.h"
#include "OCS_rtems.h"
#include "OCS_rtems_options.h"
#include "OCS_rtems_types.h"
#include "common_types.h"

OCS_rtems_status_code OCS_rtems_semaphore_create(OCS_rtems_name name, uint32 count, OCS_rtems_attribute attribute_set,
                                                 OCS_rtems_task_priority priority_ceiling, OCS_rtems_id *id);

// rtems_semaphore_delete
OCS_rtems_status_code OCS_rtems_semaphore_delete(OCS_rtems_id id);

// rtems_semaphore_release
OCS_rtems_status_code OCS_rtems_semaphore_release(OCS_rtems_id id);

// rtems_semaphore_flush
OCS_rtems_status_code OCS_rtems_semaphore_flush(OCS_rtems_id id);

// rtems_semaphore_obtain
OCS_rtems_status_code OCS_rtems_semaphore_obtain(OCS_rtems_id id, OCS_rtems_option option_set, OCS_rtems_interval timeout);

#endif
