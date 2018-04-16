/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:42:23 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 19:19:11 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void			free_player(void *arg)
{
	t_player		*player;

	player = (t_player *)arg;
	free(player->name);
	free(player->champ);
	free(player);
}

void				free_player_info(void *arg)
{
	t_player_info	*info;

	info = (t_player_info *)arg;
	free(info);
}

void				free_visu(t_visu *visu)
{
	int				i;

	ft_llist_del(&visu->players, &free_player);
	i = -1;
	while (++i < PROCESS_ARRAY_SIZE)
		ft_llist_del(visu->process + i, &free);
	i = -1;
	while ((unsigned int)++i < visu->mem.size)
		ft_llist_del(&visu->mem.data[i].procs, NULL);
	free(visu->mem.data);
	free(visu->mem.raw_content);
	free(visu->mem.raw_front);
	free(visu->mem.raw_back);
}
