/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_callers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:06:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 01:45:52 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_new_cycle(t_logic *logic)
{
	t_command		command;

	if (!(get_logic()->params.command_io))
		return ;
	command.size = 0;
	command.type = COMMAND_LOGIC_CYCLE;
	command.size += write_int(command.data + command.size, logic->cycles);
	command.size += write_int(command.data + command.size,
		logic->cycles_to_die);
	command.size += write_int(command.data + command.size, logic->cycles_left);
	send_command(command);
}

void				call_live_report(t_proc *process, int player)
{
	t_command		command;

	if (!(get_logic()->params.command_io))
		return ;
	command.size = 0;
	command.type = COMMAND_LOGIC_LIVE;
	command.size += write_int(command.data + command.size, process->id);
	command.size += write_int(command.data + command.size, player);
	send_command(command);
}
