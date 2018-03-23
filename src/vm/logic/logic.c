/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:45:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 23:25:48 by hbouillo         ###   ########.fr       */
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
	return (&logic);
}

/*
** Runs cycle for a single process. Returns 0 if OK, 1 if process crashes or
** did not report as alive, and -1 in case of error.
*/

static int				run_process_cycle(t_proc *process)
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
			if (get_logic()->params.verbose >= 0)
				verbose(process);
			process->current_task->run_instr(process);
			get_logic()->params.ncurse ? update_arena_visu(process) : 0;
		}
		if (!(process->current_task->opcode == I_ZJMP && process->carry == 1))
			process->pc += process->current_task->mem_size;
		process->pc %= MEM_SIZE;
		del_instr(process->current_task);
		process->current_task = NULL;
	}
	return (0);
}

static void				run_cycle(void)
{
	t_logic				*logic;
	t_llist				*tmp;
	t_llist				*tmp2;

	logic = get_logic();
	tmp = logic->queue;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (run_process_cycle((t_proc *)tmp->data))
			kill_process((t_proc *)tmp->data);
		tmp = tmp2;
	}
	check_lives();
	logic->params.ncurse ? print_screen(logic) : 0;
	logic->cycles_left--;
}

void					run_loop(t_champ *champs)
{
	t_logic				*logic;
	int					i;

	logic = get_logic();
	logic->params = get_params();
	logic->champs = champs;
	i = -1;
	while (++i < logic->params.players)
		spawn_process(load_process(champs + i, 0, NULL));
	while (logic->queue && (logic->params.dump < 0 ||
		logic->cycles <= logic->params.dump))
	{
		logic->cycles++;
		run_cycle();
	}
	endwin();
	if (logic->params.dump >= 0)
		print_arena_dump();
	else if (logic->last_live)
		ft_printf("Player %s (%d) won at cycle %d.\n", logic->last_live->name,
			logic->last_live->id, logic->cycles);
}
