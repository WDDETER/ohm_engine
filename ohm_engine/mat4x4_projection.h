//	mat4x4_projection.h by Jaidev Bormann


#ifndef _OHM_MAT4X4_PROJECTION_H
#define _OHM_MAT4X4_PROJECTION_H


#include <math.h>
#include "mat4x4_base.h"


static inline void ohm_mat4x4f_perspective(ohm_mat4x4f mat, float fov_y, float aspect, float near_z, float far_z) 
{

	float fov_tan		= 1.0f / tanf(fov_y * 0.5f);
	float near_far_diff	= 1.0f / (near_z - far_z);


	mat[0]	= aspect / fov_tan;
	mat[1]	= 0.0f;
	mat[2]	= 0.0f;
	mat[3]	= 0.0f;

	mat[4]	= 0.0f;
	mat[5]	= fov_tan;
	mat[6]	= 0.0f;
	mat[7]	= 0.0f;

	mat[8]	= 0.0f;
	mat[9]	= 0.0f;
	mat[10] = (near_z + far_z) * near_far_diff;
	mat[11] = -1.0f;

	mat[12] = 0.0f;
	mat[13] = 0.0f;
	mat[14] = (2.0f * near_z * far_z) * near_far_diff;
	mat[15] = 0.0f;

}


#endif