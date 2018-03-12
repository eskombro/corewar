/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:45:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/12 18:14:44 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		del_instr(void *data)
{
	t_instr		*instr;

	instr = (t_instr *)data;
	free(instr->parameters);
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
	t_llist		*new;

	if (!queue)
		return ;
	if (!(new = ft_llist_new(process)))
		exit(1);
	ft_llist_front(queue, new);
}

/*
** Runs cycle for a single process. Returns 0 if OK, 1 if process crashes.
*/
static int		run_process_cycle(t_proc *process)
{
	process = 0;
	return (0);
}

void			run_loop(void)
{
	int			cycles;
	t_llist		*process_queue;
	t_llist		*tmp;

	process_queue = NULL;
	cycles = 0;
	while (1)
	{
		tmp = process_queue;
		while (tmp)
		{
			if (run_process_cycle((t_proc *)tmp->data))
				kill_process(&process_queue, (t_proc *)tmp->data);
			tmp = tmp->next;
		}
	}
}
