/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:43:36 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/21 04:13:38 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uchar		*get_arena_visu(void)
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
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(11, COLOR_BLUE, COLOR_WHITE);
	init_pair(12, COLOR_GREEN, COLOR_WHITE);
	init_pair(13, COLOR_RED, COLOR_WHITE);
	init_pair(14, COLOR_YELLOW, COLOR_WHITE);
	init_pair(15, COLOR_WHITE, COLOR_WHITE);
	init_pair(16, COLOR_CYAN, COLOR_WHITE);
	while (++champ < logic->players_count)
	{
		i = logic->champs[champ].spawn - 1;
		while (++i < logic->champs[champ].spawn + logic->champs[champ].size)
			arena_writer[i] = logic->champs[champ].fixed_id;
	}
}

void		visu_handle_st(t_proc *process)
{
	t_addr			addr;
	unsigned int	i;
	uchar			*arena_v;

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
			arena_v[(addr + i) % MEM_SIZE] = (uchar)process->owner->fixed_id;
	}
}

void		visu_handle_sti(t_proc *process)
{
	t_addr			addr;
	unsigned int	i;
	uchar			*arena_v;

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
		arena_v[(addr + i) % MEM_SIZE] = (uchar)process->owner->fixed_id;
}

void		update_arena_visu(t_proc *process)
{

	if (process->current_task->opcode == 3)
		visu_handle_st(process);
	else if (process->current_task->opcode == 11)
		visu_handle_sti(process);
}

void		display_scoreboard(t_logic *logic)
{
	int				x;
	int				last_line;

	attron(COLOR_PAIR(6));
	x = -1;
	while (++x < (COLS - ((64 * 2) + 63) )/2)
		printw(" ");
	printw("------------------------------------------------------------");
	printw("------------------------------------------------------------");
	printw("------------------------------------------------------------");
	printw("-----------\n");
	x = -1;
	while (++x < (COLS - ((64 * 2) + 63) )/2)
		printw(" ");
	printw("   Cycles:           %d\n", logic->cycles);
	x = -1;
	while (++x < (COLS - ((64 * 2) + 63) )/2)
		printw(" ");
	printw("   Cycles to die:    %d\n", logic->cycles_to_die);
	x = -1;
	while (++x < (COLS - ((64 * 2) + 63) )/2)
		printw(" ");
	printw("   Cycles left:      %d\n", logic->cycles_left);
	x = -1;
	last_line = (MEM_SIZE / 64) + 2;
	while (++x < logic->players_count)
	{
		attron(COLOR_PAIR(logic->champs[x].fixed_id + 1));
		move(last_line++, (COLS - ((64 * 2) + 63) )/2 + 60);
		printw("   Player:           ", logic->champs[x].name, logic->champs[x].id);
		printw("%s (%d) \n", logic->champs[x].name, logic->champs[x].id);
		move(last_line++, (COLS - ((64 * 2) + 63) )/2 + 60);
		printw("   Lives:            %d \n", logic->champs[x].lives);
	}
}

void		display_arena(uchar *arena)
{
	int				x;
	int				y;
	uchar			*arena_visu;

	x = -1;
	y = -1;
	move(0, 0);
	attron(COLOR_PAIR(6));
	arena_visu = get_arena_visu();
	while (++x < (COLS - ((64 * 2) + 63) )/2)
		printw(" ");
	printw("------------------------------------------------------------");
	printw("------------------------------------------------------------");
	printw("------------------------------------------------------------");
	printw("-----------\n");
	while (++y < (MEM_SIZE / 64))
	{
		x = -1;
		while (++x < (COLS - ((64 * 2) + 63) )/2)
			printw(" ");
		x = -1;
		while (++x < 64)
		{
			attron(COLOR_PAIR((int)(arena_visu[(y * 64) + x] + 1)));
			arena[(y * 64) + x] <= 0xF ? printw("0") : 0;
			printw("%x ", arena[(y * 64) + x]);
		}
		printw("\n");
	}
}

void		display_process(t_logic *logic)
{
	t_llist				*tmp;
	uchar				*arena_visu;
	t_proc				*proc;
	int		p;

	p = -1;
	arena_visu = get_arena_visu();
	tmp = logic->queue;
	while (tmp)
	{
		proc = (t_proc *)tmp->data;
		arena_visu[(proc->owner->spawn + proc->pc) % MEM_SIZE] += 9;
		tmp = tmp->next;
	}
}

void		print_screen(t_logic *logic)
{
	static int		init = 0;
	uchar			*arena;
	uchar			*arena_visu;
	int				delay;

	delay = 100;
	arena = get_arena();
	arena_visu = get_arena_visu();
	!init++ ? initialize_arena_visu(logic, arena_visu) : 0;
	display_arena(arena);
	//display_process(logic);
	display_scoreboard(logic);
	refresh();
	usleep(delay);
}
