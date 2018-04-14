/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:37:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/14 18:20:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

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
	proc->owner_spawn = player ? player->spawn : 0;
	proc->pc = read_int(command->data + 8);
	while (proc->pc < 0)
		proc->pc += visu->mem.size;
	push_proc(visu, proc);
	proc_add(visu, proc);
}

void				handle_proc_move(t_visu *visu, t_command *command)
{
	t_process		*proc;
	int				id;

	if (!visu->mem.data)
		return ;
	id = read_int(command->data);
	proc = find_process(visu, id);
	proc_remove(visu, proc);
	proc->pc = read_int(command->data + 4);
	while (proc->pc < 0)
		proc->pc += visu->mem.size;
	proc_add(visu, proc);
}

void				handle_proc_death(t_visu *visu, t_command *command)
{
	t_process		*proc;
	int				id;

	if (!visu->mem.data)
		return ;
	id = read_int(command->data);
	proc = find_process(visu, id);
	proc_remove(visu, proc);
}
