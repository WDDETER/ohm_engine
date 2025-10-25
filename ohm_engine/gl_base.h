//	gl_base.h by Jaidev Bormann


#ifndef _OHM_GLBASE_H
#define _OHM_GLBASE_H


#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>


#define OHM_PFD_VERSION 1


struct ohm_glrender 
{

	HGLRC			render_context_handle;
	HDC			device_context_handle;


	int			pixel_format;


	PIXELFORMATDESCRIPTOR	pixel_format_desc;
	DWORD			flags;
	BYTE			color_bits, depth_bits, stencil_bits, layer_type, pixel_type;

};


void ohm_glrender_init(struct ohm_glrender* context);
void ohm_glrender_free(struct ohm_glrender* context);


#endif