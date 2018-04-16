/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_shortcuts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 04:35:05 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/16 05:36:54 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

void			display_shortcuts(void)
{
	int			x;
	int			y;

	y = get_visu()->start_y + (get_visu()->m_size / 64) - 10;
	x = get_visu()->start_x + (3 * MEM_TAB_LENGTH) + 2;
	attron(COLOR_PAIR(4));
	mvprintw(y++, x, " *--------------------------------------* ");
	mvprintw(y++, x, " |              SHORTCUTS               | ");
	mvprintw(y++, x, " *--------------------------------------* ");
	mvprintw(y++, x, " |     SPACE => Pause / Play            | ");
	mvprintw(y++, x, " |     'q'   => Quit                    | ");
	mvprintw(y++, x, " |     'p'   => +50 Cycles per second   | ");
	mvprintw(y++, x, " |     'o'   => +1 Cycles per second    | ");
	mvprintw(y++, x, " |     'i'   => -1 Cycles per second    | ");
	mvprintw(y++, x, " |     'u'   => -50 Cycles per second   | ");
	mvprintw(y++, x, " *--------------------------------------* ");
}
