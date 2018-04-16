/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:34:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 16:55:55 by hbouillo         ###   ########.fr       */
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

static t_color		*color_from_id(int writer, t_color_set *colors)
{
	if ((writer - 1) % 4 == 0)
		return (&colors->display_p1);
	if ((writer - 1) % 4 == 1)
		return (&colors->display_p2);
	if ((writer - 1) % 4 == 2)
		return (&colors->display_p3);
	if ((writer - 1) % 4 == 3)
		return (&colors->display_p4);
	return (&colors->display_grid_00);
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
	player->color = color_from_id(player->visu_id, visu->gui.colors);
	player->vm_id = read_int(command->data);
	name_len = (int)read_short(command->data + 4);
	player->name = read_str(command->data + 6, name_len);
	player->spawn = read_int(command->data + 6 + name_len);
	champ_len = read_int(command->data + 6 + name_len + 4);
	player->champ = (unsigned char *)read_str(command->data + 6 + name_len + 8, champ_len);
	while (player->spawn < 0)
		player->spawn += visu->mem.size;
	i = -1;
	while (++i < champ_len)
	{
		visu->mem.data[(player->spawn + i) % visu->mem.size].content =
			player->champ[i];
		visu->mem.data[(player->spawn + i) % visu->mem.size].writer =
			player->visu_id;
	}
	visu->mem.new_data = 1;
	push_player(visu, player);
	init_player_info_gui(visu, player);
}

void				handle_champ_win(t_visu *visu, t_command *command)
{
	t_player		*player;

	player = find_player(visu, read_int(command->data));
	if (player)
	{
		sg_set_label_text(
			visu->gui.scenes[COREWAR_SCENE_END].end.msg,
			sg_new_gstr(player->name,
				get_resource_path(COREWAR_FONT), (int)(1.5 * COREWAR_TOP_FONT_SIZE)));
		sg_set_label_color(visu->gui.scenes[COREWAR_SCENE_END].end.msg,
			*player->color);
	}
	push_user_event(COREWAR_EVENT_SCENE, (void *)COREWAR_SCENE_END, NULL);
}
