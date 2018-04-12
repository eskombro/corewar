/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:34:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 17:56:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

static void			push_player(t_visu *visu, t_player *player)
{
	t_llist			*new;

	if (!(new = ft_llist_new(player)))
		error(ERR_MALLOC, ERR_CRITICAL);
	ft_llist_back(&visu->players, new);
}

void				handle_champ_spawn(t_visu *visu, t_command *command)
{
	static int		visu_id;
	t_player		*player;
	int				name_len;
	int				champ_len;
	int				i;

	if (!visu->mem.data)
		return ;
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		error(ERR_MALLOC, ERR_CRITICAL);
	player->visu_id = ++visu_id;
	player->vm_id = read_int(command->data);
	name_len = (int)read_short(command->data + 4);
	player->name = read_str(command->data + 6, name_len);
	player->spawn = read_int(command->data + 6 + name_len);
	champ_len = read_int(command->data + 6 + name_len + 4);
	player->champ = read_str(command->data + 6 + name_len + 8, champ_len);
	i = -1;
	while (++i < champ_len)
	{
		visu->mem.data[(player->spawn + i) % visu->mem.size] = player->champ[i];
		visu->mem.writer[(player->spawn + i) % visu->mem.size] =
			player->visu_id;
	}
	visu->mem.new_data = 1;
	push_player(visu, player);
}
