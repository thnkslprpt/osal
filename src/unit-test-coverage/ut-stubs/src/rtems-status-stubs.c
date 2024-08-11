// #include "OCS_rtems.h"
#include "OCS_rtems_status.h"
#include "common_types.h"
#include "OCS_rtems.h"
#include "utstubs.h"

const char *OCS_rtems_status_text(OCS_rtems_status_code code)
{
    int32 Status;
    Status = UT_DEFAULT_IMPL(OCS_rtems_status_text);

    if (Status == 0)
    {
        /* "nominal" response */
        return 0;
    }

    return (char *)0;
}
