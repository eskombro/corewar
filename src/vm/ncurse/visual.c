/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:43:36 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/23 23:41:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurse_visu.h"

void				visu_handle_st(t_proc *process)
{
	t_addr			addr;
	unsigned int	i;
	t_uchar			*arena_v;

	arena_v = get_arena_visu();
	addr = 0;
	i = -1;
	if (process->current_task->par[1].type != T_RG)
	{
		addr = (short)process->current_task->par[1].value;
		addr %= IDX_MOD;
		addr += process->owner->spawn + process->pc;
		while (addr < 0)
			addr += MEM_SIZE;
		addr %= MEM_SIZE;
		while (++i < 4)
			arena_v[(addr + i) % MEM_SIZE] = (t_uchar)process->owner->fixed_id;
	}
}

void				visu_handle_sti(t_proc *process)
{
	t_addr			addr;
	unsigned int	i;
	t_uchar			*arena_v;

	arena_v = get_arena_visu();
	addr = 0;
	i = -1;
	addr = get_parameter_result(process->current_task->par[1], process, 1);
	addr += get_parameter_result(process->current_task->par[2], process, 1);
	addr %= IDX_MOD;
	addr += process->owner->spawn + process->pc;
	while (addr < 0)
		addr += MEM_SIZE;
	addr %= MEM_SIZE;
	while (++i < 4)
		arena_v[(addr + i) % MEM_SIZE] = (t_uchar)process->owner->fixed_id;
}

void				update_arena_visu(t_proc *process)
{
	if (process->current_task->opcode == 3)
		visu_handle_st(process);
	else if (process->current_task->opcode == 11)
		visu_handle_sti(process);
}

void				display_line_separator(void)
{
	int				x;

	x = -1;
	attron(COLOR_PAIR(6));
	while (++x < (COLS - ((64 * 2) + 63)) / 2)
		printw(" ");
	printw("------------------------------------------------------------");
	printw("------------------------------------------------------------");
	printw("------------------------------------------------------------");
	printw("-----------\n");
}

void				print_screen(t_logic *logic)
{
	static int		init;
	t_uchar			*arena;
	t_uchar			*arena_visu;
	int				delay;

	initscr();
	delay = logic->cycles <= 22600 ? 1 : NCURSE_DELAY;
	arena = get_arena();
	arena_visu = get_arena_visu();
	!init++ ? initialize_arena_visu(logic, arena_visu) : 0;
	display_arena(arena);
	display_process(logic);
	display_scoreboard(logic);
	refresh();
	usleep(delay);
}
