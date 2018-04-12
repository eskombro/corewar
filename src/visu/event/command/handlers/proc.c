/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:37:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 18:05:32 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

static t_player		*find_player(t_visu *visu, int vm_id)
{
	t_llist			*tmp;
	t_player		*tmp_player;

	tmp = visu->players;
	while (tmp)
	{
		tmp_player = (t_player *)tmp->data;
		if (tmp_player->vm_id == vm_id)
			return (tmp_player);
		tmp = tmp->next;
	}
	return (NULL);
}

static void			push_proc(t_visu *visu, t_process *proc)
{
	t_llist			*new;
	int				array;

	if (!(new = ft_llist_new(proc)))
		error(ERR_MALLOC, ERR_CRITICAL);
	array = proc->id % PROCESS_ARRAY_SIZE;
	ft_llist_back(visu->process + array, new);
}

void				handle_proc_spawn(t_visu *visu, t_command *command)
{
	t_process		*proc;
	t_player		*player;
	int				i;

	if (!visu->mem.data)
		return ;
	if (!(proc = (t_process *)ft_memalloc(sizeof(t_process))))
		error(ERR_MALLOC, ERR_CRITICAL);
	proc->id = read_int(command->data);
	proc->owner_id = read_int(command->data + 4);
	player = find_player(visu, proc->owner_id);
	proc->owner_visu_id = player ? player->visu_id : 0;
	proc->pc = read_int(command->data + 8);
	push_proc(visu, proc);
}
