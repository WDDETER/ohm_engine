//	gl_mesh.h by Jaidev Bormann


#ifndef _OHM_GLMESH_H
#define _OHM_GLMESH_H


#include <windows.h>
#include <stdint.h>
#include <stddef.h>
#include <gl/GL.h>
#include <gl/GLU.h>


#define OHM_GLVERT_OFFSET(base, type, member)	((type*)((BYTE*)(base) + offsetof(type, member)))
#define OHM_GLVERTEX_POSITION_SIZE		3
#define OHM_GLVERTEX_COLOR_SIZE			4
#define OHM_GLVERTEX_NORMAL_SIZE		3
#define OHM_GLVERTEX_TEXCOORD_SIZE		2


struct ohm_glvertex
{

	GLfloat position[OHM_GLVERTEX_POSITION_SIZE],
		color	[OHM_GLVERTEX_COLOR_SIZE],
		normal	[OHM_GLVERTEX_NORMAL_SIZE],
		texcoord[OHM_GLVERTEX_TEXCOORD_SIZE];

};


struct ohm_glmesh
{

	struct ohm_glvertex*	vertices;
	GLushort*		indices;


	int32_t vertex_count, index_count;

};


static const GLsizei ohm_glmesh_stride = sizeof(struct ohm_glvertex);


void ohm_glmesh_init	(struct ohm_glmesh* mesh);
void ohm_glmesh_free	(struct ohm_glmesh* mesh);
void ohm_glmesh_draw	(struct ohm_glmesh* mesh);
void ohm_glmesh_load	(struct ohm_glmesh* mesh, const char* file_path);


#endif