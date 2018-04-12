/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 19:21:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 19:30:09 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../events.h"

void				handle_new_cycle(t_visu *visu, t_command *command)
{
	visu->game.cycle = read_int(command->data);
	visu->game.cycle_to_die = read_int(command->data + 4);
	visu->game.cycle_left = read_int(command->data + 8);
}
