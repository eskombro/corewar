/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:24:30 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/16 05:20:56 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

void			print_header2(int y, int x, int i)
{
	move(y++, x);
	init_pair(i, i, 232);
	attron(COLOR_PAIR(i -= 2));
	printw(" 888        888     888 888   d88P 8888888");
	printw("    888 d888b 888     d88P 888 888   d88P ");
	move(y++, x);
	init_pair(i, i, 232);
	attron(COLOR_PAIR(i--));
	printw(" 888        888     888 8888888P   888    ");
	printw("    888d88888b888    d88P  888 8888888P   ");
	move(y++, x);
	init_pair(i, i, 232);
	attron(COLOR_PAIR(i--));
	printw(" 888    888 888     888 888 T88b   888    ");
	printw("    88888P Y88888   d88P   888 888 T88b   ");
	move(y++, x);
	init_pair(i, i, 232);
	attron(COLOR_PAIR(i--));
	printw(" Y88b  d88P Y88b. .d88P 888  T88b  888    ");
	printw("    8888P   Y8888  d8888888888 888  T88b  ");
	move(y++, x);
	init_pair(i, i, 232);
	attron(COLOR_PAIR(i--));
	printw("   Y8888P     Y88888P   888   T88b 8888888");
	printw("888 888P     Y888 d88P     888 888   T88b ");
}

void			print_header(void)
{
	int		y;
	int		x;
	int		i;

	y = 2;
	i = 246;
	x = (COLS - 83) / 2;
	move(y++, x);
	init_pair(i, i, 232);
	attron(COLOR_PAIR(i--));
	printw("  .d8888b.   .d88888b.  8888888b.  8888888");
	printw("888 888       888        d8888 8888888b.  ");
	move(y++, x);
	init_pair(i, i, 232);
	attron(COLOR_PAIR(i -= 2));
	printw(" d88P  Y88b d88P   Y88b 888   Y88b 888    ");
	printw("    888   o   888       d88888 888   Y88b ");
	move(y++, x);
	init_pair(i, i, 232);
	attron(COLOR_PAIR(i -= 2));
	printw(" 888    888 888     888 888    888 888    ");
	printw("    888  d8b  888      d88P888 888    888 ");
	print_header2(y, x, i);
}

void			display_leaderboard(void)
{
	int			i;
	int			y;
	int			x;

	i = -1;
	x = get_visu()->start_x - 45;
	y = get_visu()->start_y;
	while (++i < get_visu()->champ_nb)
	{
		attron(COLOR_PAIR(i + 32));
		mvprintw(y++, x, " *--------------------------------------* ");
		mvprintw(y++, x, " |    %-31.31s   | ", get_visu()->champs[i]->name);
		mvprintw(y++, x, " *--------------------------------------* ");
		mvprintw(y++, x, " |                                      | ");
		mvprintw(y++, x, " |    Player %-3d (%.8x)             | ",
			get_visu()->champs[i]->id, get_visu()->champs[i]->id);
		mvprintw(y++, x, " |    Lives this round: %-13d   | ",
			get_visu()->champs[i]->lifes_round);
		mvprintw(y++, x, " |    Total lives: %-18d   | ",
			get_visu()->champs[i]->lifes);
		mvprintw(y++, x, " |                                      | ");
		mvprintw(y++, x, " *--------------------------------------* ");
		y++;
	}
}

void			display_stats(void)
{
	int			i;
	int			y;
	int			x;

	i = -1;
	y = get_visu()->start_y;
	x = get_visu()->start_x + (3 * MEM_TAB_LENGTH) + 5;
	attron(COLOR_PAIR(3));
	mvprintw(y++, x, " *--------------------------------------* ");
	mvprintw(y++, x, " |               STATS                  | ");
	mvprintw(y++, x, " *--------------------------------------* ");
	mvprintw(y++, x, " |   Cycles:           %- 15d  | ",
		get_visu()->stats->cycles);
	mvprintw(y++, x, " |   Cycles to die:     %-6d          | ",
		get_visu()->stats->cycles_to_die);
	mvprintw(y++, x, " |   Cycles left:       %-8d        | ",
		get_visu()->stats->cycles_left);
	mvprintw(y++, x, " |   Last live:         %-12.12s    | ",
		get_visu()->stats->last_life);
	mvprintw(y++, x, " |   Cycles per second: %-4d            | ",
		get_visu()->cps);
	mvprintw(y++, x, " |                                      | ");
	mvprintw(y++, x, " *--------------------------------------* ");
}

void			print_win_panel(int x, int y, char *str)
{
	y++;
	mvprintw(y++, x, " *--------------------------------------* ");
	mvprintw(y++, x, " |             THE END                  | ");
	mvprintw(y++, x, " *--------------------------------------* ");
	mvprintw(y++, x, " |                                      | ");
	mvprintw(y++, x, " |    Winner: %-24s  | ", str);
	mvprintw(y++, x, " |    Cycles: %-6d                    | ",
			get_visu()->stats->cycles);
	mvprintw(y++, x, " |                                      | ");
	mvprintw(y++, x, " |                                      | ");
	mvprintw(y++, x, " |    PRESS 'q' TO CLOSE                | ");
	mvprintw(y++, x, " |                                      | ");
	mvprintw(y++, x, " |                                      | ");
	mvprintw(y++, x, " *--------------------------------------* ");
}
