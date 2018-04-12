/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:41:23 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 18:05:44 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

static t_process	*find_process(t_visu *visu, int proc_id)
{
	t_llist			*tmp;
	t_process		*tmp_process;

	tmp = visu->process[proc_id % PROCESS_ARRAY_SIZE];
	while (tmp)
	{
		tmp_process = (t_process *)tmp->data;
		if (tmp_process->id == proc_id)
			return (tmp_process);
		tmp = tmp->next;
	}
	return (NULL);
}

void				handle_mem_write(t_visu *visu, t_command *command)
{
	int				addr;
	int				i;
	t_process		*proc;

	if (!visu->mem.data)
		return ;
	addr = read_int(command->data + 4);
	i = -1;
	proc = find_process(visu, read_int(command->data));
	while (++i < 4)
	{
		visu->mem.data[(addr + i) % visu->mem.size] = command->data[8 + i];
		visu->mem.writer[(addr + i) % visu->mem.size] =
			proc ? proc->owner_visu_id : 0;
	}
	visu->mem.new_data = 1;
}
