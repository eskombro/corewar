/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_core_callers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:11:26 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/15 03:25:40 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

static void		display_arena(void)
{
	int				x;
	int				y;

	y = -1;
	get_visu()->start_y = 14;
	get_visu()->start_x = (COLS - (3 * MEM_TAB_LENGTH)) / 2;
	while (++y < (get_visu()->m_size / MEM_TAB_LENGTH))
	{
		x = -1;
		move(get_visu()->start_y + y, get_visu()->start_x);
		while (++x < MEM_TAB_LENGTH)
		{
			attron(COLOR_PAIR(1));
			get_visu()->mem[(y * MEM_TAB_LENGTH) + x] <= 0xF ? printw("0") : 0;
			printw("%x ", get_visu()->mem[(y * MEM_TAB_LENGTH) + x]);
		}
		printw("\n");
	}
	get_visu()->mem_tab_height = y;
}

static void		free_all(void)
{
	int			i;
	t_v_proc	*tmp;
	t_v_proc	*tmp_proc;

	i = -1;
	ft_strdel((char**)&get_visu()->mem);
	while (++i < get_visu()->champ_nb)
	{
		ft_strdel(&get_visu()->champs[i]->name);
		ft_memdel((void**)&get_visu()->champs[i]);
	}
	ft_memdel((void**)&get_visu()->champs);
	i = -1;
	tmp_proc = NULL;
	while (++i < PROC_TAB_SIZE)
	{
		tmp_proc = get_visu()->procs[i];
		while (tmp_proc)
		{
			tmp_proc->next ? tmp = tmp_proc->next : 0;
			ft_memdel((void**)tmp_proc);
			tmp_proc = tmp;
		}
	}
	ft_memdel((void**)get_visu()->procs);
}

void			handle_core_begin(t_command *command)
{
	get_visu()->m_size = read_int(command->data);
	if (!get_visu()->mem)
		if (!(get_visu()->mem =
			(t_uchar *)ft_memalloc(sizeof(t_uchar) * (get_visu()->m_size)))
			|| !(get_visu()->mem_proc =
			(int *)ft_memalloc(sizeof(int) * (get_visu()->m_size)))
			|| !(get_visu()->stats =
			(t_v_stats*)ft_memalloc(sizeof(t_v_stats))))
			exit(1);
	display_arena();
}

void			handle_core_end(void)
{
	free_all();
	while (1)
		;
	endwin();
}
