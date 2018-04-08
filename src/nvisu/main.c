/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:16:17 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/08 06:42:28 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"
#include "errno.h"

t_visu			*get_visu(void)
{
	static t_visu		v;

	return (&v);
}

void			display_arena(t_visu *v)
{
	int				x;
	int				y;


	y = -1;
	v->start_y = 12;
	v->start_x = (COLS - (MEM_TAB_LENGTH * 3)) / 2;
	while (++y < (v->m_size / MEM_TAB_LENGTH))
	{
		x = -1;
		move(v->start_y + y, v->start_x);
		while (++x < MEM_TAB_LENGTH)
		{
			attron(COLOR_PAIR(1));
			v->mem[(y * MEM_TAB_LENGTH) + x] <= 0xF ? printw("0") : 0;
			printw("%x ", v->mem[(y * MEM_TAB_LENGTH) + x]);
		}
		printw("\n");
	}
	v->mem_tab_height = y;
}

void 			print_champ(t_uchar *champ, int champ_size, t_command *command)
{
	int			x;
	int			y;
	int			spawn_x;
	int			spawn_y;
	int			name_size;

	y = -1;
	x = 0;
	name_size = read_short(command->data + 4);
	spawn_y = get_visu()->start_y + ((read_int(command->data + 6 + name_size)) / MEM_TAB_LENGTH);
	spawn_x = get_visu()->start_x + ((read_int(command->data + 6 + name_size)) % MEM_TAB_LENGTH);
	attron(COLOR_PAIR(get_visu()->champ_nb + 10));
	while (x + (++y * MEM_TAB_LENGTH) < champ_size)
	{
		x = -1;
		while (++x < MEM_TAB_LENGTH)
		{
			if ((x + (y * MEM_TAB_LENGTH)) < champ_size)
			{
				move(spawn_y + y, spawn_x + (x * 3));
				champ[x + (y * MEM_TAB_LENGTH)] < 16 ? printw("0") : 0;
				printw("%x ", champ[x + (y * MEM_TAB_LENGTH)]);
			}
		}
		x = 0;
	}
}

void			handle_champ_spawn(t_command *command)
{
	int			name_size;
	t_v_champ	*player;
	t_uchar		*champ;
	int			champ_size;

	if (!(get_visu()->champs))
		if (!((get_visu()->champs = (t_v_champ**)ft_memalloc(sizeof(t_v_champ) * (MAX_CHAMPS)))))
			exit(1);
	if (!((get_visu()->champs[get_visu()->champ_nb] = (t_v_champ*)ft_memalloc(sizeof(t_v_champ)))))
		exit(1);
	player = get_visu()->champs[get_visu()->champ_nb];
	player->id = read_int(command->data);
	name_size = read_short(command->data + 4);
	if (!(player->name = ft_strnew(name_size + 1)))
		exit(1);
	ft_memcpy(player->name, command->data + 6, name_size);
	champ_size = read_int(command->data + 6 + name_size + 4);
	if (!(champ = (t_uchar*)ft_strnew(champ_size)))
		exit(1);
	ft_memcpy(champ, command->data + 6 + name_size + 8, read_int(command->data + 6 + name_size + 4));
	print_champ(champ, champ_size, command);
	attron(COLOR_PAIR(2));
	free(champ);
	get_visu()->champ_nb++;
	attron(COLOR_PAIR(1));
}

void			handle_command(t_command *command)
{
	if (command->type == COMMAND_CORE_BEGIN)
	{
		get_visu()->m_size = read_int(command->data);
		if (!get_visu()->mem)
			if (!(get_visu()->mem = (t_uchar *)ft_memalloc(sizeof(t_uchar) * (get_visu()->m_size))))
				exit(1);
		display_arena(get_visu());
	}
	else if (command->type == COMMAND_CHAMP_SPAWN)
		handle_champ_spawn(command);
}

void			read_loop(void)
{
	t_command	command;
	t_uchar		c[2];
	int			ret;
	int			i;

	while ((ret = read(0, c, 1)) > 0)
	{
		command.type = c[0];
		ret = read(0, c, 2);
		if (ret != 2)
			break ;
		command.size = read_short(c);
		ret = read(0, command.data, command.size);
		if (ret != command.size)
			break ;
		//debug_command(command);
		handle_command(&command);
		refresh();
	}
	endwin();
	ft_strdel((char**)&get_visu()->mem);
	i = 0;
	while (get_visu()->champs[i])
	{
		free(get_visu()->champs[i]->name);
		free(get_visu()->champs[i++]);
	}
	free(get_visu()->champs);
}

void			initialize_ncurses(void)
{
	initscr();
	start_color();

	init_pair(1, 235, COLOR_BLACK);
	init_pair(20, 242, COLOR_BLACK);
	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(11, 34, COLOR_BLACK);
	init_pair(12, 214, COLOR_BLACK);
	init_pair(13, 91, COLOR_BLACK);
}

void			print_header2(int y, int x)
{
	move(y++, x);
	printw(" 888        888     888 888   d88P 8888888");
	printw("    888 d888b 888     d88P 888 888   d88P ");
	move(y++, x);
	printw(" 888        888     888 8888888P   888    ");
	printw("    888d88888b888    d88P  888 8888888P   ");
	move(y++, x);
	printw(" 888    888 888     888 888 T88b   888    ");
	printw("    88888P Y88888   d88P   888 888 T88b   ");
	move(y++, x);
	printw(" Y88b  d88P Y88b. .d88P 888  T88b  888    ");
	printw("    8888P   Y8888  d8888888888 888  T88b  ");
	move(y++, x);
	printw("   Y8888P     Y88888P   888   T88b 8888888");
	printw("888 888P     Y888 d88P     888 888   T88b ");
}

void			print_header(void)
{
	int		y;
	int		x;

	attron(COLOR_PAIR(20));

	y = 0;
	x = (COLS - 83) / 2;
	move(y++, x);
	move(y++, x);
	printw("  .d8888b.   .d88888b.  8888888b.  8888888");
	printw("888 888       888        d8888 8888888b.  ");
	move(y++, x);
	printw(" d88P  Y88b d88P   Y88b 888   Y88b 888    ");
	printw("    888   o   888       d88888 888   Y88b ");
	move(y++, x);
	printw(" 888    888 888     888 888    888 888    ");
	printw("    888  d8b  888      d88P888 888    888 ");
	print_header2(y, x);
}

int				main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	run_corewar(argv);
	initialize_ncurses();
	print_header();
	read_loop();
	return (0);
}
