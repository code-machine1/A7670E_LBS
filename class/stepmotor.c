#include "stepmotor.h"
#include "userconfig.h"

int stepmotor_Clock(uintptr_t wObjectAddr);
int stepmotor_Run(uintptr_t wObjectAddr);

// Define a global stepmotor base of type gmsi_base_t
static gmsi_base_t s_tStepmotorBase;

// Define and initialize a global stepmotor base configuration of type gmsi_base_cfg_t
gmsi_base_cfg_t s_tStepmotorBaseCfg = {
    .wId = STEPMOTOR,                        // Set the ID to STEPMOTOR
    .wParent = 0,                           // Set the parent to 0
    .FcnInterface = {
        .Clock = stepmotor_Clock,            // Set the Clock function to stepmotor_Clock
        .Run = stepmotor_Run,                // Set the Run function to stepmotor_Run
    },
};

gcoroutine_handle_t tGcoroutineStepmotorHandle = {
    .bIsRunning = false,
    .pfcn = NULL,
};

GMSI_MSG_ITEM_DECLARE(STEPMOTOR, StepmotorBuffer, 20);

uint8_t chStepmotorBufferTest[20] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14};
/**
 * Function: stepmotor_gcoroutine
 * ----------------------------
 * This function is a coroutine that handles different states of the stepmotor object. It receives 
 * a parameter, converts it to an stepmotor object, and uses a switch statement to handle different 
 * states. This function returns fsm_rt_on_going if it is still running, or fsm_rt_cpl if it has 
 * completed its task. Once the coroutine has completed its task, it will be removed from the 
 * coroutine list.
 *
 * Parameters: 
 * pvParam: The parameter to be converted to an stepmotor object.
 *
 * Returns: 
 * fsm_rt_on_going if the function is still running, or fsm_rt_cpl if the function has completed 
 * its task.
 */
fsm_rt_t stepmotor_gcoroutine(void *pvParam)
{
    static uint8_t s_eState = 0;
    fsm_rt_t tFsm = fsm_rt_on_going;
    stepmotor_t *ptThis = (stepmotor_t *)pvParam;

    // Check if ptThis is not NULL
    if (ptThis == NULL) {
        GLOG_PRINTF("Error: ptThis is NULL.\n");
        return fsm_rt_err;
    }

    switch(s_eState)
    {
        case 0:
            GLOG_PRINTF("get stepmotor event");
            s_eState++;
            break;
        case 1:
            GLOG_PRINTF("finish get stepmotor event handle");
            fsm_cpl();
            break;
        default:
            fsm_cpl();
        break;
    }
    fsm_on_going(); 
}

/**
 * Function: stepmotor_EventHandle
 * ----------------------------
 * This function handles the events for the stepmotor object. It checks for specific events and 
 * performs the corresponding actions. This function does not return a value, as its result is 
 * reflected in the state of the stepmotor object it operates on.
 *
 * Parameters: 
 * ptThis: The pointer to the stepmotor object.
 * wEvent: The events to be handled.
 *
 * Returns: 
 * None
 */
static void stepmotor_EventHandle(stepmotor_t *ptThis, uint32_t wEvent)
{
    GMSI_MSG_DECLARE(StepmotorTestBuffer, 20);
    // Check if ptThis is not NULL
    if (ptThis == NULL) {
        GLOG_PRINTF("ptThis is NULL.");
        return;
    }

    // Check if the event Event_SyncMissed is set
    if(wEvent & Event_SyncMissed)
    {
        GLOG_PRINTF("get event Event_SyncMissed");
    }

    // Check if the event Event_SyncButtonPushed is set
    if(wEvent & Event_SyncButtonPushed)
    {
        if(GMSI_SUCCESS != gcoroutine_Insert(&tGcoroutineStepmotorHandle, (void *)ptThis, stepmotor_gcoroutine))
        {
            GLOG_PRINTF("Error: gcoroutine_Insert failed.");
        }
    }

    // Check if the event Event_PacketReceived is set
    if(wEvent & Event_PacketReceived)
    {
        // Handle the event Event_PacketReceived
        GMSI_MSG_UPDATE(StepmotorTestBuffer, chStepmotorBufferTest, 20);
        GMSI_MSG_ITEM_UPDATE(StepmotorBuffer, GMSI_MSG_GET_BUFFER(StepmotorTestBuffer),   \
                                                GMSI_MSG_GET_LENGTH(StepmotorTestBuffer));
        gbase_MessagePost(EXAMPLE, GMSI_MSG_ITEM_GET_HANDLE(StepmotorBuffer));
    }
}

