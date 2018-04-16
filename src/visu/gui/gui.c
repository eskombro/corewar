/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:48:43 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 19:20:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gui.h"

void					uninit_gui(t_visu *visu)
{
	ft_llist_del(&visu->gui.scenes[COREWAR_SCENE_MAIN].main.p_infos,
		&free_player_info);
	destroy_display(visu->gui.scenes[COREWAR_SCENE_MAIN].main.mem_grid.frame);
	sg_destroy_scene(visu->gui.scenes[COREWAR_SCENE_MAIN].ptr);
	sg_destroy_scene(visu->gui.scenes[COREWAR_SCENE_END].ptr);
}

void					init_gui(t_visu *visu)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	ft_bzero(&(visu->gui), sizeof(t_gui));
	set_color_set(visu, 0);
	init_main_scene(visu, &(visu->gui.scenes[COREWAR_SCENE_MAIN].main));
	init_end_scene(visu, &(visu->gui.scenes[COREWAR_SCENE_END].end));
	visu->gui.active_scene = visu->gui.scenes + COREWAR_SCENE_MAIN;
}

static void				draw_gui(t_visu *visu)
{
	if (visu->gui.active_scene == visu->gui.scenes + COREWAR_SCENE_END)
		sg_draw(visu->gui.scenes[COREWAR_SCENE_MAIN].ptr);
	sg_draw(visu->gui.active_scene->ptr);
}

static void				update_labels(t_visu *visu)
{
	char				*tmp;

	tmp = ft_itoa(visu->game.cycle);
	sg_set_label_text(
		visu->gui.scenes[COREWAR_SCENE_MAIN].main.cycles,
		sg_new_gstr(tmp,
			get_resource_path(COREWAR_FONT),
			(int)(0.75 * COREWAR_TOP_FONT_SIZE)));
	free(tmp);
	tmp = ft_itoa(visu->game.cycle_left);
	sg_set_label_text(
		visu->gui.scenes[COREWAR_SCENE_MAIN].main.cycles_left,
		sg_new_gstr(tmp,
			get_resource_path(COREWAR_FONT),
			(int)(0.75 * COREWAR_TOP_FONT_SIZE)));
	free(tmp);
}

void					run_gui(t_visu *visu)
{
	static t_time		last_time;
	t_time				current_time;
	unsigned long		delta;

	clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
	if (!last_time.tv_sec)
		last_time = current_time;
	delta = (current_time.tv_sec - last_time.tv_sec) * 1000000000 +
			current_time.tv_nsec - last_time.tv_nsec;
	if (delta > 1000000000 / FRAMES_PER_SECOND)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (visu->game.update_labels)
		{
			update_labels(visu);
			visu->game.update_labels = 0;
		}
		if (visu->gui.active_scene != NULL)
			draw_gui(visu);
		last_time = current_time;
		SDL_GL_SwapWindow(visu->window);
	}
}
