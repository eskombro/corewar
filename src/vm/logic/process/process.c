/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:00:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 22:40:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../logic.h"

t_proc					*load_process(t_champ *owner, t_addr addr, t_proc *parent)
{
	t_proc				*process;
	int					i;

	if (!(process = (t_proc *)ft_memalloc(sizeof(t_proc))))
		exit(1);
	process->owner = owner;
	while (addr < 0)
		addr += MEM_SIZE;
	process->pc = addr % MEM_SIZE;
	if (parent)
	{
		process->carry = parent->carry;
		process->alive = parent->alive;
		i = -1;
		while (++i < REG_NUMBER)
			ft_memcpy(process->reg[i], parent->reg[i], sizeof(t_reg));
	}
	else
		write_reg(process->reg[0], owner->id);
	return (process);
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

void					del_process(void *data)
{
	t_proc				*proc;

	proc = (t_proc *)data;
	del_instr(proc->current_task);
	free(proc);
}

void					kill_process(t_proc *process)
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
