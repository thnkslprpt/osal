

/* PSP coverage stub replacement for moduleLib.h */
// #include <string.h>
// #include <stdlib.h>
#include "utstubs.h"

#include "OCS_sem.h"
#include "OCS_rtems.h"

OCS_rtems_status_code OCS_rtems_semaphore_create(OCS_rtems_name name, uint32 count, OCS_rtems_attribute attribute_set,
                                                 OCS_rtems_task_priority priority_ceiling, OCS_rtems_id *id)
{
    int Status = 0;
    Status     = UT_DEFAULT_IMPL(OCS_rtems_semaphore_create);

    return Status;
}

// rtems_semaphore_delete
OCS_rtems_status_code OCS_rtems_semaphore_delete(OCS_rtems_id id)
{
    int Status = 0;
    Status     = UT_DEFAULT_IMPL(OCS_rtems_semaphore_delete);

    return Status;
}

// rtems_semaphore_release
OCS_rtems_status_code OCS_rtems_semaphore_release(OCS_rtems_id id)
{
    int Status = 0;
    Status     = UT_DEFAULT_IMPL(OCS_rtems_semaphore_release);

    return Status;
}

// rtems_semaphore_flush
OCS_rtems_status_code OCS_rtems_semaphore_flush(OCS_rtems_id id)
{
    int Status = 0;
    Status     = UT_DEFAULT_IMPL(OCS_rtems_semaphore_flush);

    return Status;
}

// rtems_semaphore_obtain
OCS_rtems_status_code OCS_rtems_semaphore_obtain(OCS_rtems_id id, OCS_rtems_option option_set,
                                                 OCS_rtems_interval timeout)
{
    int Status = 0;
    Status     = UT_DEFAULT_IMPL(OCS_rtems_semaphore_obtain);

    return Status;
}
