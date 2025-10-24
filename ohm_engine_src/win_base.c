//	win_base.c by Jaidev Bormann


#include "win_base.h"
#include "general_error.h"


void ohm_window_init(struct ohm_window* window) 
{

	window->instance_handle = GetModuleHandleW(NULL);


	window->class_ex.cbSize		= sizeof(WNDCLASSEX);
	window->class_ex.hInstance	= window->instance_handle;
	window->class_ex.lpszClassName	= window->class_ex_title;
	window->class_ex.lpfnWndProc	= ohm_window_proc;

	ohm_window_error((const void*)window->class_ex.lpfnWndProc);

	RegisterClassEx(&window->class_ex);


	window->handle = CreateWindowExW
	(

		window->style_ex, window->class_ex.lpszClassName, window->title, window->style,
		window->x, window->y, window->width, window->height,
		window->parent_handle, window->handle_menu, window->instance_handle, window->custom_data

	);

	ohm_window_error((const void*)window->handle);


	window->device_context_handle = GetDC(window->handle);

	ohm_window_error((const void*)window->device_context_handle);


	window->is_running = true;

}


void ohm_window_free(struct ohm_window* window)
{

	if (window == NULL) return;


	DestroyWindow	(window->handle);
	UnregisterClassW(window->class_ex.lpszClassName, window->class_ex.hInstance);
	ReleaseDC	(window->handle, window->device_context_handle);

}


LRESULT CALLBACK ohm_window_proc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{

		case WM_DESTROY:

			PostQuitMessage(0);
			return 0;


		default:

			return DefWindowProc(hwnd, uMsg, wParam, lParam);
	
	}
}