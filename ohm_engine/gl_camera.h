//	gl_camera.h by Jaidev Bormann


#ifndef _OHM_GLCAMERA_H
#define _OHM_GLCAMERA_H


#include "vec3_base.h"
#include "mat4x4_base.h"


struct ohm_glcamera 
{

	ohm_vec3f	position, target, up, right, look;


	ohm_mat4x4f	view;

};


static inline void ohm_glcamera_lookat(struct ohm_glcamera* camera)
{

	camera->look	= ohm_vec3f_normalize(ohm_vec3f_sub(camera->target, camera->position));
	camera->right	= ohm_vec3f_normalize(ohm_vec3f_cross(camera->look, camera->up));
	camera->up	= ohm_vec3f_cross(camera->right, camera->look);


	camera->view[0]		= camera->right.x;
	camera->view[1]		= camera->up.x;
	camera->view[2]		= -camera->look.x;
	camera->view[3]		= 0;

	camera->view[4]		= camera->right.y;
	camera->view[5]		= camera->up.y;
	camera->view[6]		= -camera->look.y;
	camera->view[7]		= 0;

	camera->view[8]		= camera->right.z;
	camera->view[9]		= camera->up.z;
	camera->view[10]	= -camera->look.z;
	camera->view[11]	= 0;

	camera->view[12]	= -ohm_vec3f_dot(camera->right, camera->position);
	camera->view[13]	= -ohm_vec3f_dot(camera->up, camera->position);
	camera->view[14]	= ohm_vec3f_dot(camera->look, camera->position);
	camera->view[15]	= 1.0f;

}


#endif