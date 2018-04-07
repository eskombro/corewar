/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 21:22:31 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/06 21:45:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../events.h"

void			handle_key_event(SDL_KeyboardEvent key)
{
	SDL_Event	quit;

	quit.type = SDL_QUIT;
	if (key.keysym.sym == SDLK_ESCAPE)
		SDL_PushEvent(&quit);
}
