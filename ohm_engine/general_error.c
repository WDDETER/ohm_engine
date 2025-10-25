//	 general_error.c by Jaidev Bormann


#include <stdio.h>
#include "general_error.h"


int ohm_error(const void* data, const char* data_name)
{
	
	if (data == NULL)
	{
	
		printf("[OHM-ERROR] %s has encountered an error!\n", data_name);
	
		
		return OHM_ERROR_NULL;

	}


	return OHM_ERROR_NONE;

}