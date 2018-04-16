/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:45:42 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 05:06:43 by hbouillo         ###   ########.fr       */
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
	else if (command->type == COMMAND_CORE_END)
		handle_core_end(visu, command);
	else if (command->type == COMMAND_CHAMP_SPAWN)
		handle_champ_spawn(visu, command);
	else if (command->type == COMMAND_LOGIC_CYCLE)
		handle_new_cycle(visu, command);
	else if (command->type == COMMAND_LOGIC_LIVE)
		handle_live(visu, command);
	else if (command->type == COMMAND_PROC_SPAWN)
		handle_proc_spawn(visu, command);
	else if (command->type == COMMAND_PROC_MOVE)
		handle_proc_move(visu, command);
	else if (command->type == COMMAND_PROC_DEATH)
		handle_proc_death(visu, command);
	free(command);
}
