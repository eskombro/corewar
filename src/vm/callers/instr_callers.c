/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_callers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:04:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/05 01:28:09 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_instr_start(t_proc *process)
{
	t_command		command;

	bzero(&command, sizeof(t_command));
	command.type = COMMAND_INSTR_INIT;
	command.size += write_int(command.data + command.size, process->id);
	command.size += write_int(command.data + command.size,
		process->current_task->run_cycle);
	send_command(command);
}

void				call_instr_exec(t_proc *process)
{
	t_command		command;
	int				i;

	bzero(&command, sizeof(t_command));
	command.type = COMMAND_INSTR_EXEC;
	command.size += write_int(command.data + command.size, process->id);
	command.size += write_char(command.data + command.size,
		process->current_task->opcode);
	command.size += write_int(command.data + command.size,
		process->current_task->mem_size);
	i = -1;
	while (++i < 3)
	{
		command.size += write_int(command.data + command.size, process->current_task->par[i].type);
		command.size += write_int(command.data + command.size, process->current_task->par[i].value);
	}
	send_command(command);
}
