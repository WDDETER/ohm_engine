//	win_base.c by Jaidev Bormann


#include "win_base.h"
#include "win_error.h"


struct ohm_input ohm_global_input = { 0 };


void ohm_window_init(struct ohm_window* window) 
{

	window->instance_handle = GetModuleHandleW(NULL);


	window->class_ex.cbSize		= sizeof(WNDCLASSEX);
	window->class_ex.hInstance	= window->instance_handle;
	window->class_ex.lpszClassName	= window->class_ex_title;
	window->class_ex.lpfnWndProc	= ohm_window_proc;
	RegisterClassExW(&window->class_ex);


	window->handle = CreateWindowExW
	(

		window->style_ex, window->class_ex.lpszClassName, window->title, window->style,
		window->x, window->y, window->width, window->height,
		window->parent_handle, window->handle_menu, window->instance_handle, window->custom_data

	);


	window->device_context_handle = GetDC(window->handle);


	ohm_window_error((const void*)window->class_ex.lpfnWndProc);
	ohm_window_error((const void*)window->handle);
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


LRESULT CALLBACK ohm_window_proc(HWND handle, UINT message, WPARAM wide_param, LPARAM long_param)
{
	switch (message)
	{

	case WM_KEYDOWN:	ohm_global_input.keys[wide_param] = true;	break;
	case WM_KEYUP:		ohm_global_input.keys[wide_param] = false;	break;

	case WM_LBUTTONDOWN:	ohm_global_input.mouse_buttons[0] = true;	break;
	case WM_LBUTTONUP:	ohm_global_input.mouse_buttons[0] = false;	break;
	case WM_RBUTTONDOWN:	ohm_global_input.mouse_buttons[1] = true;	break;
	case WM_RBUTTONUP:	ohm_global_input.mouse_buttons[1] = true;	break;

	case WM_MOUSEMOVE:

		ohm_global_input.mouse_position.x = GET_X_LPARAM(long_param);
		ohm_global_input.mouse_position.y = GET_Y_LPARAM(long_param);

		break;


	case WM_DESTROY:

		PostQuitMessage(0);
		
		return 0;


	default: return DefWindowProcW(handle, message, wide_param, long_param);
	
	}
}