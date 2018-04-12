/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:45:42 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 17:54:17 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../events.h"

void			handle_command_event(t_visu *visu, SDL_UserEvent user)
{
	t_command	*command;

	command = (t_command *)user.data1;
	if (command->type == COMMAND_CORE_BEGIN)
		handle_core_begin(visu, command);
	else if (command->type == COMMAND_MEM_WRITE)
		handle_mem_write(visu, command);
	else if (command->type == COMMAND_CHAMP_SPAWN)
		handle_champ_spawn(visu, command);
	else if (command->type == COMMAND_PROC_SPAWN)
		handle_proc_spawn(visu, command);
	free(command);
}
