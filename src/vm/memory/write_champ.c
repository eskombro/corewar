/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 21:19:14 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/14 17:00:04 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Writes champion in memory, at its spawn address
*/

void		write_champ(t_champ *champ)
{
	int		i;
	uchar	*arena;

	i = -1;
	arena = get_arena();
	while (++i < champ->size)
		arena[(champ->spawn + i) % MEM_SIZE] = (uchar)champ->champion[i];
}
