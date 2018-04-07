/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:42:58 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/06 20:13:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main_scene.h"

void					frames(t_visu *visu, t_main_scene *main)
{
	if (!(main->top_frame = sg_create_rectangle(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->top_frame,
		sg_recti(MAIN_SCENE_MARGIN, visu->win_h - MAIN_SCENE_MARGIN,
			visu->win_w - 2 * MAIN_SCENE_MARGIN, MAIN_SCENE_TOP_HEIGHT));
	sg_set_flags(main->top_frame, SG_ALIGN_RIGHT | SG_ALIGN_BOTTOM |
		SG_LOCK_TOP | SG_LOCK_LEFT | SG_LOCK_RIGHT | SG_LOCK_HEIGHT);
	sg_set_rectangle_radius(main->top_frame, MAIN_SCENE_CORNER_RADIUS);
	sg_set_rectangle_edge(main->top_frame, MAIN_SCENE_EDGE);
}

void					labels(t_visu *visu, t_main_scene *main)
{
	if (!(main->title_label = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->title_label,
		sg_recti(visu->win_w / 2, visu->win_h - MAIN_SCENE_MARGIN - 25, 0, 0));
	sg_set_flags(main->title_label, SG_LOCK_TOP
		| SG_LOCK_SIZE);
	sg_set_label_text(main->title_label, sg_new_gstr("Corewar",
		get_resource_path(COREWAR_FONT), COREWAR_TOP_FONT_SIZE));
}
