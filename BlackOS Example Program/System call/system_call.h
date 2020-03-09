#ifndef SYSTEM_CALL_H
#define SYSTEM_CALL_H

#include <stdint.h>

//--------------------------------------------------------------------------------------------------//

#define KERNEL_SERVICE_NOINLINE __attribute__((noinline))

//--------------------------------------------------------------------------------------------------//

void KERNEL_SERVICE_NOINLINE system_call_serial_print(char* data);

void KERNEL_SERVICE_NOINLINE system_call_delay(uint32_t ticks);

//--------------------------------------------------------------------------------------------------//

#endif