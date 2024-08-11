/* pull in the OSAL configuration */
#include "osconfig.h"
#include "ut-adaptor-binsem.h"

#include "os-rtems.h"
#include "os-impl-binsem.h"

void *const  UT_Ref_OS_impl_bin_sem_table      = OS_impl_bin_sem_table;
size_t const UT_Ref_OS_impl_bin_sem_table_SIZE = sizeof(OS_impl_bin_sem_table);

// const UT_EntryKey_t UT_StubKey_GenericSemTake = UT_KEY(OS_VxWorks_GenericSemTake);
// const UT_EntryKey_t UT_StubKey_GenericSemGive = UT_KEY(OS_VxWorks_GenericSemGive);

int32 UT_Call_OS_Rtems_BinSemAPI_Impl_Init(void)
{
    return OS_Rtems_BinSemAPI_Impl_Init();
}
