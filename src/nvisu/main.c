/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:16:17 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/14 20:05:34 by sjimenez         ###   ########.fr       */
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
	v->start_y = 14;
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

void			display_leaderboard(void)
{
	t_visu		*v;
	int			i;
	int			y;

	i = -1;
	v = get_visu();
	y = v->start_y;
	while (++i < v->champ_nb)
	{
		attron(COLOR_PAIR(i + 32));
		move(y++, v->start_x - 45);
		printw("*--------------------------------------*");
		move(y++, v->start_x - 45);
		printw("|                                      |");
		move(y++, v->start_x - 45);
		printw("|\tPlayer %-24d |", v->champs[i]->id);
		move(y++, v->start_x - 45);
		printw("|\t%-31.31s |", v->champs[i]->name);
		move(y++, v->start_x - 45);
		printw("|\tLives this round: %-13d |", v->champs[i]->lifes_round);
		move(y++, v->start_x - 45);
		printw("|\tLives: %-24d |", v->champs[i]->lifes);
		move(y++, v->start_x - 45);
		printw("|                                      |");
		move(y++, v->start_x - 45);
		printw("*--------------------------------------*");
		y++;
	}
}

void			display_stats(void)
{
	t_visu		*v;
	int			i;
	int			y;

	i = -1;
	v = get_visu();
	y = v->start_y;
	attron(COLOR_PAIR(33));
	move(y++, v->start_x + (MEM_TAB_LENGTH * 3) + 5);
	printw("*--------------------------------------*");
	move(y++, v->start_x + (MEM_TAB_LENGTH * 3) + 5);
	printw("|\tCycles:       %- 13d       |", v->stats->cycles);
	move(y++, v->start_x + (MEM_TAB_LENGTH * 3) + 5);
	printw("|\tCycles to die: %-6d             |", v->stats->cycles_to_die);
	move(y++, v->start_x + (MEM_TAB_LENGTH * 3) + 5);
	printw("|\tCycles left:   %-8d           |", v->stats->cycles_left);
	move(y++, v->start_x + (MEM_TAB_LENGTH * 3) + 5);
	printw("|\tLast live:     %-18s |", v->stats->last_life);
	move(y++, v->start_x + (MEM_TAB_LENGTH * 3) + 5);
	printw("|                                      |");
	move(y++, v->start_x + (MEM_TAB_LENGTH * 3) + 5);
	printw("|                                      |");
	move(y++, v->start_x + (MEM_TAB_LENGTH * 3) + 5);
	printw("*--------------------------------------*");
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
	get_visu()->champs[get_visu()->champ_nb]->spawn = read_int(command->data + 6 + name_size);
	spawn_y = get_visu()->start_y + ((read_int(command->data + 6 + name_size)) / MEM_TAB_LENGTH);
	spawn_x = get_visu()->start_x + ((read_int(command->data + 6 + name_size)) % MEM_TAB_LENGTH);
	get_visu()->champs[get_visu()->champ_nb]->spawn_y = spawn_y;
	get_visu()->champs[get_visu()->champ_nb]->spawn_x = spawn_x;
	attron(COLOR_PAIR(get_visu()->champ_nb + 12));
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
	free(champ);
	get_visu()->champ_nb++;
	attron(COLOR_PAIR(1));
}

int			display_proc_pc_calc(int col, int pc_rel_spawn)
{
	if (col == 1 || (col >= 12 && col <= 15))
	{
		if (get_visu()->mem_proc[pc_rel_spawn % get_visu()->m_size] == 1)
			col += 10;
	}
	else if (col == 11 || (col >= 22 && col <= 25))
	{
		if (get_visu()->mem_proc[pc_rel_spawn % get_visu()->m_size] == 0)
			col -= 10;
	}
	return (col);
}

