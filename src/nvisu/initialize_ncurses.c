/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ncurses.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 02:07:44 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/16 05:18:33 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

void			set_black_background(void)
{
	int			i;

	i = -1;
	move(0, 0);
	attron(COLOR_PAIR(2));
	while (++i < LINES)
		printw("%*s", COLS, " ");
}

void			initialize_ncurses(void)
{
	initscr();
	start_color();
	init_pair(1, 235, 232);
	init_pair(2, 16, 16);
	init_pair(3, 232, 241);
	init_pair(4, 237, 233);
	init_pair(11, 235, 242);
	init_pair(12, 214, 232);
	init_pair(13, 91, 232);
	init_pair(14, 1, 232);
	init_pair(15, 34, 232);
	init_pair(22, 214, 242);
	init_pair(23, 91, 242);
	init_pair(24, 1, 242);
	init_pair(25, 34, 242);
	init_pair(32, 232, 214);
	init_pair(33, 232, 91);
	init_pair(34, 232, 1);
	init_pair(35, 232, 34);
	set_black_background();
}
