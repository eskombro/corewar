/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:40:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 16:40:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../events.h"

void			handle_scene_event(t_visu *visu, SDL_UserEvent user_event)
{
	visu->gui.active_scene = visu->gui.scenes + (int)user_event.data1;
}
