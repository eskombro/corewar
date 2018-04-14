/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:52:02 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/14 18:17:12 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

void				push_proc(t_visu *visu, t_process *proc)
{
	t_llist			*new;
	int				array;

	if (!(new = ft_llist_new(proc)))
		error(ERR_MALLOC, ERR_CRITICAL);
	array = proc->id % PROCESS_ARRAY_SIZE;
	ft_llist_back(visu->process + array, new);
}

void				proc_add(t_visu *visu, t_process *proc)
{
	t_llist			*new;

	if (!(new = ft_llist_new(proc)))
		error(ERR_MALLOC, ERR_CRITICAL);
	ft_llist_back(
		&visu->mem.data[(proc->pc + proc->owner_spawn) % visu->mem.size].procs,
		new);
}

void				proc_remove(t_visu *visu, t_process *proc)
{
	t_llist			*tmp;
	t_process		*tmp_proc;

	tmp = visu->mem.data[(proc->pc + proc->owner_spawn) % visu->mem.size].procs;
	while (tmp)
	{
		tmp_proc = (t_process *)tmp->data;
		if (tmp_proc == proc)
		{
			ft_llist_rem(&visu->mem.data[
					(proc->pc + proc->owner_spawn) % visu->mem.size].procs,
				tmp, NULL);
			break ;
		}
		tmp = tmp->next;
	}
}
