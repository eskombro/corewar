/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 01:08:48 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/06 18:31:01 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			debug_command(t_command command)
{
	int			i;

	ft_dprintf(2, "[COMMAND] Packet of type 0x%2.2x and size %3d \
octets contains [ ",
		command.type, command.size);
	i = -1;
	while (++i < command.size)
		ft_dprintf(2, "%02.2x ", command.data[i]);
	ft_dprintf(2, "]\n");
}
