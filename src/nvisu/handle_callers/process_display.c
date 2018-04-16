/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:48:32 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/15 03:01:02 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

int				display_proc_pc_calc(int col, int pc_rel_spawn)
{
	if (col == 1 || (col >= 12 && col <= 15))
	{
		if (get_visu()->mem_proc[pc_rel_spawn % get_visu()->m_size] == 1)
			col += 10;
	}
	else if (col == 11 || (col >= 22 && col <= 25))
	{
		if (get_visu()->mem_proc[pc_rel_spawn % get_visu()->m_size] == 0)
			col -= 10;
	}
	return (col);
}

void			display_proc_pc(t_v_proc *proc)
{
	int			i;
	int			pos_x;
	int			pos_y;
	char		chstr[3];
	int			pc_rel_spawn;

	i = 0;
	while (get_visu()->champs[i]->id != proc->owner_id)
		i++;
	pc_rel_spawn = proc->pc + proc->owner->spawn;
	while (pc_rel_spawn < 0)
		pc_rel_spawn += get_visu()->m_size;
	pos_y = get_visu()->start_y + (((pc_rel_spawn
		% get_visu()->m_size) / MEM_TAB_LENGTH));
	pos_x = get_visu()->start_x + (3 * ((pc_rel_spawn
		% get_visu()->m_size) % MEM_TAB_LENGTH));
	chstr[0] = mvinch(pos_y, pos_x) & A_CHARTEXT;
	chstr[1] = mvinch(pos_y, pos_x + 1) & A_CHARTEXT;
	chstr[2] = 0;
	attron(COLOR_PAIR(display_proc_pc_calc(
		((mvinch(pos_y, pos_x) & A_COLOR) % 255), pc_rel_spawn)));
	move(pos_y, pos_x);
	printw(chstr);
}
