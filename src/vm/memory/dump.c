/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:27:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 23:39:42 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	print_arena_dump:
**	Writes the arena content in stdout.
*/

void				print_arena_dump(void)
{
	t_uchar			*arena;
	int				i;

	i = -1;
	arena = get_arena();
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%04x : ", i);
		ft_printf("%.2x ", arena[i]);
		i % 64 == 63 ? ft_putchar('\n') : 0;
	}
}
