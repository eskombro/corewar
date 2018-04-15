/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:24:30 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/15 04:00:17 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

void			print_header2(int y, int x, int i)
{
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i -= 2));
	printw(" 888        888     888 888   d88P 8888888");
	printw("    888 d888b 888     d88P 888 888   d88P ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw(" 888        888     888 8888888P   888    ");
	printw("    888d88888b888    d88P  888 8888888P   ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw(" 888    888 888     888 888 T88b   888    ");
	printw("    88888P Y88888   d88P   888 888 T88b   ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw(" Y88b  d88P Y88b. .d88P 888  T88b  888    ");
	printw("    8888P   Y8888  d8888888888 888  T88b  ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw("   Y8888P     Y88888P   888   T88b 8888888");
	printw("888 888P     Y888 d88P     888 888   T88b ");
}

void			print_header(void)
{
	int		y;
	int		x;
	int		i;

	y = 3;
	i = 246;
	x = (COLS - 83) / 2;
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw("  .d8888b.   .d88888b.  8888888b.  8888888");
	printw("888 888       888        d8888 8888888b.  ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i -= 2));
	printw(" d88P  Y88b d88P   Y88b 888   Y88b 888    ");
	printw("    888   o   888       d88888 888   Y88b ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
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
		mvprintw(y++, x, "*--------------------------------------*");
		mvprintw(y++, x, "|                                      |");
		mvprintw(y++, x, "|\t%-31.31s |", get_visu()->champs[i]->name);
		mvprintw(y++, x, "|                                      |");
		mvprintw(y++, x, "|\tPlayer %-3d (%.8x)           |",
			get_visu()->champs[i]->id, get_visu()->champs[i]->id);
		mvprintw(y++, x, "|\tLives this round: %-13d |",
				get_visu()->champs[i]->lifes_round);
		mvprintw(y++, x, "|\tLives: %-24d |", get_visu()->champs[i]->lifes);
		mvprintw(y++, x, "|                                      |");
		mvprintw(y++, x, "*--------------------------------------*");
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
	mvprintw(y++, x, "*--------------------------------------*");
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "|\tSTATS                             |");
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "|\tCycles:       %- 16d    |", get_visu()->stats->cycles);
	mvprintw(y++, x, "|\tCycles to die: %-6d             |",
		get_visu()->stats->cycles_to_die);
	mvprintw(y++, x, "|\tCycles left:   %-8d           |",
		get_visu()->stats->cycles_left);
	mvprintw(y++, x, "|\tLast live:     %-18s |", get_visu()->stats->last_life);
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "*--------------------------------------*");
}

void			print_win_panel(int x, int y, char *str)
{
	mvprintw(y++, x, "*--------------------------------------*");
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "|             THE END                  |");
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "|\tWinner: %-24s  |", str);
	mvprintw(y++, x, "|\tCycles: %-6d                    |",
			get_visu()->stats->cycles);
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "|\tPRESS ctrl + c TO CLOSE           |");
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "|                                      |");
	mvprintw(y++, x, "*--------------------------------------*");
}
