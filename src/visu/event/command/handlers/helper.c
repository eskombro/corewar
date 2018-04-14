/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:42:38 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/14 17:47:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

t_player			*find_player(t_visu *visu, int vm_id)
{
	t_llist			*tmp;
	t_player		*tmp_player;

	tmp = visu->players;
	while (tmp)
	{
		tmp_player = (t_player *)tmp->data;
		if (tmp_player->vm_id == vm_id)
			return (tmp_player);
		tmp = tmp->next;
	}
	return (NULL);
}

t_process			*find_process(t_visu *visu, int proc_id)
{
	t_llist			*tmp;
	t_process		*tmp_process;

	tmp = visu->process[proc_id % PROCESS_ARRAY_SIZE];
	while (tmp)
	{
		tmp_process = (t_process *)tmp->data;
		if (tmp_process->id == proc_id)
			return (tmp_process);
		tmp = tmp->next;
	}
	return (NULL);
}
