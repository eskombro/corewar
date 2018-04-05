/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_callers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:05:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/05 06:25:15 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_champ_spawn(t_champ *champ)
{
	t_command		command;

	ft_bzero(&command, sizeof(t_command));
	command.type = COMMAND_CHAMP_SPAWN;
	command.size += write_int(command.data + command.size, champ->id);
	command.size += write_short(command.data + command.size, ft_strlen(champ->name));
	command.size += write_str(command.data + command.size, champ->name);
	command.size += write_int(command.data + command.size, champ->spawn);
	command.size += write_int(command.data + command.size, champ->size);
	command.size += write_buf(command.data + command.size, champ->champion,
		champ->size);
	send_command(command);
}

void				call_champ_win(t_champ *champ)
{
	t_command		command;

	ft_bzero(&command, sizeof(t_command));
	command.type = COMMAND_CHAMP_WINS;
	command.size += write_int(command.data + command.size, champ->id);
	send_command(command);
}
