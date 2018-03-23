/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse_visu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:33:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 23:41:07 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_VISU_H
# define NCURSE_VISU_H

# include "corewar.h"

void				display_players_info(t_logic *logic);
void				display_scoreboard(t_logic *logic);
void				display_arena_line(t_uchar *arena, t_uchar *arena_visu,
						int y);
void				display_arena(t_uchar *arena);
void				display_process(t_logic *logic);
void				display_line_separator(void);

void				initialize_arena_visu(t_logic *logic,
						t_uchar *arena_writer);

#endif
