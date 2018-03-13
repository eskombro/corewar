/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:45:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/13 13:16:06 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		del_instr(void *data)
{
	t_instr		*instr;

	instr = (t_instr *)data;
	free(instr->par);
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
			ft_llist_rem(queue, list, &del_process);
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
** did not report as alive.
*/
static int		run_process_cycle(t_proc *process)
{
	process = 0;
	return (0);
}

void			run_loop(t_champ *champs)
{
	int			cycles;
	t_llist		*proc_queue;
	t_llist		*tmp;

	proc_queue = NULL;
	cycles = 0;
	while (champs)
	{
		spawn_process(&proc_queue, load_process(champs, champs->spawn, NULL));
		champs++;
	}
	while (proc_queue)
	{
		tmp = proc_queue;
		while (tmp)
		{
			if (run_process_cycle((t_proc *)tmp->data))
				kill_process(&proc_queue, (t_proc *)tmp->data);
			tmp = tmp->next;
		}
		cycles++;
	}
}
