//	gl_mesh.c by Jaidev Bormann


#include <stdlib.h>
#include <stdio.h>
#include "gl_mesh.h"
#include "general_error.h"


#define OHM_LINE_BUFFER_SIZE	1024
#define OHM_GLMESH_INDEX_WIDTH	3


void ohm_glmesh_init(struct ohm_glmesh* mesh)
{
	
	mesh->vertices	= (struct ohm_glvertex*)malloc(mesh->vertex_count * sizeof(struct ohm_glvertex));
	mesh->indices	= (GLushort*)malloc(mesh->index_count * sizeof(GLushort));

	ohm_error((const void*)mesh->vertices, "mesh->vertices");
	ohm_error((const void*)mesh->indices, "mesh->indices");

}


void ohm_glmesh_free(struct ohm_glmesh* mesh)
{
	
	if (mesh == NULL) return;


	free(mesh->vertices);
	free(mesh->indices);

}


// .. meh?
void ohm_glmesh_draw(struct ohm_glmesh* mesh)
{

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);


	glVertexPointer		(OHM_GLVERTEX_POSITION_SIZE, GL_FLOAT, ohm_glmesh_stride, OHM_GLVERT_OFFSET(mesh->vertices, struct ohm_glvertex, position));
	glColorPointer		(OHM_GLVERTEX_COLOR_SIZE, GL_FLOAT, ohm_glmesh_stride, OHM_GLVERT_OFFSET(mesh->vertices, struct ohm_glvertex, color));
	glTexCoordPointer	(OHM_GLVERTEX_TEXCOORD_SIZE, GL_FLOAT, ohm_glmesh_stride, OHM_GLVERT_OFFSET(mesh->vertices, struct ohm_glvertex, texcoord));
	glNormalPointer		(GL_FLOAT, ohm_glmesh_stride, OHM_GLVERT_OFFSET(mesh->vertices, struct ohm_glvertex, normal));
	
	glDrawElements(GL_TRIANGLES, mesh->index_count, GL_UNSIGNED_SHORT, mesh->indices);


	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

}


void ohm_glmesh_load(struct ohm_glmesh* mesh, const char* file_path)
{

	FILE* file = fopen(file_path, "r");

	ohm_error((const void*)file, "file");


	BYTE line_buffer[OHM_LINE_BUFFER_SIZE] = { 0 };

	int vertex_count = 0, index_count = 0;
	int vertex_index = 0, index_index = 0;

	
	while (fgets(line_buffer, sizeof(line_buffer), file)) 
	{
	
		if (line_buffer[0] == 'v') vertex_count++;
		if (line_buffer[0] == 'i') index_count++;
	
	}

	mesh->vertex_count	= vertex_count;
	mesh->index_count	= index_count * OHM_GLMESH_INDEX_WIDTH;

	ohm_glmesh_init(mesh);


	rewind(file);


	while (fgets(line_buffer, sizeof(line_buffer), file)) 
	{
	
		if (line_buffer[0] == 'v')
		{
		
			GLfloat x	= 0.0f, y	= 0.0f, z	= 0.0f;
			GLfloat r	= 0.0f, g	= 0.0f, b	= 0.0f;
			GLfloat tx	= 0.0f, ty	= 0.0f;
			GLfloat nx	= 0.0f, ny	= 0.0f, nz	= 0.0f;

			int value_return = sscanf_s(line_buffer, "v %f %f %f c %f %f %f t %f %f n %f %f %f", &x, &y, &z, &r, &g, &b, &tx, &ty, &nx, &ny, &nz);
			

			mesh->vertices[vertex_index].position[0] = x;
			mesh->vertices[vertex_index].position[1] = y;
			mesh->vertices[vertex_index].position[2] = z;

			mesh->vertices[vertex_index].color[0] = r;
			mesh->vertices[vertex_index].color[1] = g;
			mesh->vertices[vertex_index].color[2] = b;

			mesh->vertices[vertex_index].texcoord[0] = tx;
			mesh->vertices[vertex_index].texcoord[1] = ty;

			mesh->vertices[vertex_index].normal[0] = nx;
			mesh->vertices[vertex_index].normal[1] = ny;
			mesh->vertices[vertex_index].normal[2] = nz;


			vertex_index++;

		}

		if (line_buffer[0] == 'i')
		{
		
			GLushort a = 0, b = 0, c = 0;

			int value_return = sscanf_s(line_buffer, "i %hu %hu %hu", &a, &b, &c);
			

			mesh->indices[index_index++] = a;
			mesh->indices[index_index++] = b;
			mesh->indices[index_index++] = c;


		}
	
	}


	fclose(file);

}