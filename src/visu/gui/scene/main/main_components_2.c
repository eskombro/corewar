/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_components_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:23:59 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 04:26:05 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main_scene.h"

void					cycles_lbl(t_visu *visu, t_main_scene *main)
{
	if (!(main->cycles_lbl = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->cycles_lbl,
		sg_recti(2 * MAIN_SCENE_MARGIN,
			visu->win_h - 3 * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT, 0, 0));
	sg_set_flags(main->cycles_lbl, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->cycles_lbl, sg_new_gstr("Cycles",
		get_resource_path(COREWAR_FONT), COREWAR_TOP_FONT_SIZE));
	if (!(main->cycles = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->cycles,
		sg_recti(2 * MAIN_SCENE_MARGIN,
			visu->win_h - 3 * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT - COREWAR_TOP_FONT_SIZE, 0, 0));
	sg_set_flags(main->cycles, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->cycles, sg_new_gstr("0",
		get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
}

void					cycles_to_die_lbl(t_visu *visu, t_main_scene *main)
{
	if (!(main->cycles_to_die_lbl = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->cycles_to_die_lbl,
		sg_recti(2 * MAIN_SCENE_MARGIN,
			visu->win_h - 4 * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT - (int)(1.75 * COREWAR_TOP_FONT_SIZE), 0, 0));
	sg_set_flags(main->cycles_to_die_lbl, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->cycles_to_die_lbl, sg_new_gstr("Cycles to die",
		get_resource_path(COREWAR_FONT), COREWAR_TOP_FONT_SIZE));
	if (!(main->cycles_to_die = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->cycles_to_die,
		sg_recti(2 * MAIN_SCENE_MARGIN,
			visu->win_h - 4 * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT - (int)(2.75 * COREWAR_TOP_FONT_SIZE), 0, 0));
	sg_set_flags(main->cycles_to_die, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->cycles_to_die, sg_new_gstr("0",
		get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
}

void					cycles_left_lbl(t_visu *visu, t_main_scene *main)
{
	if (!(main->cycles_left_lbl = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->cycles_left_lbl,
		sg_recti(2 * MAIN_SCENE_MARGIN,
			visu->win_h - 5 * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT - (int)(3.5 * COREWAR_TOP_FONT_SIZE), 0, 0));
	sg_set_flags(main->cycles_left_lbl, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->cycles_left_lbl, sg_new_gstr("Cycles left",
		get_resource_path(COREWAR_FONT), COREWAR_TOP_FONT_SIZE));
	if (!(main->cycles_left = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->cycles_left,
		sg_recti(2 * MAIN_SCENE_MARGIN,
			visu->win_h - 5 * MAIN_SCENE_MARGIN - MAIN_SCENE_TOP_HEIGHT - (int)(4.5 * COREWAR_TOP_FONT_SIZE), 0, 0));
	sg_set_flags(main->cycles_left, SG_LOCK_TOP
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->cycles_left, sg_new_gstr("0",
		get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
}

void					cycles_rate_lbl(t_visu *visu, t_main_scene *main)
{
	char				*tmp;

	visu = 0;
	if (!(main->cycles_rate_lbl = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->cycles_rate_lbl,
		sg_recti(2 * MAIN_SCENE_MARGIN,
			2 * MAIN_SCENE_MARGIN + (int)(1 * COREWAR_TOP_FONT_SIZE), 0, 0));
	sg_set_flags(main->cycles_rate_lbl, SG_LOCK_BOTTOM
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	sg_set_label_text(main->cycles_rate_lbl, sg_new_gstr("Cycles per second",
		get_resource_path(COREWAR_FONT), COREWAR_TOP_FONT_SIZE));
	if (!(main->cycles_rate = sg_create_label(main->ptr)))
		error(ERR_MALLOC, ERR_CRITICAL);
	sg_set_component_boundaries(main->cycles_rate,
		sg_recti(2 * MAIN_SCENE_MARGIN,
			2 * MAIN_SCENE_MARGIN, 0, 0));
	sg_set_flags(main->cycles_rate, SG_LOCK_BOTTOM
		| SG_LOCK_LEFT | SG_LOCK_SIZE
		| SG_ALIGN_RIGHT);
	tmp = ft_itoa(CYCLES_PER_SECOND);
	sg_set_label_text(main->cycles_rate, sg_new_gstr(tmp,
		get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
	free(tmp);
}
