/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 05:03:25 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 18:51:54 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

static void			update_labels(t_player_info *pinfo)
{
	sg_set_label_text(
		pinfo->alive,
		sg_new_gstr("Alive",
			get_resource_path(COREWAR_FONT),
			(int)(0.75 * COREWAR_TOP_FONT_SIZE)));
}

void				handle_live(t_visu *visu, t_command *command)
{
	int				player;
	t_llist			*tmp;
	t_player_info	*pinfo;

	player = read_int(command->data + 4);
	tmp = visu->gui.scenes[COREWAR_SCENE_MAIN].main.p_infos;
	while (tmp)
	{
		pinfo = (t_player_info *)tmp->data;
		if (pinfo->player->vm_id == player)
		{
			update_labels(pinfo);
			break ;
		}
		tmp = tmp->next;
	}
}
