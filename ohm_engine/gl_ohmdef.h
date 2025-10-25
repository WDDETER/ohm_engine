//	gl_ohmdef.h by Jaidev Bormann


#ifndef _OHM_GLOHMDEF_H
#define _OHM_GLOHMDEF_H


#include <windows.h>
#include <gl/GL.h>


#define OHMDEF_GL_FLAGS		(PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER)
#define OHMDEF_GL_LAYER		PFD_MAIN_PLANE
#define OHMDEF_GL_PIXEL_TYPE	PFD_TYPE_RGBA

#define OHMDEF_GL_COLOR_BITS	32
#define OHMDEF_GL_DEPTH_BITS	24
#define OHMDEF_GL_STENCIL_BITS	8


#endif