/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:18:49 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/06 19:18:30 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gui.h"

static t_color_set		set_from_tab(int *color_set)
{
	t_color_set			set;

	set.background = sg_color(color_set[0]);
	set.main_text = sg_color(color_set[1]);
	set.display_edge = sg_color(color_set[2]);
	set.display_grid = sg_color(color_set[3]);
	set.button_hover = sg_color(color_set[4]);
	set.button_pressed = sg_color(color_set[5]);
	return (set);
}

static t_color_set		*get_color_set(int set)
{
	static int			init;
	static t_color_set	sets[10];

	if (!init)
	{
		sets[init++] = set_from_tab((int[6]) { 0x252525, 0xe2e2e2, 0xe2e2e2,
			0xaf252525, 0x3a3a3a, 0x606060 });
		sets[init++] = set_from_tab((int[6]) { 0xe2e2e2, 0x565656, 0x565656,
			0xafe2e2e2, 0xcecece, 0xbcbcbc });
		sets[init++] = set_from_tab((int[6]) { 0xe2e2e2, 0x565656, 0x565656,
			0xafe2e2e2, 0xc593ff, 0xff8787 });
		sets[init++] = set_from_tab((int[6]) { 0x000000, 0xf5b553, 0xf5b553,
			0xaf000000, 0x222222, 0x333333 });
		sets[init++] = set_from_tab((int[6]) { 0xffdddd, 0xff7777, 0xff7777,
			0xafffdddd, 0xffb7b7, 0xffa0a0 });
		sets[init++] = set_from_tab((int[6]) { 0x08085e, 0xe8fcf6, 0xe8fcf6,
			0xaf08085e, 0x232368, 0x383877 });
	}
	if (set >= init)
		set = 0;
	return (&(sets[set]));
}

void					set_color_set(t_visu *visu, int set)
{
	visu->gui.colors = get_color_set(set);
	// if (show->gui.scenes[FILLER_SCENE_MAIN].ptr)
	// 	main_update_colors(show, &(show->gui.scenes[FILLER_SCENE_MAIN].main));
	// if (show->gui.scenes[FILLER_SCENE_END].ptr)
	// 	end_update_colors(show, &(show->gui.scenes[FILLER_SCENE_END].end));
	glClearColor(visu->gui.colors->background.r, visu->gui.colors->background.g,
		visu->gui.colors->background.b, visu->gui.colors->background.a);
}
