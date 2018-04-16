/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 04:32:22 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 17:07:37 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

void				init_player_info_gui(t_visu *visu, t_player *player)
{
	t_llist			*new;
	t_player_info	*pinfo;
	t_main_scene	*main;
	char			*tmp;

	if (!(pinfo = (t_player_info *)malloc(sizeof(t_player_info))) ||
		!(new = ft_llist_new(pinfo)))
		error(ERR_MALLOC, ERR_CRITICAL);
	main = &(visu->gui.scenes[COREWAR_SCENE_MAIN].main);
	ft_llist_back(&main->p_infos, new);
	pinfo->player = player;
	if (!(pinfo->name = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(pinfo->name,
		sg_recti(visu->win_w - 2 * MAIN_SCENE_MARGIN,
			visu->win_h - (2 + player->visu_id) * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT - (int)(((player->visu_id - 1) * 2.5) * COREWAR_TOP_FONT_SIZE), 0, 0));
	sg_set_flags(pinfo->name, SG_LOCK_TOP
		| SG_LOCK_RIGHT | SG_LOCK_SIZE
		| SG_ALIGN_LEFT);
	sg_set_label_text(pinfo->name, sg_new_gstr(player->name,
		get_resource_path(COREWAR_FONT), COREWAR_TOP_FONT_SIZE));
	if (!(pinfo->id = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(pinfo->id,
		sg_recti(visu->win_w - (int)(2.5 * MAIN_SCENE_MARGIN),
			visu->win_h - (2 + player->visu_id) * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT - (int)(((player->visu_id) * 2.5 - 1.5) * COREWAR_TOP_FONT_SIZE), 0, 0));
	sg_set_flags(pinfo->id, SG_LOCK_TOP
		| SG_LOCK_RIGHT | SG_LOCK_SIZE
		| SG_ALIGN_LEFT);
	tmp = ft_itoa(player->vm_id);
	sg_set_label_text(pinfo->id, sg_new_gstr(tmp,
		get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
	if (!(pinfo->alive = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(pinfo->alive,
		sg_recti(visu->win_w - (int)(2.5 * MAIN_SCENE_MARGIN),
			visu->win_h - (2 + player->visu_id) * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT - (int)(((player->visu_id) * 2.5 - 0.75) * COREWAR_TOP_FONT_SIZE), 0, 0));
	sg_set_flags(pinfo->alive, SG_LOCK_TOP
		| SG_LOCK_RIGHT | SG_LOCK_SIZE
		| SG_ALIGN_LEFT);
	sg_set_label_text(pinfo->alive, sg_new_gstr("-----",
		get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
	sg_set_label_color(pinfo->name, *pinfo->player->color);
	sg_set_label_color(pinfo->id, *pinfo->player->color);
	sg_set_label_color(pinfo->alive, *pinfo->player->color);
}
