#include "system_call.h"

//--------------------------------------------------------------------------------------------------//

// Service numbers
// Service 1 to 10 is reserved for the kernel
// Service 11-255 is free to use

typedef enum
{
	SERVICE_THREAD_DELAY = 1,
	SERVICE_SERIAL_PRINT = 10
} kernel_services;

// Macro for calling the SVC handler with the specified SVC number
#define KERNEL_SERVICE(svc_number) asm volatile ("svc %[arg]" : : [arg] "I" (svc_number))

//--------------------------------------------------------------------------------------------------//

// Implementation of the kernel services
// Note that service 0-10 should not be used since these
// provides kernel services

void KERNEL_SERVICE_NOINLINE system_call_serial_print(char* data)
{
	KERNEL_SERVICE(SERVICE_SERIAL_PRINT);
}

void KERNEL_SERVICE_NOINLINE system_call_delay(uint32_t ticks)
{
	KERNEL_SERVICE(SERVICE_THREAD_DELAY);
}

//--------------------------------------------------------------------------------------------------//