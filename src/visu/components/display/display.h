/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 04:22:16 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 18:31:09 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "visualizer.h"

typedef struct			s_display
{
	t_color				ocolor;
	t_color				grid_00;
	t_color				p1;
	t_color				p2;
	t_color				p3;
	t_color				p4;
	t_color				check;
	int					*win_h;
	int					*win_w;
	t_mem				*mem;
	t_gamedata			*game;
	int					edge;
	GLuint				map;
	GLuint				front_map;
	GLuint				back_map;
	t_pngtex			*hextex_data;
	GLuint				hextex;
}						t_display;

void					display_draw(void *scene, t_component_data *data,
							t_rect bounds);

void					display_event(void *scene, t_component_data *data,
							SDL_Event e);
void					compute_texture(t_display *display);
void					init_draw(GLuint vao, t_component_data *data,
							t_rect bounds);
#endif
