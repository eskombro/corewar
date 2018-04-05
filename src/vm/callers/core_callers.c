/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_callers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 00:42:36 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/05 06:25:18 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_core_begin(void)
{
	t_command		command;

	ft_bzero(&command, sizeof(t_command));
	command.type = COMMAND_CORE_BEGIN;
	command.size += write_int(command.data + command.size, MEM_SIZE);
	send_command(command);
}

void				call_core_end(void)
{
	t_command		command;

	ft_bzero(&command, sizeof(t_command));
	command.type = COMMAND_CORE_END;
	send_command(command);
}
