
/* PSP coverage stub replacement for moduleLib.h */
#ifndef OVERRIDE_SEM_H
#define OVERRIDE_SEM_H

#include "OCS_rtems.h"
#include "OCS_sem.h"
#include <rtems.h>

#define rtems_semaphore_create OCS_rtems_semaphore_create
#define rtems_semaphore_delete OCS_rtems_semaphore_delete
#define rtems_semaphore_release OCS_rtems_semaphore_release
#define rtems_semaphore_flush OCS_rtems_semaphore_flush
#define rtems_semaphore_obtain OCS_rtems_semaphore_obtain

#endif