/**
 * Function: stepmotor_Run
 * ----------------------------
 * This function is mounted in the GMSI run function list and is called within a while(1) loop. 
 * It receives events and messages from other objects. When a corresponding event is triggered, 
 * it executes the appropriate coroutine. The function gets the stepmotor object from the given 
 * address, retrieves the events for the object, and handles these events. This function returns 
 * GMSI_SUCCESS if it runs successfully.
 *
 * Parameters: 
 * wObjectAddr: The address of the stepmotor object.
 *
 * Returns: 
 * GMSI_SUCCESS if the function runs successfully.
 */
int stepmotor_Run(uintptr_t wObjectAddr)
{
    int wRet = GMSI_SUCCESS;
    uint32_t wEvent;
    GMSI_MSG_DECLARE(StepmotorBufferGet, 20);
    // Get the stepmotor object from the given address
    stepmotor_t *ptThis = (stepmotor_t *)wObjectAddr;

    // Check if ptThis is not NULL
    if (ptThis == NULL) {
        GLOG_PRINTF("ptThis is NULL.");
        return GMSI_EFAIL;
    }

    // Get the events for the stepmotor object
    wEvent = gbase_EventPend(ptThis->ptBase);

    // If there are any events, handle them
    if(wEvent)
        stepmotor_EventHandle(ptThis, wEvent);
    
    if(gbase_MessagePend(ptThis->ptBase, GMSI_MSG_GET_HANDLE(StepmotorBufferGet)) > 0)
    {
        // Handle the message
        GLOG_PRINTF("get example message");
    }
    // Logic or state machine programs

    return wRet;
}

/**
 * Function: stepmotor_Clock
 * ----------------------------
 * This function is called in a 1ms interrupt. It gets the stepmotor object from the given address 
 * and performs operations on it. This function returns GMSI_SUCCESS if it runs successfully.
 *
 * Parameters: 
 * wObjectAddr: The address of the stepmotor object.
 *
 * Returns: 
 * GMSI_SUCCESS if the function runs successfully.
 */
int stepmotor_Clock(uintptr_t wObjectAddr)
{
    // Get the stepmotor object from the given address
    stepmotor_t *ptThis = (stepmotor_t *)wObjectAddr;

    int wRet = GMSI_SUCCESS;
    
    // Perform operations on ptThis

    return wRet;
}

/**
 * Function: stepmotor_Init
 * ----------------------------
 * This function initializes an stepmotor object. It converts the given addresses to pointers, 
 * checks if the pointers are not NULL, copies the configuration members to the object, initializes 
 * the hardware, and registers the object in the GMSI list.
 *
 * Parameters: 
 * wObjectAddr: The address of the stepmotor object.
 * wObjectCfgAddr: The address of the stepmotor configuration object.
 *
 * Returns: 
 * GMSI_SUCCESS if the function runs successfully, GMSI_EAGAIN if the object cannot be registered 
 * in the GMSI list, or GMSI_FAILURE if any of the pointers is NULL.
 */
int stepmotor_Init(uintptr_t wObjectAddr, uintptr_t wObjectCfgAddr)
{
    // Convert the given addresses to pointers
    stepmotor_t *ptThis = (stepmotor_t *)wObjectAddr;
    stepmotor_cfg_t *ptCfg = (stepmotor_cfg_t *)wObjectCfgAddr;

    // Check if the pointers are not NULL
    if (ptThis == NULL || ptCfg == NULL) {
        GLOG_PRINTF("Error: ptThis or ptCfg is NULL.");
        return GMSI_EFAIL;
    }

    /* Copy the configuration members to the object */
    GMSI_MSG_ITEM_INITIALISE_LIST(StepmotorBuffer);

    /* Initialize the hardware */

    // Register the object in the GMSI list
    ptThis->ptBase = &s_tStepmotorBase;
    if (ptThis->ptBase == NULL) {
        return GMSI_EAGAIN;
    } else {
        s_tStepmotorBaseCfg.wParent = wObjectAddr;
        return gbase_Init(ptThis->ptBase, &s_tStepmotorBaseCfg);
    }
}