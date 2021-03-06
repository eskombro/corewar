/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:30:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/15 19:31:47 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_SCENE_H
# define MAIN_SCENE_H

# include "../../gui.h"

void			frames(t_visu *visu, t_main_scene *main);
void			labels(t_visu *visu, t_main_scene *main);
void			cycles_lbl(t_visu *visu, t_main_scene *main);
void			cycles_to_die_lbl(t_visu *visu, t_main_scene *main);
void			cycles_left_lbl(t_visu *visu, t_main_scene *main);
void			cycles_rate_lbl(t_visu *visu, t_main_scene *main);
void			display(t_visu *visu, t_main_scene *main);

#endif
