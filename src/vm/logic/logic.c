/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:45:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 22:45:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"

t_logic					*get_logic(void)
{
	static int			set;
	static t_logic		logic;

	if (!set)
	{
		set = 1;
		logic.cycles_to_die = CYCLE_TO_DIE;
		logic.cycles_left = CYCLE_TO_DIE;
	}
	return  (&logic);
}

/*
** Runs cycle for a single process. Returns 0 if OK, 1 if process crashes or
** did not report as alive, and -1 in case of error.
*/
static int				run_process_cycle(t_proc *process, t_params *params)
{
	if (!process)
		return (-1);
	if (!process->current_task && !(process->current_task =
			load_instr(process)))
		return (1);
	process->current_task->wait_cycles--;
	if (process->current_task->wait_cycles <= 0)
	{
		if (process->current_task->opcode)
			fill_instr(process);
		if (process->current_task->run_instr)
		{
			if (params->verbose >= 0)
				verbose(process);
			process->current_task->run_instr(process);
			params->ncurse ? update_arena_visu(process) : 0;
		}
		if (!(process->current_task->opcode == I_ZJMP && process->carry == 1))
			process->pc += process->current_task->mem_size;
		process->pc %= MEM_SIZE;
		del_instr(process->current_task);
		process->current_task = NULL;
	}
	return (0);
}

void					run_loop(t_champ *champs)
{
	t_logic				*logic;
	t_llist				*tmp;
	t_llist				*tmp2;
	t_params			params;
	int					i;

	logic = get_logic();
	params = get_params();
	logic->players_count = params.players;
	logic->champs = champs;
	i = -1;
	while (++i < params.players)
		spawn_process(load_process(champs + i, 0, NULL));
	while (logic->queue && (params.dump < 0 || logic->cycles <= params.dump))
	{
		logic->cycles++;
		tmp = logic->queue;
		while (tmp)
		{
			tmp2 = tmp->next;
			if (run_process_cycle((t_proc *)tmp->data, &params))
				kill_process((t_proc *)tmp->data);
			tmp = tmp2;
		}
		check_lives();
		params.ncurse ? print_screen(logic) : 0;
		logic->cycles_left--;
	}
	endwin();
	if (params.dump >= 0)
		print_arena_dump();
	else if (logic->last_live)
		ft_printf("Player %s (%d) won at cycle %d.\n", logic->last_live->name,
			logic->last_live->id, logic->cycles);
	ft_printf("The End\n");
}
