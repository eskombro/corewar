/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:45:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/15 23:03:12 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_logic			*get_logic(void)
{
	static t_logic		logic;

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

void					report_live(unsigned long player)
{
	t_logic				*logic;
	int					i;

	logic = get_logic();
	i = -1;
	while (++i < logic->players_count)
	{
		if (logic->champs[i].id == player)
		{
			logic->champs[i].lives++;
			ft_printf("Player %s (%d) reported as alive\n", logic->champs[i].name, player);
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
			load_instr(process, process->owner->spawn)))
		return (1);
	process->current_task->wait_cycles--;
	if (process->current_task->wait_cycles <= 0)
	{
		if (process->current_task->opcode)
			debug_instr(get_logic()->cycles, process->current_task, process);
		pc = process->pc;
		if (process->current_task->run_instr)
		{
			process->current_task->run_instr(process);
			ft_printf("  Carry: %d\n", process->carry);
			debug_reg(process);
		}
		if (process->pc == pc)
			process->pc += process->current_task->mem_size;
		del_instr(process->current_task);
		process->current_task = NULL;
	}
	return (0);
}

void					run_loop(t_champ *champs, int players_count)
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
		spawn_process(load_process(champs + i, champs[i].spawn, NULL));
	while (logic->queue && logic->cycles < 1600)
	{
		//ft_printf("Running cycle %d\n", cycles);
		tmp = logic->queue;
		while (tmp)
		{
			tmp2 = tmp->next;
			if (run_process_cycle((t_proc *)tmp->data))
				kill_process((t_proc *)tmp->data);
			tmp = tmp2;
		}
		logic->cycles++;
	}
}
