/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:39:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/15 16:40:32 by hbouillo         ###   ########.fr       */
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
		glGenTextures(1, &(((t_display *)data->data)->front_map));
		glGenTextures(1, &(((t_display *)data->data)->back_map));
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
	glUniform1i(glGetUniformLocation(data->shader_prog, "frontMap"), 3);
	glUniform1i(glGetUniformLocation(data->shader_prog, "backMap"), 4);
	glUniform1i(glGetUniformLocation(data->shader_prog, "hextex"), 2);
}

static t_color	color_from_writer(char writer, t_display *display)
{
	if ((writer - 1) % 4 == 0)
		return (display->p1);
	if ((writer - 1) % 4 == 1)
		return (display->p2);
	if ((writer - 1) % 4 == 2)
		return (display->p3);
	if ((writer - 1) % 4 == 3)
		return (display->p4);
	return (display->grid_00);
}

static void		update_mem_raw(t_display *display)
{
	int			i;
	t_color		tmp;
	float		f;

	if (!display->mem->raw_content && !(display->mem->raw_content =
		(unsigned char *)ft_memalloc(
			sizeof(unsigned char) * display->mem->size)))
		error(ERR_MALLOC, ERR_CRITICAL);
	i = -1;
	while ((unsigned int)++i < display->mem->size)
		display->mem->raw_content[i] = display->mem->data[i].content;
	if (!display->mem->raw_front && !(display->mem->raw_front =
		(float *)ft_memalloc(
			sizeof(float) * display->mem->size * 4)))
		error(ERR_MALLOC, ERR_CRITICAL);
	i = -1;
	while ((unsigned int)++i < display->mem->size)
	{
		tmp = color_from_writer(display->mem->data[i].writer, display);
		f = (display->game->cycle - display->mem->data[i].write_cycle
			 > WRITE_ANIM_DUR) ? 0.0 : (1.0 - ((float)(display->game->cycle -
			display->mem->data[i].write_cycle)) / ((float)WRITE_ANIM_DUR));
		display->mem->raw_front[i * 4] = tmp.r + (1.0 - tmp.r) * f;
		display->mem->raw_front[i * 4 + 1] = tmp.g + (1.0 - tmp.g) * f;
		display->mem->raw_front[i * 4 + 2] = tmp.b + (1.0 - tmp.b) * f;
		display->mem->raw_front[i * 4 + 3] = tmp.a;
	}
	if (!display->mem->raw_back && !(display->mem->raw_back =
		(float *)ft_memalloc(
			sizeof(float) * display->mem->size * 4)))
		error(ERR_MALLOC, ERR_CRITICAL);
	i = -1;
	while ((unsigned int)++i < display->mem->size)
	{
		tmp = display->mem->data[i].procs ? display->grid_00 :
			sg_color(0xff000000);
		display->mem->raw_back[i * 4] = tmp.r;
		display->mem->raw_back[i * 4 + 1] = tmp.g;
		display->mem->raw_back[i * 4 + 2] = tmp.b;
		display->mem->raw_back[i * 4 + 3] = tmp.a;
	}
}

static void		compute_texture(t_display *display)
{
	if (!display->mem->data)
		return ;
	update_mem_raw(display);
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, display->map);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, display->mem->size_2d.w,
		display->mem->size_2d.h, 0, GL_RED_INTEGER,
		GL_UNSIGNED_BYTE, display->mem->raw_content);
	glActiveTexture(GL_TEXTURE0 + 3);
	glBindTexture(GL_TEXTURE_2D, display->front_map);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, display->mem->size_2d.w,
		display->mem->size_2d.h, 0, GL_RGBA,
		GL_FLOAT, display->mem->raw_front);
	display->mem->new_data = 0;
	glActiveTexture(GL_TEXTURE0 + 4);
	glBindTexture(GL_TEXTURE_2D, display->back_map);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, display->mem->size_2d.w,
		display->mem->size_2d.h, 0, GL_RGBA,
		GL_FLOAT, display->mem->raw_back);
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
	compute_texture(display);
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, display->map);
	glActiveTexture(GL_TEXTURE0 + 2);
	glBindTexture(GL_TEXTURE_2D, display->hextex);
	glActiveTexture(GL_TEXTURE0 + 3);
	glBindTexture(GL_TEXTURE_2D, display->front_map);
	glActiveTexture(GL_TEXTURE0 + 4);
	glBindTexture(GL_TEXTURE_2D, display->back_map);
	uniforms(data, bounds);
	glBindVertexArray(data->vao);
	uniform = glGetUniformLocation(data->shader_prog, "mode");
	glUniform1i(uniform, 0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glUniform1i(uniform, 1);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}
