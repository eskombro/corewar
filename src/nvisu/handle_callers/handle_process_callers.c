/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process_callers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:46:20 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/15 03:15:22 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

static void		store_process(t_v_proc *proc)
{
	t_v_proc	*tmp;

	if (!(get_visu()->procs[proc->id % PROC_TAB_SIZE]))
		get_visu()->procs[proc->id % PROC_TAB_SIZE] = proc;
	else
	{
		tmp = get_visu()->procs[proc->id % PROC_TAB_SIZE];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = proc;
	}
}

void			handle_proc_spawn(t_command *command)
{
	t_v_proc	*proc;
	int			i;

	i = 0;
	if (!(get_visu()->procs))
		if (!(get_visu()->procs =
			(t_v_proc**)ft_memalloc(sizeof(t_v_proc*) * (PROC_TAB_SIZE + 1))))
			exit(1);
	if (!((proc = (t_v_proc*)ft_memalloc(sizeof(t_v_proc)))))
		exit(1);
	proc->id = read_int(command->data);
	proc->owner_id = read_int(command->data + 4);
	while (get_visu()->champs[i]->id != proc->owner_id)
		i++;
	proc->owner = get_visu()->champs[i];
	proc->pc = read_int(command->data + 8);
	get_visu()->mem_proc[(proc->owner->spawn + proc->pc)
		% get_visu()->m_size]++;
	store_process(proc);
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
	while (proc && proc->id != id)
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

static void		visu_kill_proc(t_v_proc *proc, int id, t_v_proc *prev)
{
	int			pc_rel_spawn;

	pc_rel_spawn = proc->pc + proc->owner->spawn;
	while (pc_rel_spawn < 0)
		pc_rel_spawn += get_visu()->m_size;
	get_visu()->mem_proc[pc_rel_spawn % get_visu()->m_size]--;
	display_proc_pc(proc);
	if (prev == NULL)
		get_visu()->procs[id % PROC_TAB_SIZE] = proc->next;
	else
		prev->next = proc->next;
	ft_memdel((void**)&proc);
}

void			handle_proc_death(t_command *command)
{
	t_v_proc	*proc;
	t_v_proc	*prev;
	int			id;

	id = read_int(command->data);
	proc = get_visu()->procs[id % PROC_TAB_SIZE];
	prev = NULL;
	while (proc)
	{
		if (proc->id == id)
		{
			visu_kill_proc(proc, id, prev);
			break ;
		}
		prev = proc;
		proc = proc->next;
	}
}
