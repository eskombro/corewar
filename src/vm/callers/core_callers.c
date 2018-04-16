/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_callers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 00:42:36 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 01:45:27 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_core_begin(void)
{
	t_command		command;

	if (!(get_logic()->params.command_io))
		return ;
	command.size = 0;
	command.type = COMMAND_CORE_BEGIN;
	command.size += write_int(command.data + command.size, MEM_SIZE);
	send_command(command);
}

void				call_core_end(void)
{
	t_command		command;

	if (!(get_logic()->params.command_io))
		return ;
	command.size = 0;
	command.type = COMMAND_CORE_END;
	send_command(command);
}
