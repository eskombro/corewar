/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:45:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/19 21:27:47 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_logic			*get_logic(void)
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

static void				del_instr(void *data)
{
	t_instr				*instr;

	instr = (t_instr *)data;
	free(instr);
}

static void				del_process(void *data)
{
	t_proc				*proc;

	proc = (t_proc *)data;
	del_instr(proc->current_task);
	free(proc);
}

static void				kill_process(t_proc *process)
{
	t_llist				**queue;
	t_llist				*list;

	queue = &(get_logic()->queue);
	if (!queue)
		return ;
	list = *queue;
	while (list)
	{
		if (list->data == process)
		{
			ft_llist_rem(queue, list, &del_process);
			return ;
		}
		list = list->next;
	}
}

void					report_live(t_proc *process, int player)
{
	t_logic				*logic;
	int					i;

	logic = get_logic();
	i = -1;
	process->alive = 1;
	while (++i < logic->players_count)
	{
		if (logic->champs[i].id == player)
		{
			logic->champs[i].lives++;
			logic->last_live = logic->champs + i;
			logic->valid_lives++;
			//debug_live_report(process, logic->champs + i);
		}
	}
}

void					spawn_process(t_proc *process)
{
	t_llist				**queue;
	static int			id;
	t_llist				*new;

	queue =&(get_logic()->queue);
	if (!queue)
		return ;
	process->id = id++;
	if (!(new = ft_llist_new(process)))
		exit(1);
	ft_llist_front(queue, new);
}

/*
** Runs cycle for a single process. Returns 0 if OK, 1 if process crashes or
** did not report as alive, and -1 in case of error.
*/
static int				run_process_cycle(t_proc *process)
{
	int					pc;

	if (!process)
		return (-1);
	if (!process->current_task && !(process->current_task =
			load_instr(process)))
	{
//		debug_process_crash(process);
		return (1);
	}
	process->current_task->wait_cycles--;
	if (process->current_task->wait_cycles <= 0)
	{
		if (process->current_task->opcode)
			debug_instr(get_logic()->cycles, process->current_task, process);
		pc = process->pc;
		if (process->current_task->run_instr)
		{
			process->current_task->run_instr(process);
			verbose(process);
			// ft_printf("  Carry: %d\n", process->carry);
//			debug_reg(process);
//			print_arena();
		}
		if (process->pc == pc)
			process->pc += process->current_task->mem_size;
		process->pc %= MEM_SIZE;
		del_instr(process->current_task);
		process->current_task = NULL;
	}
	return (0);
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
		if (logic->valid_lives >= NBR_LIVE || nodecrement_checks >= MAX_CHECKS)
		{
			nodecrement_checks = 0;
			logic->cycles_to_die -= CYCLE_DELTA;
			ft_printf("CYCLES DECREM %d at cycle %d (lives %d)\n", logic->cycles_to_die, logic->cycles, logic->valid_lives);
		}
		logic->valid_lives = 0;
		logic->cycles_left = logic->cycles_to_die;
	}
}

void					run_loop(t_champ *champs, int players_count, int dump)
{
	t_logic				*logic;
	t_llist				*tmp;
	t_llist				*tmp2;
	int					i;

	logic = get_logic();
	logic->players_count = players_count;
	logic->champs = champs;
	i = -1;
	while (++i < players_count)
		spawn_process(load_process(champs + i, 0, NULL));
	while (logic->queue && (dump < 0 || logic->cycles <= dump))
	{
		logic->cycles++;
		tmp = logic->queue;
		while (tmp)
		{
			tmp2 = tmp->next;
			if (run_process_cycle((t_proc *)tmp->data))
				kill_process((t_proc *)tmp->data);
			tmp = tmp2;
		}
		check_lives();
		logic->cycles_left--;
	}
	if (dump >= 0)
		print_arena_dump();
	else if (logic->last_live)
		ft_printf("Player %s (%d) won at cycle %d.\n", logic->last_live->name,
			logic->last_live->id, logic->cycles);
	ft_printf("The End\n");
}
