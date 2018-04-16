/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 01:08:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 18:47:47 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void		init_window(t_visu *visu)
{
	if (SDL_GetDisplayUsableBounds(0, &(visu->max_size)) < 0)
	{
		error(ERR_SDL_DISPLAY, ERR_WARNING);
		visu->max_size.w = 1280 * 10 / 9;
		visu->max_size.h = 720 * 10 / 9;
	}
	if (!(visu->window = SDL_CreateWindow("Corewar",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		visu->max_size.w * 9 / 10,
		visu->max_size.h * 9 / 10,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)))
		error(ERR_SDL_WINDOW, ERR_CRITICAL);
	visu->context = SDL_GL_CreateContext(visu->window);
	visu->win_w = visu->max_size.w * 9 / 10;
	visu->win_h = visu->max_size.h * 9 / 10;
	SDL_SetWindowMinimumSize(visu->window, 1000, 670);
}

static void		run_loop(t_visu *visu)
{
	while (1)
	{
		if (run_events(visu))
		{
			pthread_mutex_lock(&visu->run_mutex);
			visu->run = 0;
			pthread_mutex_unlock(&visu->run_mutex);
			break ;
		}
		run_gui(visu);
	}
}

void			run_visu(t_visu *visu)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error(ERR_SDL_INIT, ERR_CRITICAL);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE);
	init_window(visu);
	init_gui(visu);
	run_loop(visu);
	uninit_gui(visu);
	sg_del_all_gstr();
	SDL_GL_DeleteContext(visu->context);
	SDL_DestroyWindow(visu->window);
	SDL_Quit();
}
