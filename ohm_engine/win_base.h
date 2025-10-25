//	win_base.h by Jaidev Bormann


#ifndef _OHM_WINBASE_H
#define _OHM_WINBASE_H


#include <windows.h>
#include <windowsx.h>
#include <stdbool.h>


struct ohm_window 
{

	LPCWSTR		title, class_ex_title;
	int		width, height, x, y;


	bool		is_running;


	HWND		handle, parent_handle;
	HMENU		handle_menu;
	HINSTANCE	instance_handle;
	HDC		device_context_handle;


	WNDCLASSEX	class_ex;


	MSG		message;


	DWORD		style, style_ex;
	LPVOID		custom_data;

};


struct ohm_input 
{

	bool	keys[256], mouse_buttons[2];
	POINT	mouse_position;

};


extern struct ohm_input ohm_global_input;


void			ohm_window_init(struct ohm_window* window);
void			ohm_window_free(struct ohm_window* window);
LRESULT CALLBACK	ohm_window_proc(HWND handle, UINT message, WPARAM wide_param, LPARAM long_param);


static inline void ohm_window_pump(struct ohm_window* window, UINT message_filter_min, UINT message_filter_max)
{

	while (PeekMessageW(&window->message, NULL, message_filter_min, message_filter_max, PM_REMOVE)) 
	{
	
		if (window->message.message == WM_QUIT) window->is_running = false;


		TranslateMessage(&window->message);
		DispatchMessageW(&window->message);
	
	}

}


#endif