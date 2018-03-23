/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:33:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 23:41:00 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ncurse_visu.h"

void				display_players_info(t_logic *logic)
{
	int				x;
	int				last_line;

	x = -1;
	last_line = (MEM_SIZE / 64) + 2;
	while (++x < logic->params.players)
	{
		attron(COLOR_PAIR(logic->champs[x].fixed_id + 1));
		move(last_line++, (COLS - ((64 * 2) + 63)) / 2 + 60);
		printw("   ");
		printw("Player:        ", logic->champs[x].name, logic->champs[x].id);
		printw("   %s (%d) \n", logic->champs[x].name, logic->champs[x].id);
		move(last_line++, (COLS - ((64 * 2) + 63)) / 2 + 60);
		printw("   Lives:            %d \n", logic->champs[x].lives);
	}
}

void				display_scoreboard(t_logic *logic)
{
	int				x;

	x = -1;
	display_line_separator();
	while (++x < (COLS - ((64 * 2) + 63)) / 2)
		printw(" ");
	printw("   Cycles:           %d\n", logic->cycles);
	x = -1;
	while (++x < (COLS - ((64 * 2) + 63)) / 2)
		printw(" ");
	printw("   Cycles to die:    %d\n", logic->cycles_to_die);
	x = -1;
	while (++x < (COLS - ((64 * 2) + 63)) / 2)
		printw(" ");
	printw("   Cycles left:      %d\n", logic->cycles_left);
	display_players_info(logic);
}

void				display_arena_line(t_uchar *arena, t_uchar *arena_visu,
						int y)
{
	int				x;

	x = -1;
	while (++x < (COLS - ((64 * 2) + 63)) / 2)
		printw(" ");
	x = -1;
	while (++x < 64)
	{
		attron(COLOR_PAIR((int)(arena_visu[(y * 64) + x] + 1)));
		arena[(y * 64) + x] <= 0xF ? printw("0") : 0;
		printw("%x", arena[(y * 64) + x]);
		attron(COLOR_PAIR(1));
		printw(" ");
	}
	printw("\n");
}

void				display_arena(t_uchar *arena)
{
	int				y;
	t_uchar			*arena_visu;

	y = -1;
	move(0, 0);
	attron(COLOR_PAIR(6));
	arena_visu = get_arena_visu();
	display_line_separator();
	while (++y < (MEM_SIZE / 64))
		display_arena_line(arena, arena_visu, y);
}

void				display_process(t_logic *logic)
{
	t_llist			*tmp;
	t_uchar			*arena_visu;
	t_proc			*proc;
	int				p;

	p = -1;
	arena_visu = get_arena_visu();
	while (++p < MEM_SIZE)
		arena_visu[p] >= 10 ? arena_visu[p] -= 10 : 0;
	tmp = logic->queue;
	while (tmp)
	{
		proc = (t_proc *)tmp->data;
		p = (proc->owner->spawn + proc->pc) % MEM_SIZE;
		arena_visu[p] <= 10 ? arena_visu[p] += 10 : 0;
		tmp = tmp->next;
	}
}
