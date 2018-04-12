/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:10:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/07 18:15:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "visualizer.h"

void					init_main_scene(t_visu *visu, t_main_scene *main);
// void					init_end_scene(t_visu *visu, t_end_scene *main);

void					main_update_colors(t_visu *show, t_main_scene *main);
// void					end_update_colors(t_visu *visu, t_end_scene *end);

#endif
