/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:22:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 05:23:01 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../events.h"

static void		handle_color_set_pick(t_visu *visu, SDL_KeyboardEvent event)
{
	if (event.keysym.sym == SDLK_0)
		set_color_set(visu, 9);
	else if (event.keysym.sym == SDLK_1)
		set_color_set(visu, 0);
	else if (event.keysym.sym == SDLK_2)
		set_color_set(visu, 1);
	else if (event.keysym.sym == SDLK_3)
		set_color_set(visu, 2);
	else if (event.keysym.sym == SDLK_4)
		set_color_set(visu, 3);
	else if (event.keysym.sym == SDLK_5)
		set_color_set(visu, 4);
	else if (event.keysym.sym == SDLK_6)
		set_color_set(visu, 5);
	else if (event.keysym.sym == SDLK_7)
		set_color_set(visu, 6);
	else if (event.keysym.sym == SDLK_8)
		set_color_set(visu, 7);
	else if (event.keysym.sym == SDLK_9)
		set_color_set(visu, 8);
}

static void		update_tps(t_visu *visu)
{
	char		*tmp;

	tmp = ft_itoa(visu->tps);
	sg_set_label_text(
		visu->gui.scenes[COREWAR_SCENE_MAIN].main.cycles_rate,
		sg_new_gstr(tmp,
			get_resource_path(COREWAR_FONT), (int)(COREWAR_TOP_FONT_SIZE * 0.75)));
	free(tmp);
}

static void		handle_tps(t_visu *visu, SDL_KeyboardEvent key)
{
	pthread_mutex_lock(&visu->run_mutex);
	if (key.keysym.sym == SDLK_UP || key.keysym.sym == SDLK_w)
		visu->tps++;
	else if (key.keysym.sym == SDLK_DOWN || key.keysym.sym == SDLK_s)
		visu->tps--;
	else if (key.keysym.sym == SDLK_PAGEUP || key.keysym.sym == SDLK_r)
		visu->tps += 10;
	else if (key.keysym.sym == SDLK_PAGEDOWN || key.keysym.sym == SDLK_f)
		visu->tps -= 10;
	if (visu->tps <= 0)
		visu->tps = 1;
	else if (visu->tps > CYCLES_PER_SECOND_MAX)
		visu->tps = CYCLES_PER_SECOND_MAX;
	update_tps(visu);
	pthread_mutex_unlock(&visu->run_mutex);
}

void			handle_key_event(t_visu *visu, SDL_KeyboardEvent key)
{
	SDL_Event	quit;

	quit.type = SDL_QUIT;
	if (key.keysym.sym == SDLK_ESCAPE)
		SDL_PushEvent(&quit);
	else if (key.keysym.sym == SDLK_RETURN)
	{
		if (SDL_GetWindowFlags(visu->window) & SDL_WINDOW_FULLSCREEN_DESKTOP)
			SDL_SetWindowFullscreen(visu->window, 0);
		else
			SDL_SetWindowFullscreen(visu->window,
				SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	else if (key.keysym.sym == SDLK_SPACE)
	{
		pthread_mutex_lock(&visu->pause_mutex);
		visu->pause ^= 1;
		pthread_mutex_unlock(&visu->pause_mutex);
	}
	else if (key.keysym.sym == SDLK_UP || key.keysym.sym == SDLK_w ||
		key.keysym.sym == SDLK_DOWN || key.keysym.sym == SDLK_s ||
		key.keysym.sym == SDLK_PAGEUP || key.keysym.sym == SDLK_r ||
		key.keysym.sym == SDLK_PAGEDOWN || key.keysym.sym == SDLK_f)
		handle_tps(visu, key);
	handle_color_set_pick(visu, key);
}
