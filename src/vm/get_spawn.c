/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:50:39 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/12 22:58:13 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/inc/libft.h"
#include "types.h"
#include <unistd.h>
#include <stdio.h>
#include "vm_params.h"

int		calc_spawn(char **jcvd, t_champ *champs)
{
	int lines;
	int players;
	int div;
	int i;
	int pos;

	lines = MEM_SIZE / 64;
	players = ft_chartablen(jcvd);
	if (players == 1)
	{
		champs->spawn = 0;
		return (0);
	}
	players--;
	i = players;
	div = lines / players;
	pos = 0;
	while (i)
	{
		champs[players - i].spawn = (pos + ((players - i) * div)) * 64;
		i--;
	}
	return (0);
}
