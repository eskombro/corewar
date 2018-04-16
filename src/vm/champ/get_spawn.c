/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:50:39 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 21:55:53 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"

static int		checkdup(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] == tab[j] && i != j)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void			get_champnbr(t_champ *champs, char *arg)
{
	int tab[MAX_CHAMPS];
	int i;

	i = 0;
	ft_bzero(&tab, sizeof(int) * MAX_CHAMPS);
	while (champs[i].fixed_id)
	{
		tab[i] = ft_atoi(arg);
		while (*arg && *arg != ',')
			arg++;
		if (*arg && *arg == ',')
			arg++;
		i++;
	}
	if (!checkdup(tab, i))
		return ;
	i = 0;
	while (champs[i].fixed_id)
	{
		champs[i].id = tab[i];
		i++;
	}
}

int				calc_spawn(int players, t_champ *champs)
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
