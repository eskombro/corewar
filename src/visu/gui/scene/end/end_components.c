/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 02:58:40 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 17:07:38 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./end_scene.h"

static void				heckyeah_action(void *component, t_component_data *data)
{
	component = NULL;
	data = NULL;
	push_user_event(COREWAR_EVENT_SCENE, (void *)COREWAR_SCENE_MAIN, NULL);
}

void					end_buttons(t_visu *visu, t_end_scene *end)
{
	if (!(end->heckyeah = sg_create_button(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->heckyeah,
		sg_recti(visu->win_w / 2, visu->win_h / 2 + END_SCENE_BUTTON_PADDING,
			END_SCENE_HECKYEAH_BUTTON_WIDTH, END_SCENE_BUTTON_HEIGHT));
	sg_set_flags(end->heckyeah, SG_LOCK_SIZE | SG_LOCK_MID);
	sg_set_button_text(end->heckyeah, sg_new_gstr("Oh yeah",
		get_resource_path(COREWAR_FONT), COREWAR_TOP_FONT_SIZE));
	sg_set_button_edge(end->heckyeah, END_SCENE_EDGE);
	sg_set_button_radius(end->heckyeah, END_SCENE_CORNER_RADIUS);
	sg_set_button_action(end->heckyeah, &heckyeah_action);
}

void					end_labels(t_visu *visu, t_end_scene *end)
{
	if (!(end->msg = sg_create_label(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->msg,
		sg_recti(visu->win_w / 2, visu->win_h / 2 + END_SCENE_LABEL_PADDING,
			0, 0));
	sg_set_flags(end->msg, SG_LOCK_SIZE | SG_LOCK_MID);
	sg_set_label_text(end->msg, sg_new_gstr("Unknown player",
		get_resource_path(COREWAR_FONT), (int)(1.5 * COREWAR_TOP_FONT_SIZE)));
	if (!(end->wins = sg_create_label(end->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(end->wins,
		sg_recti(visu->win_w / 2,
			visu->win_h / 2 + END_SCENE_WINS_PADDING_Y, 0, 0));
	sg_set_flags(end->wins, SG_LOCK_SIZE | SG_LOCK_MID);
	sg_set_label_text(end->wins, sg_new_gstr("wins !",
		get_resource_path(COREWAR_FONT), (int)(1.0 * COREWAR_TOP_FONT_SIZE)));
}
