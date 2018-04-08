/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:45:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/07 04:35:51 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./logic.h"

t_logic					*get_logic(void)
{
	static int			set;
	static t_logic		logic;

	if (!set)
	{
		set = 1;
		logic.cycles_to_die = CYCLE_TO_DIE;
		logic.cycles_left = CYCLE_TO_DIE;
	}
	return (&logic);
}

/*
** Runs cycle for a single process. Returns 0 if OK, 1 if process crashes or
** did not report as alive, and -1 in case of error.
*/

static void				run_process_cycle(t_proc *process)
{
	t_logic				*logic;

	logic = get_logic();
	if (!process->current_task)
	{
		process->current_task = load_instr(process);
		process->current_task->run_cycle += logic->cycles - 1;
		call_instr_start(process);
	}
	if (process->current_task->run_cycle <= logic->cycles)
	{
		if (process->current_task->opcode)
			fill_instr(process);
		if (process->current_task->run_instr)
		{
			call_instr_exec(process);
			process->current_task->run_instr(process);
			logic->params.ncurse ? update_arena_visu(process) : 0;
		}
		if (!(process->current_task->opcode == I_ZJMP && process->carry == 1))
			process->pc += process->current_task->mem_size;
		process->pc %= MEM_SIZE;
		call_process_move(process);
		del_instr(process->current_task);
		process->current_task = NULL;
	}
}

static int				run_cycle(void)
{
	static int			next_active_cycle = -1;
	t_logic				*logic;
	t_llist				*tmp;
	t_llist				*tmp2;
	int					run;

	logic = get_logic();
	tmp = logic->queue;
	run = 0;
	if (next_active_cycle <= logic->cycles)
		while (tmp)
		{
			tmp2 = tmp->next;
			if (!((t_proc *)tmp->data)->dead)
			{
				run = 1;
				run_process_cycle((t_proc *)tmp->data);
				if (((t_proc *)tmp->data)->current_task)
					next_active_cycle = ft_nbrmin(
						((t_proc *)tmp->data)->current_task->run_cycle,
						next_active_cycle);
			}
			tmp = tmp2;
		}
	return (run);
}

static void				end_game(void)
{
	t_logic				*logic;

	logic = get_logic();
	endwin();
	if (logic->params.dump >= 0)
		print_arena_dump();
	else if (logic->last_live)
	{
		if (!logic->params.command_io)
			ft_printf("Player %s (%d) won at cycle %d.\n", logic->last_live->name,
				logic->last_live->id, logic->cycles);
		call_champ_win(logic->last_live);
	}
}

void					run_loop(t_champ *champs)
{
	t_logic				*logic;
	int					i;

	logic = get_logic();
	logic->champs = champs;
	i = -1;
	while (++i < logic->params.players)
	{
		call_champ_spawn(champs + i);
		spawn_process(load_process(champs + i, 0, NULL));
	}
	while (logic->queue && (logic->params.dump < 0 ||
		logic->cycles <= logic->params.dump))
	{
		call_new_cycle(logic);
		if (!run_cycle())
			break ;
		check_lives();
		logic->params.ncurse ? print_screen(logic) : 0;
		logic->cycles_left--;
		logic->cycles++;
	}
	ft_llist_del(&(logic->queue), &del_process);
	end_game();
}
