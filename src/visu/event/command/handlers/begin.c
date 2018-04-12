/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:58:20 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 15:56:00 by hbouillo         ###   ########.fr       */
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
	if (!(visu->mem.data = ft_memalloc(sizeof(char) * visu->mem.size)))
		error(ERR_MALLOC, ERR_CRITICAL);
	if (!(visu->mem.writer = ft_memalloc(sizeof(char) * visu->mem.size)))
		error(ERR_MALLOC, ERR_CRITICAL);
	visu->mem.new_data = 1;
}
