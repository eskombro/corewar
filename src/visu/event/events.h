/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:23:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 05:06:51 by hbouillo         ###   ########.fr       */
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
void			handle_core_end(t_visu *visu, t_command *command);
void			handle_mem_write(t_visu *visu, t_command *command);
void			handle_champ_spawn(t_visu *visu, t_command *command);
void			handle_proc_spawn(t_visu *visu, t_command *command);
void			handle_proc_move(t_visu *visu, t_command *command);
void			handle_new_cycle(t_visu *visu, t_command *command);
void			handle_live(t_visu *visu, t_command *command);
void			handle_proc_death(t_visu *visu, t_command *command);

/*
** Helper
*/
t_player		*find_player(t_visu *visu, int vm_id);
t_process		*find_process(t_visu *visu, int proc_id);
void			push_proc(t_visu *visu, t_process *proc);
void			proc_add(t_visu *visu, t_process *proc);
void			proc_remove(t_visu *visu, t_process *proc);
void			init_player_info_gui(t_visu *visu, t_player *player);

#endif
