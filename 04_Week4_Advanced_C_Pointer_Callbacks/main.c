#include <stdio.h>

/* --- 1. Function Pointer & Callbacks Section --- */

// Definition of a function pointer type for notification callbacks
typedef void (*NotificationCallback_t)(void);

// Simulation of a Driver (like UART) that uses Callbacks to notify upper layers of event completion
void UART_TransmitAsync(const char *data, NotificationCallback_t cb) {
    printf("[MCAL - UART]: Transmitting payload: \"%s\"\n", data);
    printf("[MCAL - UART]: Transmission completed successfully.\n");

    // Ensure the pointer is not NULL before execution to avoid Segmentation Fault
    if (cb != NULL) {
        cb(); // Execute the Callback
    }
}

// Function belonging to the Application layer that will be called via the Callback
void App_OnTransmissionComplete(void) {
    printf("[Application]: Callback received! Data successfully sent to hardware.\n\n");
}


/* --- 2. Jump Tables & Array of Function Pointers Section --- */

// Definition of system modes as an Enum
typedef enum {
    MODE_INIT = 0,
    MODE_NORMAL,
    MODE_SLEEP,
    MODE_ERROR,
    MODE_MAX_MODES
} SystemMode_t;

// Functions for controlling different hardware states
void System_Init(void) {
    printf("[HW Action]: Initializing system clocks, GPIOs, and peripherals...\n");
}

void System_Normal(void) {
    printf("[HW Action]: Running normal execution loop. Monitoring sensors...\n");
}

void System_Sleep(void) {
    printf("[HW Action]: Disabling non-critical modules. Entering low-power mode...\n");
}

void System_Error(void) {
    printf("[HW Action]: Critical fault detected! Executing emergency recovery...\n");
}


int main(void) {
    printf("==================================================\n");
    printf("     EMBEDDED-C-JOURNEY: WEEK 4 ADVANCED CONCEPTS\n");
    printf("==================================================\n\n");

    // --- Part 1: Testing Function Pointers & Callbacks ---
    printf("--- [1] Testing Function Pointers & Callbacks ---\n\n");
    UART_TransmitAsync("Hello Automotive Embedded Systems!", App_OnTransmissionComplete);


    // --- Part 2: Testing Jump Tables (Array of Function Pointers) ---
    printf("--- [2] Testing Jump Tables for State Management ---\n\n");

    // Creating a Jump Table (Array of Function Pointers) for different system modes
    void (*JumpTable[MODE_MAX_MODES])(void) = {
        System_Init,
        System_Normal,
        System_Sleep,
        System_Error
    };

    // Simulation of changing system modes and executing them dynamically with optimal performance O(1)
    SystemMode_t currentMode = MODE_INIT;
    
    printf("-> Setting Mode to INIT:\n");
    JumpTable[currentMode]();

    printf("\n-> Setting Mode to NORMAL:\n");
    currentMode = MODE_NORMAL;
    JumpTable[currentMode]();

    printf("\n-> Setting Mode to SLEEP:\n");
    currentMode = MODE_SLEEP;
    JumpTable[currentMode]();

    printf("\n==================================================\n");
    printf("         WEEK 4 DEMO SUCCESSFULLY COMPLETED       \n");
    printf("==================================================\n");

    return 0;
}