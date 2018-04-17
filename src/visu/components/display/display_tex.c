/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:08:59 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/17 01:23:28 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

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

static void		update_front_raw(t_display *display)
{
	float		f;
	int			i;
	t_color		tmp;

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
}

static void		update_back_raw(t_display *display)
{
	float		f;
	float		a;
	int			i;
	t_color		tmp;

	if (!display->mem->raw_back && !(display->mem->raw_back =
		(float *)ft_memalloc(sizeof(float) * display->mem->size * 4)))
		error(ERR_MALLOC, ERR_CRITICAL);
	i = -1;
	while ((unsigned int)++i < display->mem->size)
	{
		tmp = display->mem->data[i].procs ? display->grid_00 :
			sg_color(0xff000000);
		f = (display->game->cycle - display->game->check_cycle
			> CHECK_ANIM_DUR) ? 0.0 : (1.0 - ((float)(display->game->cycle -
			display->game->check_cycle)) / ((float)(CHECK_ANIM_DUR)));
		a = (1.0 - tmp.a) * f * display->check.a + tmp.a;
		display->mem->raw_back[i * 4] = ((1.0 - tmp.a) * f *
			display->check.a * display->check.r + tmp.a * tmp.r) / a;
		display->mem->raw_back[i * 4 + 1] = ((1.0 - tmp.a) * f *
			display->check.a * display->check.g + tmp.a * tmp.g) / a;
		display->mem->raw_back[i * 4 + 2] = ((1.0 - tmp.a) * f *
			display->check.a * display->check.b + tmp.a * tmp.b) / a;
		display->mem->raw_back[i * 4 + 3] = a;
	}
}

static void		compute_raw_front(t_display *display)
{
	glActiveTexture(GL_TEXTURE0 + 3);
	glBindTexture(GL_TEXTURE_2D, display->front_map);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, display->mem->size_2d.w,
		display->mem->size_2d.h, 0, GL_RGBA,
		GL_FLOAT, display->mem->raw_front);
	glActiveTexture(GL_TEXTURE0 + 4);
	glBindTexture(GL_TEXTURE_2D, display->back_map);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, display->mem->size_2d.w,
		display->mem->size_2d.h, 0, GL_RGBA,
		GL_FLOAT, display->mem->raw_back);
}

void			compute_texture(t_display *display)
{
	int			i;

	if (!display->mem->data)
		return ;
	if (!display->mem->raw_content && !(display->mem->raw_content =
		(unsigned char *)ft_memalloc(
			sizeof(unsigned char) * display->mem->size)))
		error(ERR_MALLOC, ERR_CRITICAL);
	i = -1;
	while ((unsigned int)++i < display->mem->size)
		display->mem->raw_content[i] = display->mem->data[i].content;
	update_front_raw(display);
	update_back_raw(display);
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, display->map);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32UI, display->mem->size_2d.w,
		display->mem->size_2d.h, 0, GL_RED_INTEGER,
		GL_UNSIGNED_BYTE, display->mem->raw_content);
	compute_raw_front(display);
	display->mem->new_data = 0;
}
