/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:23:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/06 21:57:40 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "visualizer.h"

void			handle_command_event(SDL_UserEvent e);
void			handle_key_event(SDL_KeyboardEvent e);

#endif
