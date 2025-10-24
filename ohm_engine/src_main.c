//	src_main.c by Jaidev Bormann


#include "win_base.h"
#include "win_ohmdef.h"


int main(void) 
{

	struct ohm_window window	= { 0 };
	window.style			= OHMDEF_WIN_STYLE;
	
	window.class_ex_title		= OHMDEF_WIN_CLASS_TITLE;
	window.title			= OHMDEF_WIN_TITLE;

	window.width			= OHMDEF_WIN_WIDTH;
	window.height			= OHMDEF_WIN_HEIGHT;
	window.x			= OHMDEF_WIN_X;
	window.y			= OHMDEF_WIN_Y;

	ohm_window_init(&window);


	while (window.is_running) 
	{
	
		ohm_window_pump(&window, 0, 0);
	



		
	}


	ohm_window_free(&window);


	return 0;
}