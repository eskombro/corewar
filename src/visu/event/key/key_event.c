/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:22:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 17:50:58 by hbouillo         ###   ########.fr       */
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

void			handle_key_event(t_visu *visu, SDL_KeyboardEvent key)
{
	SDL_Event	quit;

	quit.type = SDL_QUIT;
	if (key.keysym.sym == SDLK_ESCAPE)
		SDL_PushEvent(&quit);
	handle_color_set_pick(visu, key);
}
