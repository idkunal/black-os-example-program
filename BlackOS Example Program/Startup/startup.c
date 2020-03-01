#include "config.h"

#include <stdint.h>

extern uint32_t _end;

extern uint32_t _sgot;
extern uint32_t _egot;

extern uint32_t _sgot_plt;
extern uint32_t _egot_plt;

extern uint32_t __init_array_start;
extern uint32_t __init_array_end;

extern uint32_t __fini_array_start;
extern uint32_t __fini_array_end;

extern uint32_t __preinit_array_start;
extern uint32_t __preinit_array_end;


void application_startup(void);

int main(void);


typedef struct
{
	void*		application_end;
	
	void*		application_entry;
	
	void*		start_got;
	void*		end_got;
	
	void*		start_got_plt;
	void*		end_got_plt;
	
	uint32_t	stack_size;
	
	uint32_t	name_length;
	char		name[APPLICATION_MAX_NAME_LENGTH];
		
} application_info;


__attribute__ ((section(".info"))) const application_info app_info =
{
	.application_end		= (void *)(&_end),
	
	.application_entry		= (void *)application_startup,
	
	.start_got				= (void *)(&_sgot),
	.end_got				= (void *)(&_egot),
	
	.start_got_plt			= (void *)(&_sgot_plt),
	.end_got_plt			= (void *)(&_egot_plt),

	.stack_size				= APPLICATION_STACK_SIZE,

	.name_length			= APPLICATION_MAX_NAME_LENGTH,
	.name					= APPLICATION_NAME
};

void application_startup(void)
{
	main();
	
	// Call a service to request an exit
	
}
