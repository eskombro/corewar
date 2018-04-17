/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:41:23 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/17 16:25:18 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

void				handle_mem_write(t_visu *visu, t_command *command)
{
	int				addr;
	int				i;
	t_process		*proc;

	if (!visu->mem.data)
		return ;
	addr = read_int(command->data + 4);
	while (addr < 0)
		addr += visu->mem.size;
	i = -1;
	proc = find_process(visu, read_int(command->data));
	while (++i < 4)
	{
		visu->mem.data[(addr + i) % visu->mem.size].content =
			command->data[8 + i];
		visu->mem.data[(addr + i) % visu->mem.size].writer =
			proc ? proc->owner_visu_id : 0;
		visu->mem.data[(addr + i) % visu->mem.size].write_cycle =
			visu->game.cycle;
	}
	visu->mem.new_data = 1;
}
