//	general_error.h by Jaidev Bormann


#ifndef _OHM_GENERALERROR_H
#define _OHM_GENERALERROR_H


#include <windows.h>


#define OHM_ERROR_NONE 0
#define OHM_ERROR_NULL 1


int	ohm_error	(const void* data, const char* data_name);
DWORD	ohm_window_error(const void* data);


#endif