void			display_proc_pc(t_v_proc *proc)
{
	int			i;
	int			pos_x;
	int			pos_y;
	char		chstr[3];
	int			col;
	int			pc_rel_spawn;

	i = 0;
	while (get_visu()->champs[i]->id != proc->owner_id)
		i++;
	pc_rel_spawn = proc->pc + proc->owner->spawn;
	while (pc_rel_spawn < 0)
		pc_rel_spawn += get_visu()->m_size;
	pos_y = get_visu()->start_y + (((pc_rel_spawn
		% get_visu()->m_size) / MEM_TAB_LENGTH));
	pos_x = get_visu()->start_x + (3 * ((pc_rel_spawn
		% get_visu()->m_size) % MEM_TAB_LENGTH));
	chstr[0] = mvinch(pos_y, pos_x) & A_CHARTEXT;
	chstr[1] = mvinch(pos_y, pos_x + 1) & A_CHARTEXT;
	chstr[2] = 0;
	col = ((mvinch(pos_y, pos_x) & A_COLOR) % 255);
	col = display_proc_pc_calc(col, pc_rel_spawn);
	attron(COLOR_PAIR(col));
	move(pos_y, pos_x);
	printw(chstr);
}

void			handle_proc_spawn(t_command *command)
{
	t_v_proc	*proc;
	t_v_proc	*tmp;
	int			i;

	i = 0;
	if (!(get_visu()->procs))
		if (!(get_visu()->procs = (t_v_proc**)ft_memalloc(sizeof(t_v_proc*) * (PROC_TAB_SIZE + 1))))
			exit(1);
	if (!((proc = (t_v_proc*)ft_memalloc(sizeof(t_v_proc)))))
		exit (1);
	proc->id = read_int(command->data);
	proc->owner_id = read_int(command->data + 4);
	while (get_visu()->champs[i]->id != proc->owner_id)
		i++;
	proc->owner = get_visu()->champs[i];
	proc->pc = read_int(command->data + 8);
	get_visu()->mem_proc[(proc->owner->spawn + proc->pc) % get_visu()->m_size]++;
	if (!(get_visu()->procs[proc->id % PROC_TAB_SIZE]))
		get_visu()->procs[proc->id % PROC_TAB_SIZE] = proc;
	else
	{
		tmp = 	get_visu()->procs[proc->id % PROC_TAB_SIZE];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = proc;
	}
	display_proc_pc(proc);
}

void			handle_proc_move(t_command *command)
{
	int			id;
	t_v_proc	*proc;
	int			pc_rel_spawn;

	proc = NULL;
	id = read_int(command->data);
	proc = get_visu()->procs[id % PROC_TAB_SIZE];
	while (proc->id != id && proc->next)
		proc = proc->next;
	pc_rel_spawn = proc->pc + proc->owner->spawn;
	while (pc_rel_spawn < 0)
		pc_rel_spawn += get_visu()->m_size;
	get_visu()->mem_proc[pc_rel_spawn % get_visu()->m_size]--;
	display_proc_pc(proc);
	proc->pc = read_int(command->data + 4);
	pc_rel_spawn = proc->pc + proc->owner->spawn;
	while (pc_rel_spawn < 0)
		pc_rel_spawn += get_visu()->m_size;
	get_visu()->mem_proc[pc_rel_spawn % get_visu()->m_size]++;
	display_proc_pc(proc);
}

void			handle_proc_death(t_command *command)
{
	t_v_proc	*proc;
	t_v_proc	*prev;
	int			id;
	int			pc_rel_spawn;

	id = read_int(command->data);
	proc = get_visu()->procs[id % PROC_TAB_SIZE];
	prev = NULL;
	while (proc)
	{
		if (proc->id == id)
		{
			pc_rel_spawn = proc->pc + proc->owner->spawn;
			while (pc_rel_spawn < 0)
				pc_rel_spawn += get_visu()->m_size;
			get_visu()->mem_proc[pc_rel_spawn % get_visu()->m_size]--;
			display_proc_pc(proc);
			if (prev == NULL)
				get_visu()->procs[id % PROC_TAB_SIZE] = proc->next;
			else
				prev->next = proc->next;
		}
		prev = proc;
		proc = proc->next;
	}
}

int			find_proc_owner_nb(int proc_id)
{
	int			nb;
	t_v_proc	*proc;

	nb = 0;
	proc = get_visu()->procs[proc_id % PROC_TAB_SIZE];
	while (proc->id != proc_id)
		proc = proc->next;
	while (get_visu()->champs[nb] != proc->owner)
		nb++;
	return (nb);
}

