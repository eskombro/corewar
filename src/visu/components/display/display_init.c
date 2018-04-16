/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:16:36 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 18:19:32 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

static void	gen_tex(t_display *display)
{
	glGenTextures(1, &display->map);
	glGenTextures(1, &display->hextex);
	glGenTextures(1, &display->front_map);
	glGenTextures(1, &display->back_map);
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

void		init_draw(GLuint vao, t_component_data *data, t_rect bounds)
{
	float		points[8];
	t_display	*display;

	data->vbo_count = 1;
	display = (t_display *)(data->data);
	if (!data->vbos)
	{
		if (!(data->vbos = (GLuint *)ft_memalloc(sizeof(GLuint) * 1)))
			error(ERR_MALLOC, ERR_CRITICAL);
		gen_tex(display);
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
