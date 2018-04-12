/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:30:40 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 15:27:09 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main_scene.h"

void			main_update_colors(t_visu *visu, t_main_scene *main)
{
	sg_set_rectangle_icolor(main->top_frame, visu->gui.colors->background);
	sg_set_rectangle_ocolor(main->top_frame, visu->gui.colors->main_text);
	sg_set_label_color(main->title_label, visu->gui.colors->main_text);
	sg_set_rectangle_icolor(main->mem_grid.frame, visu->gui.colors->background);
	sg_set_rectangle_ocolor(main->mem_grid.frame, visu->gui.colors->main_text);
	set_display_ocolor(main->mem_grid.frame,
		visu->gui.colors->display_edge);
	set_display_grid_color(main->mem_grid.frame,
		visu->gui.colors->display_grid_00);
	set_display_player_color(1, main->mem_grid.frame,
		visu->gui.colors->display_p1);
	set_display_player_color(2, main->mem_grid.frame,
		visu->gui.colors->display_p2);
	set_display_player_color(3, main->mem_grid.frame,
		visu->gui.colors->display_p3);
	set_display_player_color(4, main->mem_grid.frame,
		visu->gui.colors->display_p4);
}

void			init_main_scene(t_visu *visu, t_main_scene *main)
{
	if (!(main->ptr = sg_new_scene(visu->window)))
		error(ERR_MALLOC, ERR_CRITICAL);
	frames(visu, main);
	display(visu, main);
	labels(visu, main);
	main_update_colors(visu, main);
}
