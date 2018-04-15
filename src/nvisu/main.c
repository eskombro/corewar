/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:16:17 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/15 03:33:16 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"
#include "errno.h"

t_visu			*get_visu(void)
{
	static t_visu		v;

	return (&v);
}

void			initialize_ncurses(void)
{
	int			i;

	initscr();
	start_color();
	init_pair(1, 235, 232);
	init_pair(2, 16, 16);
	init_pair(3, 232, 241);
	init_pair(11, 235, 242);
	init_pair(12, 214, 232);
	init_pair(13, 91, 232);
	init_pair(14, 1, 232);
	init_pair(15, 34, 232);
	init_pair(22, 214, 242);
	init_pair(23, 91, 242);
	init_pair(24, 1, 242);
	init_pair(25, 34, 242);
	init_pair(32, 232, 214);
	init_pair(33, 232, 91);
	init_pair(34, 232, 1);
	init_pair(35, 232, 34);
	move(0, 0);
	i = -1;
	attron(COLOR_PAIR(2));
	while (++i < LINES)
		printw("%*s", COLS - 1, " ");
}

void			handle_command(t_command *command)
{
	if (command->type == COMMAND_CORE_BEGIN)
		handle_core_begin(command);
	else if (command->type == COMMAND_CHAMP_SPAWN)
		handle_champ_spawn(command);
	else if (command->type == COMMAND_PROC_SPAWN)
		handle_proc_spawn(command);
	else if (command->type == COMMAND_PROC_MOVE)
		handle_proc_move(command);
	else if (command->type == COMMAND_PROC_DEATH)
		handle_proc_death(command);
	else if (command->type == COMMAND_MEM_WRITE)
		handle_mem_write(command);
	else if (command->type == COMMAND_LOGIC_CYCLE)
		handle_logic_cycle(command);
	else if (command->type == COMMAND_LOGIC_LIVE)
		handle_logic_life(command);
	else if (command->type == COMMAND_CORE_END)
		handle_core_end();
	else if (command->type == COMMAND_CHAMP_WINS)
		handle_champ_wins(command);
}

void			read_loop(void)
{
	t_command	command;
	t_uchar		c[2];
	int			ret;

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
		handle_command(&command);
		display_leaderboard();
		display_stats();
		move(0, 0);
		refresh();
		usleep(0);
	}
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
