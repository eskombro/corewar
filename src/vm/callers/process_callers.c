/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_callers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:53:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 01:46:20 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_process_spawn(t_proc *process)
{
	t_command		command;

	if (!(get_logic()->params.command_io))
		return ;
	command.size = 0;
	command.type = COMMAND_PROC_SPAWN;
	command.size += write_int(command.data + command.size, process->id);
	command.size += write_int(command.data + command.size, process->owner->id);
	command.size += write_int(command.data + command.size, process->pc);
	send_command(command);
}

void				call_process_move(t_proc *process)
{
	t_command		command;

	if (!(get_logic()->params.command_io))
		return ;
	command.size = 0;
	command.type = COMMAND_PROC_MOVE;
	command.size += write_int(command.data + command.size, process->id);
	command.size += write_int(command.data + command.size, process->pc);
	send_command(command);
}

void				call_process_death(t_proc *process)
{
	t_command		command;

	if (!(get_logic()->params.command_io))
		return ;
	command.size = 0;
	command.type = COMMAND_PROC_DEATH;
	command.size += write_int(command.data + command.size, process->id);
	send_command(command);
}
