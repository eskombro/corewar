/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:39:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 18:33:32 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

static void		init_draw(GLuint vao, t_component_data *data, t_rect bounds)
{
	float		points[8];
	t_display	*display;

	data->vbo_count = 1;
	display = (t_display *)(data->data);
	if (!data->vbos)
	{
		if (!(data->vbos = (GLuint *)ft_memalloc(sizeof(GLuint) * 1)))
			error(ERR_MALLOC, ERR_CRITICAL);
		glGenTextures(1, &(((t_display *)data->data)->map));
		glGenTextures(1, &(((t_display *)data->data)->hextex));
		glGenTextures(1, &(((t_display *)data->data)->writer_map));
		glActiveTexture(GL_TEXTURE0 + 2);
		glBindTexture(GL_TEXTURE_2D, display->hextex);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, display->hextex_data->width,
			display->hextex_data->height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, display->hextex_data->data);
	}
	else
		glDeleteBuffers(1, data->vbos);
	sg_rect_to_vec2buf(bounds, points);
	glGenBuffers(1, data->vbos);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, data->vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), points, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

static void		uniforms(t_component_data *data, t_rect bounds)
{
	GLint		uniform;
	t_display	*display;
	float		fx;
	float		fy;

	display = (t_display *)data->data;
	fx = (float)(*(display->win_w)) / 2.0;
	fy = (float)(*(display->win_h)) / 2.0;
	uniform = glGetUniformLocation(data->shader_prog, "bounds");
	glUniform4i(uniform, (int)((bounds.x + 1.0) * fx),
		(int)((bounds.y + 1.0) * fy),
		(int)(bounds.w * fx),
		(int)(bounds.h * fy));
	uniform = glGetUniformLocation(data->shader_prog, "ocolor");
	sg_uniform_color(uniform, display->ocolor);
	uniform = glGetUniformLocation(data->shader_prog, "grid_color");
	sg_uniform_color(uniform, display->grid_00);
	uniform = glGetUniformLocation(data->shader_prog, "p1");
	sg_uniform_color(uniform, display->p1);
	uniform = glGetUniformLocation(data->shader_prog, "p2");
	sg_uniform_color(uniform, display->p2);
	uniform = glGetUniformLocation(data->shader_prog, "p3");
	sg_uniform_color(uniform, display->p3);
	uniform = glGetUniformLocation(data->shader_prog, "p4");
	sg_uniform_color(uniform, display->p4);
	uniform = glGetUniformLocation(data->shader_prog, "edge");
	glUniform1i(uniform, display->edge);
	uniform = glGetUniformLocation(data->shader_prog, "mapDataSize");
	glUniform1i(uniform, display->mem->size);
	uniform = glGetUniformLocation(data->shader_prog, "mapSize");
	glUniform2i(uniform, display->mem->size_2d.w, display->mem->size_2d.h);
	glUniform1i(glGetUniformLocation(data->shader_prog, "map"), 1);
	glUniform1i(glGetUniformLocation(data->shader_prog, "writerMap"), 3);
	glUniform1i(glGetUniformLocation(data->shader_prog, "hextex"), 2);
}

static void		compute_texture(t_display *display)
{
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, display->map);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, display->mem->size_2d.w,
		display->mem->size_2d.h, 0, GL_RED_INTEGER,
		GL_UNSIGNED_BYTE, display->mem->data);
	glActiveTexture(GL_TEXTURE0 + 3);
	glBindTexture(GL_TEXTURE_2D, display->writer_map);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, display->mem->size_2d.w,
		display->mem->size_2d.h, 0, GL_RED_INTEGER,
		GL_UNSIGNED_BYTE, display->mem->writer);
	display->mem->new_data = 0;
}

void			display_draw(void *component, t_component_data *data,
					t_rect bounds)
{
	t_display		*display;
	GLint			uniform;

	component = NULL;
	display = ((t_display *)data->data);
	glUseProgram(data->shader_prog);
	if (data->full_draw)
		init_draw(data->vao, data, bounds);
	if (display->mem->new_data)
		compute_texture(display);
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, display->map);
	glActiveTexture(GL_TEXTURE0 + 2);
	glBindTexture(GL_TEXTURE_2D, display->hextex);
	glActiveTexture(GL_TEXTURE0 + 3);
	glBindTexture(GL_TEXTURE_2D, display->writer_map);
	uniforms(data, bounds);
	glBindVertexArray(data->vao);
	uniform = glGetUniformLocation(data->shader_prog, "mode");
	glUniform1i(uniform, 0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glUniform1i(uniform, 1);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}
