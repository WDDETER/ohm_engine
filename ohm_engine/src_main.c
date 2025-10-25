//	src_main.c by Jaidev Bormann


#include "win_base.h"
#include "win_ohmdef.h"

#include "gl_base.h"
#include "gl_mesh.h"
#include "gl_ohmdef.h"
#include "gl_camera.h"

#include "math_base.h"
#include "mat4x4_transform.h"
#include "mat4x4_projection.h"


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


	struct ohm_glrender context	= { 0 };
	context.flags			= OHMDEF_GL_FLAGS;
	context.layer_type		= OHMDEF_GL_LAYER;
	context.pixel_type		= OHMDEF_GL_PIXEL_TYPE;

	context.color_bits		= OHMDEF_GL_COLOR_BITS;
	context.depth_bits		= OHMDEF_GL_DEPTH_BITS;

	context.device_context_handle	= window.device_context_handle;
	
	ohm_glrender_init(&context);


	struct ohm_glcamera camera	= { 0 };
	camera.position			= ohm_vec3f_set(camera.position, 0.0f, 0.0f, 3.0f);
	camera.target			= ohm_vec3f_set(camera.target, 0.0f, 0.0f, 0.0f);
	camera.up			= ohm_vec3f_set(camera.up, 0.0f, 1.0f, 0.0f);


	struct ohm_glmesh mesh = { 0 };
	
	ohm_glmesh_load(&mesh, "C:\\Users\\borma\\OneDrive\\Desktop\\cube.om1");


	GLfloat angle_x = 0.0f;
	GLfloat angle_y = 0.0f;
	GLfloat angle_z = 0.0f;

	ohm_mat4x4f translation		= { 0 };
	ohm_mat4x4f scale		= { 0 };
	ohm_mat4x4f rotate_x		= { 0 };
	ohm_mat4x4f rotate_y		= { 0 };
	ohm_mat4x4f rotate_z		= { 0 };
	ohm_mat4x4f projection		= { 0 };


	while (window.is_running)
	{
	
		ohm_window_pump(&window, 0, 0);
	
		
		angle_x += 0.0005f;
		angle_y += 0.0001f;
		angle_z += 0.00005f;


		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glLoadIdentity();

		ohm_mat4x4f_perspective	(projection, OHM_DEGTORAD(72.0f), (float)window.width / (float)window.height, 0.1f, 1000.0f);
		ohm_glcamera_lookat	(&camera);
		ohm_mat4x4f_translate	(translation, 0.0f, 0.0f, 0.0f);
		ohm_mat4x4f_rotate_x	(rotate_x, angle_x);
		ohm_mat4x4f_rotate_y	(rotate_y, angle_y);
		ohm_mat4x4f_rotate_z	(rotate_z, angle_z);
		ohm_mat4x4f_scale	(scale, 1.0f, 1.0f, 1.0f);
		

		glMultMatrixf		(projection);
		glMultMatrixf		(camera.view);
		glMultMatrixf		(translation);
		glMultMatrixf		(rotate_z);
		glMultMatrixf		(rotate_y);
		glMultMatrixf		(rotate_x);
		glMultMatrixf		(scale);

		ohm_glmesh_draw(&mesh);


		SwapBuffers(context.device_context_handle);
		
	}

	
	ohm_glmesh_free		(&mesh);
	ohm_glrender_free	(&context);
	ohm_window_free		(&window);


	return 0;
}