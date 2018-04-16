/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:16:17 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 19:13:57 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"
#include "errno.h"

t_visu		*get_visu(void)
{
	static t_visu		v;

	return (&v);
}

void		handle_command(t_command *command)
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

int			handle_read_line(t_command *command, t_time *curr_t, t_time *last_t)
{
	t_uchar			c[2];
	int				ret;

	if ((ret = read(5, c, 1)) > 0)
	{
		command->type = c[0];
		if (command->type == COMMAND_LOGIC_CYCLE)
			*last_t = *curr_t;
		ret = read(5, c, 2);
		if (ret != 2)
			return (1);
		command->size = read_short(c);
		ret = read(5, command->data, command->size);
		if (ret != command->size)
			return (1);
		handle_command(command);
	}
	return (0);
}

void		read_loop(void)
{
	t_command		command;
	t_time			curr_t;
	static t_time	last_t;

	while (1)
	{
		if (get_visu()->run)
		{
			clock_gettime(CLOCK_MONOTONIC_RAW, &curr_t);
			if (!get_visu()->end)
			{
				if ((curr_t.tv_sec * SECOND + curr_t.tv_nsec) - (last_t.tv_sec *
					SECOND + last_t.tv_nsec) > SECOND / get_visu()->cps)
					if (handle_read_line(&command, &curr_t, &last_t))
						break ;
				display_leaderboard();
				display_shortcuts();
				refresh();
			}
			move(1, 0);
		}
		display_stats();
		test_char();
	}
}

int			main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	run_corewar(argv);
	initialize_ncurses();
	noecho();
	nocbreak();
	curs_set(0);
	timeout(0);
	get_visu()->cps = 100;
	get_visu()->run = 1;
	print_header();
	read_loop();
	return (0);
}
