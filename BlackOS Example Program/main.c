#include <stdint.h>
#include <string.h>

#include "system_call.h"

// This is a test application for the CortexOS

static char program_info[100]	= "\n- - - - - - - - - - - - - - - - - -\nExample application\n- - - - - - - - - - - - - - - - - -\n";
static char test_print[30]		= "Hello World!\n";


int main(void)
{
	system_call_serial_print(program_info);
	
	while (1)
	{
		system_call_delay(2000);
		system_call_serial_print(test_print);
	}
}
