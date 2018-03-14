/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:45:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/14 22:15:42 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		del_instr(void *data)
{
	t_instr		*instr;

	instr = (t_instr *)data;
	free(instr);
}

static void		del_process(void *data)
{
	t_proc		*proc;

	proc = (t_proc *)data;
	del_instr(proc->current_task);
	free(proc);
}

static void		kill_process(t_llist **queue, t_proc *process)
{
	t_llist		*list;

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

void			spawn_process(t_llist **queue, t_proc *process)
{
	static int	id;
	t_llist		*new;

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
static int		run_process_cycle(t_proc *process)
{
	if (!process)
		return (-1);
	if (!process->current_task && !(process->current_task =
			load_instr(process, process->owner->spawn)))
		return (1);
	process->current_task->wait_cycles--;
	if (process->current_task->wait_cycles <= 0)
	{
		if (process->current_task->run_instr)
			process->current_task->run_instr(process->current_task);
		del_instr(process->current_task);
		process->current_task = NULL;
	}
	return (0);
}

void			run_loop(t_champ *champs, int players_count)
{
	int			cycles;
	t_llist		*proc_queue;
	t_llist		*tmp;
	t_llist		*tmp2;
	int			i;

	proc_queue = NULL;
	cycles = 0;
	i = -1;
	while (++i < players_count)
		spawn_process(&proc_queue, load_process(champs + i, champs[i].spawn, NULL));
	while (proc_queue)
	{
		//ft_printf("Running cycle %d\n", cycles);
		tmp = proc_queue;
		while (tmp)
		{
			tmp2 = tmp->next;
			if (run_process_cycle((t_proc *)tmp->data))
				kill_process(&proc_queue, (t_proc *)tmp->data);
			tmp = tmp2;
		}
		cycles++;
	}
}
