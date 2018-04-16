/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 02:06:40 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/16 04:24:17 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

void			test_char(void)
{
	int				ch;

	ch = getch();
	if (ch == 'q')
	{
		endwin();
		free_all();
		exit(0);
	}
	else if (ch == 'p')
		get_visu()->cps += 50;
	else if (ch == 'u')
		get_visu()->cps -= 50;
	else if (ch == 'o')
		get_visu()->cps++;
	else if (ch == 'i')
		get_visu()->cps--;
	else if (ch == ' ')
		get_visu()->run ^= 1;
	if (get_visu()->cps > 5000)
		get_visu()->cps = 5000;
	if (get_visu()->cps < 1)
		get_visu()->cps = 1;
}
