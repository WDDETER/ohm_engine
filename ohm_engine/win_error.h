//	win_error.h by Jaidev Bormann


#ifndef _OHM_WINERROR_H
#define _OHM_WINERROR_H


#include <windows.h>


DWORD	ohm_window_error	(const void* data);
void	ohm_window_format_error	(const DWORD error, const LPCVOID source);


#endif