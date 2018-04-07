/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:45:42 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/07 01:20:05 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../events.h"

void			handle_command_event(SDL_UserEvent user)
{
	t_command	*command;

	command = (t_command *)user.data1;
	free(command);
}
