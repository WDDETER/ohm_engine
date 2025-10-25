//	mat4x4_base.h by Jaidev Bormann


#ifndef _OHM_MAT4X4BASE_H
#define _OHM_MAT4X4BASE_H


typedef float ohm_mat4x4f[16];


static inline float* ohm_mat4x4f_identity(ohm_mat4x4f mat) 
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
	mat[10] = 1.0f;
	mat[11] = 0.0f;

	mat[12] = 0.0f;
	mat[13] = 0.0f;
	mat[14] = 0.0f;
	mat[15] = 1.0f;


	return mat;

}


#endif