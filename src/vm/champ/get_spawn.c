/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:50:39 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/14 16:55:04 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"

int		calc_spawn(int players, t_champ *champs)
{
	int lines;
	int div;
	int i;
	int pos;

	lines = MEM_SIZE / 64;
	if (players == 1)
	{
		champs->spawn = 0;
		return (0);
	}
	div = lines / players;
	players--;
	i = players;
	pos = 0;
	while (i >= 0)
	{
		champs[i].spawn = (pos + i * div) * 64;
		i--;
	}
	return (0);
}
