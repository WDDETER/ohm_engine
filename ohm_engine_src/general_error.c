//	 general_error.c by Jaidev Bormann


#include <stdio.h>
#include "general_error.h"


#define FORMAT_FLAGS (FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS)


static void ohm_window_format(const DWORD error, const LPCVOID source);


int ohm_error(const void* data, const char* data_name)
{
	
	if (data == NULL) 
	{
	
		printf("[OHM-ERROR] %s has encountered an error!\n", data_name);
	
		
		return OHM_ERROR_NULL;

	}


	return OHM_ERROR_NONE;

}


DWORD ohm_window_error(const void* data)
{

	if (!data)
	{

		DWORD last_error = GetLastError();


		printf("[WIN-API] Error Code: %lu\n", last_error);
		ohm_window_format(last_error, NULL);


		return last_error;

	}


	return ERROR_SUCCESS;

}


static void ohm_window_format(const DWORD error, const LPCVOID source)
{

	LPWSTR message = NULL;


	DWORD char_count = FormatMessage
	(

		FORMAT_FLAGS, source, error, 0, message, 0, NULL

	);


	if (char_count > 0)	wprintf(L"[WIN-API] Error Message: %ls\n", message);
	if (message)		LocalFree(message);

}