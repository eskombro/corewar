/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:23:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 19:22:59 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "visualizer.h"

void			handle_command_event(t_visu *visu, SDL_UserEvent e);
void			handle_key_event(t_visu *visu, SDL_KeyboardEvent e);

/*
** Commands
*/
void			handle_core_begin(t_visu *visu, t_command *command);
void			handle_mem_write(t_visu *visu, t_command *command);
void			handle_champ_spawn(t_visu *visu, t_command *command);
void			handle_proc_spawn(t_visu *visu, t_command *command);
void			handle_new_cycle(t_visu *visu, t_command *command);

#endif