void			handle_mem_write(t_command *command)
{
	int			final_address;
	int			value;
	int			pos_y;
	int			pos_x;
	int			i;

	i = -1;
	final_address = read_int(command->data + 4);
	while (final_address < 0)
		final_address += get_visu()->m_size;
	value = read_int(command->data + 8);
	attron(COLOR_PAIR(find_proc_owner_nb(read_int(command->data)) + 12));
	while (++i < 4)
	{
		pos_y = get_visu()->start_y + (((final_address % get_visu()->m_size)
			/ MEM_TAB_LENGTH));
		pos_x = get_visu()->start_x + (3 * ((final_address % get_visu()->m_size)
			% MEM_TAB_LENGTH));
		mvprintw(pos_y, pos_x, "%2.2x ", ((value & (0xFF000000)) >> 24));
		value <<= 8;
		final_address++;
	}
}

void			handle_logic_cycle(t_command *command)
{
	int			i;

	i = 0;
	get_visu()->stats->cycles = read_int(command->data);
	get_visu()->stats->cycles_to_die = read_int(command->data + 4);
	get_visu()->stats->cycles_left = read_int(command->data + 8);
	if (get_visu()->stats->cycles_left == 0)
	{
		while (i < get_visu()->champ_nb)
			get_visu()->champs[i++]->lifes_round = 0;
	}
	display_leaderboard();
}

void			handle_core_end()
{
	char		str[2];
	move(0,0);
	read(0, str, 1);
}

void			handle_logic_life(t_command *command)
{
	int		proc_id;
	int		champ_nb;

	proc_id = read_int(command->data);
	champ_nb = find_proc_owner_nb(proc_id);
	get_visu()->champs[champ_nb]->lifes++;
	get_visu()->champs[champ_nb]->lifes_round++;
	ft_strncpy(get_visu()->stats->last_life, get_visu()->champs[champ_nb]->name, 15);
	display_stats();
}

void			handle_command(t_command *command)
{
	if (command->type == COMMAND_CORE_BEGIN)
	{
		get_visu()->m_size = read_int(command->data);
		if (!get_visu()->mem)
			if (!(get_visu()->mem = (t_uchar *)ft_memalloc(sizeof(t_uchar) * (get_visu()->m_size)))
				|| !(get_visu()->mem_proc = (int *)ft_memalloc(sizeof(int) * (get_visu()->m_size)))
				|| !(get_visu()->stats = (t_v_stats*)ft_memalloc(sizeof(t_v_stats))))
					exit(1);
		display_arena(get_visu());
	}
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
	else if (command->type == COMMAND_CORE_END)
		handle_core_end();
	else if (command->type == COMMAND_LOGIC_LIVE)
		handle_logic_life(command);
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
		display_leaderboard();
		display_stats();
		refresh();
		usleep(600);
	}
	endwin();
	ft_strdel((char**)&get_visu()->mem);
	i = 0;
	while (i < get_visu()->champ_nb)
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
	/*move (0,0);
	int i;
	i = 0;
	while (i < 255)
	{
		init_pair(i, i, COLOR_BLACK);
		attron(COLOR_PAIR(i));
		printw("%.3d", i++);
	}*/
	init_pair(1, 235, 232);
	init_pair(2, 235, 235);
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
}

void			print_header2(int y, int x, int i)
{
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i -= 2));
	printw(" 888        888     888 888   d88P 8888888");
	printw("    888 d888b 888     d88P 888 888   d88P ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw(" 888        888     888 8888888P   888    ");
	printw("    888d88888b888    d88P  888 8888888P   ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw(" 888    888 888     888 888 T88b   888    ");
	printw("    88888P Y88888   d88P   888 888 T88b   ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw(" Y88b  d88P Y88b. .d88P 888  T88b  888    ");
	printw("    8888P   Y8888  d8888888888 888  T88b  ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw("   Y8888P     Y88888P   888   T88b 8888888");
	printw("888 888P     Y888 d88P     888 888   T88b ");
	attron(COLOR_PAIR(1));
}

void			print_header(void)
{
	int		y;
	int		x;
	int		i;

	y = 3;
	i = 246;
	x = (COLS - 83) / 2;
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i--));
	printw("  .d8888b.   .d88888b.  8888888b.  8888888");
	printw("888 888       888        d8888 8888888b.  ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i -= 2));
	printw(" d88P  Y88b d88P   Y88b 888   Y88b 888    ");
	printw("    888   o   888       d88888 888   Y88b ");
	move(y++, x);
	init_pair(i, i, COLOR_BLACK);
	attron(COLOR_PAIR(i -= 2));
	printw(" 888    888 888     888 888    888 888    ");
	printw("    888  d8b  888      d88P888 888    888 ");
	print_header2(y, x, i);
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
