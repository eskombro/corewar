/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:30:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/06 20:09:43 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_SCENE_H
# define MAIN_SCENE_H

# include "../../gui.h"

# define MAIN_SCENE_TOP_HEIGHT 50
# define MAIN_SCENE_BOTTOM_HEIGHT 100

# define MAIN_SCENE_MARGIN 20
# define MAIN_SCENE_CORNER_RADIUS 7
# define MAIN_SCENE_EDGE 1

void			frames(t_visu *visu, t_main_scene *main);
void			labels(t_visu *visu, t_main_scene *main);

#endif
