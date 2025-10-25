//	mat4x4_transform.h by Jaidev Bormann


#ifndef _OHM_MAT4X4TRANSFORM_H
#define _OHM_MAT4X4TRANSFORM_H


#include <math.h>
#include "mat4x4_base.h"


static inline void ohm_mat4x4f_translate(ohm_mat4x4f mat, float x, float y, float z)
{

	mat[0]	= 1.0f;
	mat[1]	= 0.0f;
	mat[2]	= 0.0f;
	mat[3]	= 0.0f;

	mat[4]	= 0.0f;
	mat[5]	= 1.0f;
	mat[6]	= 0.0f;
	mat[7]	= 0.0f;

	mat[8]	= 0.0f;
	mat[9]	= 0.0f;
	mat[10]	= 1.0f;
	mat[11]	= 0.0f;

	mat[12]	= x;
	mat[13]	= y;
	mat[14]	= z;
	mat[15]	= 1.0f;

}

static inline void ohm_mat4x4f_scale(ohm_mat4x4f mat, float x, float y, float z)
{

	mat[0]	= x;
	mat[1]	= 0.0f;
	mat[2]	= 0.0f;
	mat[3]	= 0.0f;

	mat[4]	= 0.0f;
	mat[5]	= y;
	mat[6]	= 0.0f;
	mat[7]	= 0.0f;

	mat[8]	= 0.0f;
	mat[9]	= 0.0f;
	mat[10]	= z;
	mat[11]	= 0.0f;

	mat[12]	= 0.0f;
	mat[13]	= 0.0f;
	mat[14]	= 0.0f;
	mat[15]	= 1.0f;

}


static inline void ohm_mat4x4f_rotate_x(ohm_mat4x4f mat, float a)
{

	mat[0]	= 1.0f;
	mat[1]	= 0.0f;
	mat[2]	= 0.0f;
	mat[3]	= 0.0f;

	mat[4]	= 0.0f;
	mat[5]	= cosf(a);
	mat[6]	= -sinf(a);
	mat[7]	= 0.0f;

	mat[8]	= 0.0f;
	mat[9]	= sinf(a);
	mat[10]	= cosf(a);
	mat[11]	= 0.0f;

	mat[12]	= 0.0f;
	mat[13]	= 0.0f;
	mat[14]	= 0.0f;
	mat[15]	= 1.0f;

}


static inline void ohm_mat4x4f_rotate_y(ohm_mat4x4f mat, float a)
{

	mat[0]	= cosf(a);
	mat[1]	= 0.0f;
	mat[2]	= -sinf(a);
	mat[3]	= 0.0f;

	mat[4]	= 0.0f;
	mat[5]	= 1.0f;
	mat[6]	= 0.0f;
	mat[7]	= 0.0f;

	mat[8]	= sinf(a);
	mat[9]	= 0.0f;
	mat[10]	= cosf(a);
	mat[11]	= 0.0f;

	mat[12]	= 0.0f;
	mat[13]	= 0.0f;
	mat[14]	= 0.0f;
	mat[15]	= 1.0f;

}


static inline void ohm_mat4x4f_rotate_z(ohm_mat4x4f mat, float a)
{

	mat[0]	= cosf(a);
	mat[1]	= sinf(a);
	mat[2]	= 0.0f;
	mat[3]	= 0.0f;

	mat[4]	= -sinf(a);
	mat[5]	= cosf(a);
	mat[6]	= 0.0f;
	mat[7]	= 0.0f;

	mat[8]	= 0.0f;
	mat[9]	= 0.0f;
	mat[10]	= 1.0f;
	mat[11]	= 0.0f;

	mat[12]	= 0.0f;
	mat[13]	= 0.0f;
	mat[14]	= 0.0f;
	mat[15]	= 1.0f;

}

#endif