/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:35:14 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 23:41:12 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ncurse_visu.h"

t_uchar				*get_arena_visu(void)
{
	static t_uchar	arena_visu[MEM_SIZE];

	return (arena_visu);
}

void				initialize_arena_visu(t_logic *logic, t_uchar *arena_writer)
{
	int				champ;
	int				i;

	champ = -1;
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_WHITE);
	init_pair(12, COLOR_BLACK, COLOR_WHITE);
	init_pair(13, COLOR_BLACK, COLOR_WHITE);
	init_pair(14, COLOR_BLACK, COLOR_WHITE);
	init_pair(15, COLOR_BLACK, COLOR_WHITE);
	init_pair(16, COLOR_BLACK, COLOR_WHITE);
	while (++champ < logic->params.players)
	{
		i = logic->champs[champ].spawn - 1;
		while (++i < logic->champs[champ].spawn + logic->champs[champ].size)
			arena_writer[i] = logic->champs[champ].fixed_id;
	}
}
