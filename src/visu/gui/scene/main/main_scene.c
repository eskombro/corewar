/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:30:40 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 18:50:18 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main_scene.h"

static void			main_set_players_colors(t_main_scene *main)
{
	t_llist			*tmp;
	t_player_info	*pinfo;

	tmp = main->p_infos;
	while (tmp)
	{
		pinfo = (t_player_info *)tmp->data;
		sg_set_label_color(pinfo->name, *pinfo->player->color);
		sg_set_label_color(pinfo->id, *pinfo->player->color);
		sg_set_label_color(pinfo->alive, *pinfo->player->color);
		tmp = tmp->next;
	}
}

static void			main_update_colors_display(t_visu *visu, t_main_scene *main)
{
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
	set_display_check_color(main->mem_grid.frame,
		visu->gui.colors->display_check);
}

void				main_update_colors(t_visu *visu, t_main_scene *main)
{
	sg_set_rectangle_icolor(main->top_frame, visu->gui.colors->background);
	sg_set_rectangle_ocolor(main->top_frame, visu->gui.colors->main_text);
	sg_set_label_color(main->title_label, visu->gui.colors->main_text);
	sg_set_label_color(main->cycles_lbl, visu->gui.colors->main_text);
	sg_set_label_color(main->cycles, visu->gui.colors->main_text);
	sg_set_label_color(main->cycles_to_die_lbl, visu->gui.colors->main_text);
	sg_set_label_color(main->cycles_to_die, visu->gui.colors->main_text);
	sg_set_label_color(main->cycles_left_lbl, visu->gui.colors->main_text);
	sg_set_label_color(main->cycles_left, visu->gui.colors->main_text);
	sg_set_label_color(main->cycles_rate_lbl, visu->gui.colors->main_text);
	sg_set_label_color(main->cycles_rate, visu->gui.colors->main_text);
	main_update_colors_display(visu, main);
	main_set_players_colors(main);
}

void				init_main_scene(t_visu *visu, t_main_scene *main)
{
	if (!(main->ptr = sg_new_scene(visu->window)))
		error(ERR_MALLOC, ERR_CRITICAL);
	frames(visu, main);
	display(visu, main);
	labels(visu, main);
	cycles_lbl(visu, main);
	cycles_to_die_lbl(visu, main);
	cycles_left_lbl(visu, main);
	cycles_rate_lbl(visu, main);
	main_update_colors(visu, main);
}
