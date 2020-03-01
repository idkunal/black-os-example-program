#include <stdint.h>
#include <string.h>

#define STACK_SIZE 500

void hello(volatile uint8_t* i)
{
	*i++;
}

#define KERNEL_SERVICE_NOINLINE __attribute__((noinline))

// Service numbers
// Service 1 to 10 is reserved for the kernel
// Service 11-255 is free to use

typedef enum
{
	SERVICE_THREAD_DELAY = 1,
	SERVICE_SERIAL_PRINT = 10
} kernel_services;

// Prototypes for the services that the kernel provide
void KERNEL_SERVICE_NOINLINE service_serial_print(char* data);

void KERNEL_SERVICE_NOINLINE service_thread_delay(uint32_t ticks);

// Macro for calling the SVC handler with the specified SVC number
#define KERNEL_SERVICE(svc_number) asm volatile ("svc %[arg]" : : [arg] "I" (svc_number))

//--------------------------------------------------------------------------------------------------//

// Implementation of the kernel services
// Note that service 0-10 should not be used since these
// provides kernel services

void KERNEL_SERVICE_NOINLINE service_serial_print(char* data)
{
	KERNEL_SERVICE(SERVICE_SERIAL_PRINT);
}

void KERNEL_SERVICE_NOINLINE service_thread_delay(uint32_t ticks)
{
	KERNEL_SERVICE(SERVICE_THREAD_DELAY);
}

char text_2[80] = "Hei dette er liten test for å se om linker scriptet funker\n";

typedef struct
{
	char data[30];
} yo;

static volatile yo var1;

int main(void)
{
	strcpy((char *)var1.data, "Heisann\n");
	while (1)
	{
		service_thread_delay(600);
		service_serial_print((char *)var1.data);
		service_thread_delay(200);
		service_serial_print(text_2);
	}
}
