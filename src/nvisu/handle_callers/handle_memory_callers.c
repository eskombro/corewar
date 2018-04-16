/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_memory_callers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:40:50 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/15 02:45:24 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

int				find_proc_owner_nb(int proc_id)
{
	int			nb;
	t_v_proc	*proc;

	nb = 0;
	proc = get_visu()->procs[proc_id % PROC_TAB_SIZE];
	while (proc && proc->id != proc_id)
		proc = proc->next;
	while (nb < get_visu()->champ_nb &&
		proc && get_visu()->champs[nb] != proc->owner)
		nb++;
	return (nb);
}

void			handle_mem_write(t_command *command)
{
	int			final_address;
	int			value;
	int			pos_y;
	int			pos_x;
	int			i;

	i = -1;
	final_address = read_int(command->data + 4);
	while (final_address < 0)
		final_address += get_visu()->m_size;
	value = read_int(command->data + 8);
	attron(COLOR_PAIR(find_proc_owner_nb(read_int(command->data)) + 12));
	while (++i < 4)
	{
		pos_y = get_visu()->start_y + (((final_address % get_visu()->m_size)
			/ MEM_TAB_LENGTH));
		pos_x = get_visu()->start_x + (3 * ((final_address % get_visu()->m_size)
			% MEM_TAB_LENGTH));
		mvprintw(pos_y, pos_x, "%2.2x ", ((value & (0xFF000000)) >> 24));
		value <<= 8;
		final_address++;
	}
}
