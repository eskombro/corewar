/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:43:36 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/21 02:56:15 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uchar				*get_arena_visu(void)
{
	static uchar	arena_visu[MEM_SIZE];

	return (arena_visu);
}

void		initialize_arena_visu(t_logic *logic, uchar *arena_writer)
{
	int				champ;
	int				i;

	champ = -1;
	initscr();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	while (++champ < logic->players_count)
	{
		i = logic->champs[champ].spawn - 1;
		while (++i < logic->champs[champ].spawn + logic->champs[champ].size)
			arena_writer[i] = logic->champs[champ].fixed_id;
	}
}

void		update_arena_visu(t_proc *process)
{
	unsigned int	i;
	uchar			*arena_v;
	t_addr			addr;

	i = -1;
	addr = 0;
	arena_v = get_arena_visu();
	if (process->current_task->opcode == 3)
	{
		if (process->current_task->par[1].type != T_RG)
		{
			i = -1;
			addr = (short)process->current_task->par[1].value;
			addr %= IDX_MOD;
			addr += process->owner->spawn + process->pc;
			while (addr < 0)
				addr += MEM_SIZE;
			addr %= MEM_SIZE;
			while (++i < 4)
				arena_v[(addr + i) % MEM_SIZE] = (uchar)process->owner->fixed_id;
		}
	}
	if (process->current_task->opcode == 11)
	{
		i = -1;
		addr = get_parameter_result(process->current_task->par[1], process, 1);
		addr += get_parameter_result(process->current_task->par[2], process, 1);
		addr %= IDX_MOD;
		addr += process->owner->spawn + process->pc;
		while (addr < 0)
			addr += MEM_SIZE;
		addr %= MEM_SIZE;
		while (++i < 4)
			arena_v[(addr + i) % MEM_SIZE] = (uchar)process->owner->fixed_id;
	}
}

void		print_screen(t_logic *logic)
{
	static int		init = 0;
	uchar			*arena;
	uchar			*arena_visu;
	int				x;
	int				y;

	arena = get_arena();
	arena_visu = get_arena_visu();
	!init++ ? initialize_arena_visu(logic, arena_visu) : 0;
	move(0, 0);
	y = -1;
	while (++y < (MEM_SIZE / 64))
	{
		x = -1;
		while (++x < 64)
		{
			attron(COLOR_PAIR((int)(arena_visu[(y * 64) + x] + 1)));
			arena[(y * 64) + x] <= 0xF ? printw("0") : 0;
			printw("%x ", arena[(y * 64) + x]);
		}
		printw("\n");
	}
	attron(COLOR_PAIR(2));
	printw("Cycles: %d\n", logic->cycles);
	attron(COLOR_PAIR(3));
	x = -1;
	while (++x < logic->players_count)
	{
		printw("Player %s \n", logic->champs[x].name);
		printw("Lives: %d \n", logic->champs[x].lives);
	}
	refresh();
	usleep(100);
}
