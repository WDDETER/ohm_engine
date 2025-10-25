//	gl_base.c by Jaidev Bormann


#include <stdint.h>
#include "gl_base.h"
#include "win_error.h"


void ohm_glrender_init(struct ohm_glrender* context)
{

	context->pixel_format_desc.nSize	= sizeof(PIXELFORMATDESCRIPTOR);
	context->pixel_format_desc.dwFlags	= context->flags;
	context->pixel_format_desc.cColorBits	= context->color_bits;
	context->pixel_format_desc.cDepthBits	= context->depth_bits;
	context->pixel_format_desc.cStencilBits = context->stencil_bits;
	context->pixel_format_desc.iLayerType	= context->layer_type;
	context->pixel_format_desc.iPixelType	= context->pixel_type;
	context->pixel_format_desc.nVersion	= OHM_PFD_VERSION;


	context->pixel_format		= ChoosePixelFormat(context->device_context_handle, &context->pixel_format_desc);
	BOOL pixel_format_return	= SetPixelFormat(context->device_context_handle, context->pixel_format, &context->pixel_format_desc);
	context->render_context_handle	= wglCreateContext(context->device_context_handle);
	BOOL render_context_return	= wglMakeCurrent(context->device_context_handle, context->render_context_handle);

	ohm_window_error((const void*)(uintptr_t)pixel_format_return);
	ohm_window_error((const void*)(uintptr_t)context->pixel_format);
	ohm_window_error((const void*)(uintptr_t)context->render_context_handle);
	ohm_window_error((const void*)(uintptr_t)render_context_return);

}


void ohm_glrender_free(struct ohm_glrender* context)
{

	if (context == NULL) return;


	wglMakeCurrent	(NULL, NULL);
	wglDeleteContext(context->render_context_handle);

}