/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:39:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 18:22:18 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

static void		uniforms_norme(t_component_data *data, t_display *display,
					float fx, float fy)
{
	GLint		uniform;

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
	uniforms_norme(data, display, fx, fy);
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
