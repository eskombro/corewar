/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_champ_callers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 01:16:59 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/15 02:18:05 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

static void		define_spawn_name(t_command *command)
{
	int			name_size;

	name_size = read_short(command->data + 4);
	get_visu()->champs[get_visu()->champ_nb]->spawn =
			read_int(command->data + 6 + name_size);
	get_visu()->champs[get_visu()->champ_nb]->spawn_y = get_visu()->start_y
			+ ((read_int(command->data + 6 + name_size)) / MEM_TAB_LENGTH);
	get_visu()->champs[get_visu()->champ_nb]->spawn_x = get_visu()->start_x
			+ ((read_int(command->data + 6 + name_size)) % MEM_TAB_LENGTH);
}

static void		print_champ(t_uchar *champ, int champ_size, t_command *command)
{
	int			x;
	int			y;

	y = -1;
	x = 0;
	define_spawn_name(command);
	attron(COLOR_PAIR(get_visu()->champ_nb + 12));
	while (x + (++y * MEM_TAB_LENGTH) < champ_size)
	{
		x = -1;
		while (++x < MEM_TAB_LENGTH)
		{
			if ((x + (y * MEM_TAB_LENGTH)) < champ_size)
			{
				move(get_visu()->champs[get_visu()->champ_nb]->spawn_y + y,
				get_visu()->champs[get_visu()->champ_nb]->spawn_x + (x * 3));
				champ[x + (y * MEM_TAB_LENGTH)] < 16 ? printw("0") : 0;
				printw("%x ", champ[x + (y * MEM_TAB_LENGTH)]);
			}
		}
		x = 0;
	}
}

static void		initialize_champ(void)
{
	if (!(get_visu()->champs))
		get_visu()->champs =
			(t_v_champ**)ft_memalloc(sizeof(t_v_champ) * (MAX_CHAMPS));
	get_visu()->champs[get_visu()->champ_nb] =
		(t_v_champ*)ft_memalloc(sizeof(t_v_champ));
	if (!get_visu()->champs || !get_visu()->champs[get_visu()->champ_nb])
		exit(1);
}

void			handle_champ_spawn(t_command *command)
{
	int			name_size;
	t_v_champ	*player;
	t_uchar		*champ;
	int			champ_size;

	initialize_champ();
	player = get_visu()->champs[get_visu()->champ_nb];
	player->id = read_int(command->data);
	name_size = read_short(command->data + 4);
	if (!(player->name = ft_strnew(name_size + 1)))
		exit(1);
	ft_memcpy(player->name, command->data + 6, name_size);
	champ_size = read_int(command->data + 6 + name_size + 4);
	if (!(champ = (t_uchar*)ft_strnew(champ_size)))
		exit(1);
	ft_memcpy(champ, command->data + name_size + 14,
			read_int(command->data + name_size + 10));
	print_champ(champ, champ_size, command);
	ft_strdel((char**)&champ);
	get_visu()->champ_nb++;
}

void			handle_champ_wins(t_command *command)
{
	int			x;
	int			y;
	int			i;
	char		*str;

	x = get_visu()->start_x + (MEM_TAB_LENGTH * 3) + 5;
	y = get_visu()->start_y + 11;
	i = 0;
	while (get_visu()->champs[i]->id != read_int(command->data))
		i++;
	str = ft_strdup(get_visu()->champs[i]->name);
	attron(COLOR_PAIR(3));
	print_win_panel(x, y, str);
	move(LINES, COLS);
	ft_strdel(&str);
}
