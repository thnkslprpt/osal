/************************************************************************
 * NASA Docket No. GSC-18,719-1, and identified as “core Flight System: Bootes”
 *
 * Copyright (c) 2020 United States Government as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 * All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License. You may obtain
 * a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ************************************************************************/

/*================================================================================*
** File:  ut_ostimer_test.c
** Owner: Tam Ngo
** Date:  May 2013
**================================================================================*/

/*--------------------------------------------------------------------------------*
** Includes
**--------------------------------------------------------------------------------*/

#include "ut_ostimer_test.h"

/*--------------------------------------------------------------------------------*
** Macros
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Data types
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** External global variables
**--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*
** Global variables
**--------------------------------------------------------------------------------*/

const char *g_timerNames[UT_OS_TIMER_LIST_LEN];
char        g_longTimerName[UT_OS_NAME_BUFF_SIZE];

volatile UT_TimerGlobal_t g_timerGlobal;

int deltatimes[25];

/*--------------------------------------------------------------------------------*
** Local function prototypes
**--------------------------------------------------------------------------------*/

void UT_os_timercallback(osal_id_t timerId);

void UT_os_init_timer_misc(void);
void UT_os_setup_timercreate_test(void);
void UT_os_setup_timerdelete_test(void);
void UT_os_setup_timergetidbyname_test(void);
void UT_os_setup_timergetinfo_test(void);
void UT_os_setup_timerset_test(void);

/*--------------------------------------------------------------------------------*
** Local function definitions
**--------------------------------------------------------------------------------*/

void UT_os_timercallback(osal_id_t timerId)
{
    OS_time_t currTime;
    int64     currIntervalTime;

    if (OS_ObjectIdEqual(timerId, g_timerGlobal.timerId) && g_timerGlobal.state != UT_TimerState_FINISHED)
    {
        OS_GetLocalTime(&currTime);

        if (g_timerGlobal.state == UT_TimerState_INIT)
        {
            /* initialization mode, first tick after a new test case starts */
            g_timerGlobal.callbackCount = 0;
            g_timerGlobal.status        = 0;

            g_timerGlobal.minDiff = INT32_MAX;
            g_timerGlobal.maxDiff = INT32_MIN;

            g_timerGlobal.startTime  = currTime;
            g_timerGlobal.finishTime = currTime;
            g_timerGlobal.state      = UT_TimerState_ACTIVE;
        }
        else
        {
            /* normal mode (actively monitoring) */
            currIntervalTime = OS_TimeGetTotalMicroseconds(OS_TimeSubtract(currTime, g_timerGlobal.finishTime));

            if (currIntervalTime < g_timerGlobal.minDiff)
            {
                g_timerGlobal.minDiff = currIntervalTime;
            }
            if (currIntervalTime > g_timerGlobal.maxDiff)
            {
                g_timerGlobal.maxDiff = currIntervalTime;
            }

            g_timerGlobal.finishTime = currTime;

            if (g_timerGlobal.callbackCount < 25)
            {
                deltatimes[g_timerGlobal.callbackCount] = currIntervalTime;
            }

            ++g_timerGlobal.callbackCount;

            if (g_timerGlobal.callbackCount >= g_timerGlobal.callbackMax)
            {
                g_timerGlobal.state = UT_TimerState_FINISHED;
            }
        }
    }
}

/*--------------------------------------------------------------------------------*/

void UT_os_init_timer_misc(void)
{
    memset(g_longTimerName, 'Y', sizeof(g_longTimerName));
    g_longTimerName[sizeof(g_longTimerName) - 1] = '\0';
}

/*--------------------------------------------------------------------------------*/

void UT_os_setup_timercreate_test(void)
{
    memset(g_longTimerName, 'Y', sizeof(g_longTimerName));
    g_longTimerName[sizeof(g_longTimerName) - 1] = '\0';

    g_timerNames[0] = "Create_NotImpl";
    g_timerNames[1] = "Create_NullPtr";
    g_timerNames[2] = "Create_LongName";
    g_timerNames[3] = "Create_DuplName";
    g_timerNames[4] = "Create_Full";
    g_timerNames[5] = "Create_InvArg";
    g_timerNames[6] = "Create_UnAvail";
    g_timerNames[7] = "Create_Nominal";
}

/*--------------------------------------------------------------------------------*/

void UT_os_setup_timerdelete_test(void)
{
    g_timerNames[0] = "Delete_NotImpl";
    g_timerNames[1] = "Delete_InvArg";
    g_timerNames[2] = "Delete_IntErr";
    g_timerNames[3] = "Delete_Nominal";
}

/*--------------------------------------------------------------------------------*/

void UT_os_setup_timergetidbyname_test(void)
{
    g_timerNames[0] = "GetId_NotImpl";
    g_timerNames[1] = "GetId_NullPtr";
    g_timerNames[2] = "GetId_LongName";
    g_timerNames[3] = "GetId_NotFound";
    g_timerNames[4] = "GetId_Nominal";
}

/*--------------------------------------------------------------------------------*/

void UT_os_setup_timergetinfo_test(void)
{
    g_timerNames[0] = "GetInfo_NotImpl";
    g_timerNames[1] = "GetInfo_NullPtr";
    g_timerNames[2] = "GetInfo_InvArg";
    g_timerNames[3] = "GetInfo_Nominal";
}

/*--------------------------------------------------------------------------------*/

void UT_os_setup_timerset_test(void)
{
    g_timerNames[0] = "Set_NotImpl";
    g_timerNames[1] = "Set_InvArg";
    g_timerNames[2] = "Set_IntErr";
    g_timerNames[3] = "Set_ShortIntv";
    g_timerNames[4] = "Set_Nominal";
}

/*--------------------------------------------------------------------------------*
** Main
**--------------------------------------------------------------------------------*/

void UtTest_Setup(void)
{
    if (OS_API_Init() != OS_SUCCESS)
    {
        UtAssert_Abort("OS_API_Init() failed");
    }

    /* the test should call OS_API_Teardown() before exiting */
    UtTest_AddTeardown(OS_API_Teardown, "Cleanup");

    UT_os_init_timer_misc();

    UtTest_Add(UT_os_timercreate_test, UT_os_setup_timercreate_test, NULL, "OS_TimerCreate");
    UtTest_Add(UT_os_timerdelete_test, UT_os_setup_timerdelete_test, NULL, "OS_TimerDelete");
    UtTest_Add(UT_os_timergetidbyname_test, UT_os_setup_timergetidbyname_test, NULL, "OS_TimerGetIdByName");
    UtTest_Add(UT_os_timergetinfo_test, UT_os_setup_timergetinfo_test, NULL, "OS_TimerGetInfo");
    UtTest_Add(UT_os_timerset_test, UT_os_setup_timerset_test, NULL, "OS_TimerSet");

    /* the reconfig test only works on POSIX */
#ifdef _POSIX_OS_
    UtTest_Add(UT_os_timerreconf_test, NULL, NULL, "TimerReconfig");
#endif
}

/*================================================================================*
** End of File: ut_ostimer_test.c
**================================================================================*/
