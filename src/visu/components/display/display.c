/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 22:06:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 17:55:15 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

static t_display	*default_display_data(t_visu *visu)
{
	t_display		*display_data;

	if (!(display_data = (t_display *)ft_memalloc(sizeof(t_display))))
		return (NULL);
	display_data->ocolor = sg_colorf(0.0, 0.0, 0.0, 1.0);
	display_data->grid_00 = sg_colorf(1.0, 1.0, 1.0, 1.0);
	display_data->p1 = sg_colorf(1.0, 1.0, 1.0, 1.0);
	display_data->p2 = sg_colorf(1.0, 1.0, 1.0, 1.0);
	display_data->p3 = sg_colorf(1.0, 1.0, 1.0, 1.0);
	display_data->p4 = sg_colorf(1.0, 1.0, 1.0, 1.0);
	display_data->check = sg_colorf(1.0, 1.0, 1.0, 1.0);
	display_data->win_h = &(visu->win_h);
	display_data->win_w = &(visu->win_w);
	display_data->mem = &(visu->mem);
	display_data->game = &(visu->game);
	display_data->edge = 1;
	display_data->map = 0;
	if (!(display_data->hextex_data =
			pngtex_from_file(get_resource_path(VM_MEMTEX))))
		error(ERR_VISU_MEMTEX, ERR_CRITICAL);
	display_data->hextex = 0;
	return (display_data);
}

void				*create_display(void *scene, t_visu *visu)
{
	void			*display_ptr;
	char			*fs;
	char			*vs;
	GLuint			shader;

	if (!(fs = get_resource_path("shaders/display.fs")) ||
		!(vs = get_resource_path("shaders/display.vs")))
		return (NULL);
	shader = get_shader_prog(fs, vs);
	if (shader == 0 ||
		!(display_ptr = sg_create_component(scene, shader)))
		return (NULL);
	free(vs);
	free(fs);
	sg_set_component_draw(display_ptr, &display_draw);
	sg_set_component_event(display_ptr, &display_event);
	sg_set_component_data(display_ptr, default_display_data(visu));
	return (display_ptr);
}
