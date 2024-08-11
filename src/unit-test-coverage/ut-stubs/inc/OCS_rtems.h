#ifndef OCS_RTEMS_H
#define OCS_RTEMS_H

#include "OCS_basetypes.h"
// #include "OCS_rtems_options.h"
// #include "OCS_rtems_types.h"
#include "common_types.h"

typedef uint32 OCS_rtems_task_priority;
typedef uint32 OCS_rtems_id;
typedef uint32 OCS_rtems_name;
typedef uint32 OCS_rtems_attribute;

struct OCS_rtems_bsdnet_ifconfig
{
    char *name;
    int (*attach)(struct OCS_rtems_bsdnet_ifconfig *conf, int attaching);
    struct OCS_rtems_bsdnet_ifconfig *next;
    char                             *ip_address;
    char                             *ip_netmask;
    void                             *hardware_address;
};

struct OCS_rtems_bsdnet_config
{
    struct OCS_rtems_bsdnet_ifconfig *ifconfig;
    void (*bootp)(void);
};

typedef enum
{
    OCS_RTEMS_SUCCESSFUL  = 0,
    OCS_RTEMS_TIMEOUT     = 6,
    OCS_RTEMS_UNSATISFIED = 13
} OCS_rtems_status_code;


#endif
