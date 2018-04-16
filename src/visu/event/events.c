/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:39:06 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/15 17:13:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./events.h"

unsigned int		get_user_event(void)
{
	static unsigned int	user_event = 0xFFFFFFFF;

	if (user_event == 0xFFFFFFFF)
		user_event = SDL_RegisterEvents(1);
	if (user_event == 0xFFFFFFFF)
		error(ERR_SDL_EVENT, ERR_CRITICAL);
	return (user_event);
}

void				push_user_event(int code, void *data1, void *data2)
{
	SDL_Event	e;

	e.type = get_user_event();
	e.user.code = code;
	e.user.data1 = data1;
	e.user.data2 = data2;
	SDL_PushEvent(&e);
}

static void			handle_event(t_visu *visu, SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
		handle_key_event(visu, e.key);
	else if (e.type == SDL_WINDOWEVENT &&
		e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
	{
		visu->win_w = (int)e.window.data1;
		visu->win_h = (int)e.window.data2;
	}
	else if (e.type == get_user_event())
	{
		if (e.user.code == COREWAR_EVENT_COMMAND)
			handle_command_event(visu, e.user);
	}
}

int					run_events(t_visu *visu)
{
	SDL_Event		e;
	int				scene;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			return (1);
		scene = -1;
		handle_event(visu, e);
		while (++scene < COREWAR_SCENES_AMOUNT)
		{
			if (!visu->gui.scenes[scene].ptr)
				continue ;
			if (visu->gui.scenes + scene == visu->gui.active_scene)
				sg_event(visu->gui.scenes[scene].ptr, e,
					SG_MODE_ACTIVE);
			else
				sg_event(visu->gui.scenes[scene].ptr, e,
					SG_MODE_PASSIVE);
		}
	}
	return (0);
}
