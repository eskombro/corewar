/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_logic_callers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:38:24 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/15 02:44:34 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

void			handle_logic_cycle(t_command *command)
{
	int			i;

	i = 0;
	get_visu()->stats->cycles = read_int(command->data);
	get_visu()->stats->cycles_to_die = read_int(command->data + 4);
	get_visu()->stats->cycles_left = read_int(command->data + 8);
	if (get_visu()->stats->cycles_left == 0)
	{
		while (i < get_visu()->champ_nb)
			get_visu()->champs[i++]->lifes_round = 0;
	}
	display_leaderboard();
}

void			handle_logic_life(t_command *command)
{
	int		proc_id;
	int		champ_nb;

	proc_id = read_int(command->data);
	champ_nb = find_proc_owner_nb(proc_id);
	get_visu()->champs[champ_nb]->lifes++;
	get_visu()->champs[champ_nb]->lifes_round++;
	ft_strncpy(get_visu()->stats->last_life,
		get_visu()->champs[champ_nb]->name, 15);
	display_stats();
}
