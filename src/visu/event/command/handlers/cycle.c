/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:21:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/15 19:23:38 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

void				update_cycles_to_die(t_visu *visu, int cycles_to_die)
{
	char			*tmp;

	tmp = ft_itoa(cycles_to_die);
	sg_set_label_text(
		visu->gui.scenes[COREWAR_SCENE_MAIN].main.cycles_to_die,
		sg_new_gstr(tmp,
			get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
	free(tmp);
}

void				update_labels(t_visu *visu, int cycles, int cycles_left)
{
	char			*tmp;

	tmp = ft_itoa(cycles);
	sg_set_label_text(
		visu->gui.scenes[COREWAR_SCENE_MAIN].main.cycles,
		sg_new_gstr(tmp,
			get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
	free(tmp);
	tmp = ft_itoa(cycles_left);
	sg_set_label_text(
		visu->gui.scenes[COREWAR_SCENE_MAIN].main.cycles_left,
		sg_new_gstr(tmp,
			get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
	free(tmp);
}

void				handle_new_cycle(t_visu *visu, t_command *command)
{
	int				new_cycles_to_die;

	visu->game.cycle = read_int(command->data);
	new_cycles_to_die = read_int(command->data + 4);
	if (new_cycles_to_die != visu->game.cycle_to_die)
	{
		visu->game.cycle_to_die = new_cycles_to_die;
		update_cycles_to_die(visu, visu->game.cycle_to_die);
	}
	visu->game.cycle_left = read_int(command->data + 8);
	update_labels(visu, visu->game.cycle, visu->game.cycle_left);
	if (visu->game.cycle_left == 0)
		visu->game.check_cycle = visu->game.cycle;
}
