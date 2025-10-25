//	vec3_base.h by Jaidev Bormann


#ifndef _OHM_VEC3BASE_H
#define _OHM_VEC3BASE_H


#include <math.h>


typedef struct ohm_vec3f
{

	float x, y, z;

} ohm_vec3f;


ohm_vec3f ohm_vec3f_set(ohm_vec3f vec3, float x, float y, float z);		// .. maybe inline ( though i don't want to increase binary size )
										// .. and you usually only directly set vectors on init anyways


static inline ohm_vec3f ohm_vec3f_add(ohm_vec3f vec3a, ohm_vec3f vec3b)
{

	vec3a.x += vec3b.x;
	vec3a.y += vec3b.y;
	vec3a.z += vec3b.z;

	
	return vec3a;

}


static inline ohm_vec3f ohm_vec3f_sub(ohm_vec3f vec3a, ohm_vec3f vec3b)
{

	vec3a.x -= vec3b.x;
	vec3a.y -= vec3b.y;
	vec3a.z -= vec3b.z;


	return vec3a;

}


static inline ohm_vec3f ohm_vec3f_scale(ohm_vec3f vec3, float scalar)
{

	vec3.x *= scalar;
	vec3.y *= scalar;
	vec3.z *= scalar;


	return vec3;

}


static inline float ohm_vec3f_dot(ohm_vec3f vec3a, ohm_vec3f vec3b)
{

	return vec3a.x * vec3b.x + vec3a.y * vec3b.y + vec3a.z * vec3b.z;

}


static inline ohm_vec3f ohm_vec3f_cross(ohm_vec3f vec3a, ohm_vec3f vec3b)
{

	ohm_vec3f result = { 0 };


	result.x = vec3a.y * vec3b.z - vec3a.z * vec3b.y;
	result.y = vec3a.z * vec3b.x - vec3a.x * vec3b.z;
	result.z = vec3a.x * vec3b.y - vec3a.y * vec3b.x;


	return result;

}


static inline float ohm_vec3f_length(ohm_vec3f vec3)
{
	
	return sqrtf(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);

}


static inline ohm_vec3f ohm_vec3f_normalize(ohm_vec3f vec3)
{

	float length = sqrtf(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);


	if (length != 0.0f)
	{

		float inv_length = 1.0f / length;

		vec3.x *= inv_length;
		vec3.y *= inv_length;
		vec3.z *= inv_length;

	}


	return vec3;

}


#endif