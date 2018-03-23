/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lives.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:42:55 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 22:43:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"

void					report_live(t_proc *process, int player)
{
	t_logic				*logic;
	int					i;

	logic = get_logic();
	i = -1;
	while (++i < logic->players_count)
		if (logic->champs[i].id == player)
		{
			logic->champs[i].lives++;
			logic->last_live = logic->champs + i;
		}
	logic->lives++;
	process->alive = 1;
}

void					check_lives(void)
{
	static int			nodecrement_checks;
	t_logic				*logic;
	t_llist				*tmp;
	t_llist				*tmp2;

	logic = get_logic();
	if (logic->cycles_left <= 0)
	{
		tmp = logic->queue;
		while (tmp)
		{
			tmp2 = tmp->next;
			if (!((t_proc *)tmp->data)->alive)
				kill_process((t_proc *)tmp->data);
			else
				((t_proc *)tmp->data)->alive = 0;
			tmp = tmp2;
		}
		nodecrement_checks++;
		if (logic->lives >= NBR_LIVE || nodecrement_checks >= MAX_CHECKS)
		{
			nodecrement_checks = 0;
			logic->cycles_to_die -= CYCLE_DELTA;
		}
		logic->lives = 0;
		logic->cycles_left = logic->cycles_to_die;
	}
}