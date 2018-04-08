/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:46:25 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/08 00:22:58 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void				send_command(t_command command)
{
	unsigned char	buf[2];

	if (command.size < 0)
		command.size = 0;
	else if (command.size > MAX_COMMAND_DATA_SIZE)
		command.size = MAX_COMMAND_DATA_SIZE;
	write(1, &command.type, 1);
	write_short(buf, command.size);
	write(1, buf, 2);
	write(1, command.data, (int)command.size);
}
