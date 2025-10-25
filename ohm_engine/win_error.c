//	win_error.c by Jaidev Bormann


#include <stdio.h>
#include "win_error.h"


#define FORMAT_FLAGS (FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS)


void ohm_window_format_error(const DWORD error, const LPCVOID source)
{

	LPWSTR message = NULL;


	DWORD char_count = FormatMessage
	(

		FORMAT_FLAGS, source, error, 0, (LPWSTR)&message, 0, NULL

	);


	if (char_count > 0)	wprintf		(L"[WIN-API] Error Message: %ls\n", message);
	if (message)		LocalFree	(message);

}


DWORD ohm_window_error(const void* data)
{

	if (!data)
	{

		DWORD last_error = GetLastError();


		printf			("[WIN-API] Error Code: %lu\n", last_error);
		ohm_window_format_error	(last_error, NULL);


		return last_error;

	}


	return ERROR_SUCCESS;

}