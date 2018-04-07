/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:30:40 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/06 20:10:24 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main_scene.h"

void			main_update_colors(t_visu *visu, t_main_scene *main)
{
	sg_set_rectangle_icolor(main->top_frame, visu->gui.colors->background);
	sg_set_rectangle_ocolor(main->top_frame, visu->gui.colors->main_text);
	sg_set_label_color(main->title_label, visu->gui.colors->main_text);
	// sg_set_label_color(main->p1_label, show->gui.colors->display_o);
	// sg_set_label_color(main->p2_label, show->gui.colors->display_x);
	// sg_set_label_color(main->vs_label, show->gui.colors->main_text);
	// sg_set_label_color(main->p1_score_label, show->gui.colors->display_o);
	// sg_set_label_color(main->p2_score_label, show->gui.colors->display_x);
	// sg_set_label_color(main->madeby_label, show->gui.colors->main_text);
	// show_set_display_ocolor(main->display_frame, show->gui.colors->display_o);
	// show_set_display_xcolor(main->display_frame, show->gui.colors->display_x);
	// show_set_display_ecolor(main->display_frame,
	// 	show->gui.colors->display_edge);
	// show_set_display_gcolor(main->display_frame,
	// 	show->gui.colors->display_grid);
	// update_button_color(show, main->pause_button);
	// update_button_color(show, main->next_button);
	// update_button_color(show, main->prev_button);
	// update_button_color(show, main->end_button);
	// update_button_color(show, main->begin_button);
}

void			init_main_scene(t_visu *visu, t_main_scene *main)
{
	if (!(main->ptr = sg_new_scene(visu->window)))
		error(ERR_MALLOC, ERR_CRITICAL);
	frames(visu, main);
	labels(visu, main);
	main_update_colors(visu, main);
}
