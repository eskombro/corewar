/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:46:25 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/31 18:52:57 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//TODO: Command reader
void				start_command_reader()
{

}

static t_command	*read_command(void)
{
	return (NULL);
}

void				send_command(t_command command)
{
	if (command.size < 0)
		command.size = 0;
	else if (command.size > MAX_COMMAND_DATA_SIZE)
		command.size = MAX_COMMAND_DATA_SIZE;
	write(1, &command.type, 1);
	write(1, &command.size, 1);
	write(1, command.data, (int)command.size);
}
