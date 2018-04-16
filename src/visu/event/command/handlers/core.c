/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:58:20 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 18:50:48 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

void				handle_core_begin(t_visu *visu, t_command *command)
{
	if (visu->mem.data)
		return ;
	visu->mem.size = read_int(command->data);
	visu->mem.size_2d.w = MEM_ROW;
	visu->mem.size_2d.h = visu->mem.size / MEM_ROW +
		(visu->mem.size % MEM_ROW ? 1 : 0);
	if (!visu->mem.size)
		return ;
	if (!(visu->mem.data = (t_data *)ft_memalloc(
		sizeof(t_data) * visu->mem.size)))
		error(ERR_MALLOC, ERR_CRITICAL);
	visu->mem.new_data = 1;
}

void				handle_core_end(t_visu *visu, t_command *command)
{
	command = 0;
	visu->end = 1;
	visu->game.check_cycle = -CHECK_ANIM_DUR;
}
