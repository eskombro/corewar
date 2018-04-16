/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 01:04:53 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 17:07:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./end_scene.h"

static void				background(t_end_scene *end)
{
	if (!(end->background = sg_create_rectangle(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->background,
		sg_rectf(-1.1, -1.1, 2.2, 2.2));
	sg_set_flags(end->background, SG_ALIGN_RIGHT | SG_ALIGN_TOP);
	sg_set_rectangle_edge(end->background, 0);
	sg_set_rectangle_radius(end->background, 0);
}

static void				popup(t_visu *visu, t_end_scene *end)
{
	if (!(end->popup = sg_create_rectangle(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->popup,
		sg_recti(visu->win_w / 2, visu->win_h / 2,
			END_SCENE_POPUP_WIDTH, END_SCENE_POPUP_HEIGHT));
	sg_set_flags(end->popup, SG_LOCK_SIZE | SG_LOCK_MID);
	sg_set_rectangle_radius(end->popup, END_SCENE_CORNER_RADIUS);
	sg_set_rectangle_edge(end->popup, END_SCENE_EDGE);
}

void					end_update_colors(t_visu *visu, t_end_scene *end)
{
	t_color				background;

	background = visu->gui.colors->background;
	background.a = 0.8;
	sg_set_button_icolor(end->heckyeah, visu->gui.colors->background);
	sg_set_button_ocolor(end->heckyeah, visu->gui.colors->main_text);
	sg_set_button_hcolor(end->heckyeah, visu->gui.colors->button_hover);
	sg_set_button_pcolor(end->heckyeah, visu->gui.colors->button_pressed);
	sg_set_button_text_color(end->heckyeah, visu->gui.colors->main_text);
	sg_set_rectangle_icolor(end->popup, visu->gui.colors->background);
	sg_set_rectangle_ocolor(end->popup, visu->gui.colors->main_text);
	sg_set_rectangle_icolor(end->background, background);
	sg_set_rectangle_ocolor(end->background, visu->gui.colors->main_text);
	sg_set_label_color(end->msg, visu->gui.colors->main_text);
	sg_set_label_color(end->wins, visu->gui.colors->main_text);
}

void					init_end_scene(t_visu *visu, t_end_scene *end)
{
	if (!(end->ptr = sg_new_scene(visu->window)))
		error(ERR_MALLOC, ERR_CRITICAL);
	background(end);
	popup(visu, end);
	end_labels(visu, end);
	end_buttons(visu, end);
	end_update_colors(visu, end);
}
