/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_callers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:05:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/31 19:33:16 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_champ_spawn(t_champ *champ)
{
	t_command		command;

	bzero(&command, sizeof(t_command));
	command.type = COMMAND_CHAMP_SPAWN;
	command.size += write_short(command.data, champ->id);
	command.size += write_str(command.data + 2, champ->name);
	send_command(command);
}

void				call_champ_win(t_champ *champ)
{
	t_command		command;

	ft_bzero(&command, sizeof(t_command));
	command.type = COMMAND_CHAMP_WINS;
	command.size += write_short(command.data, champ->id);
	send_command(command);
}
