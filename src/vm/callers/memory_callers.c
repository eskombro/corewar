/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_callers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:03:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 01:45:58 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_memory_write(t_proc *writer, t_addr final_address,
						int value)
{
	t_command		command;

	if (!(get_logic()->params.command_io))
		return ;
	command.size = 0;
	command.type = COMMAND_MEM_WRITE;
	command.size += write_int(command.data + command.size, writer->id);
	command.size += write_int(command.data + command.size, final_address);
	command.size += write_int(command.data + command.size, value);
	send_command(command);
}
