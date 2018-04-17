/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:03:05 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/17 17:46:56 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbose.h"

void		print_ld(t_proc *proc)
{
	print_norm_line(proc, 2, 1);
}

void		print_ldi(t_proc *proc)
{
	int i;
	int j;

	i = get_parameter_result(proc->current_task->par[1], proc, 1);
	j = get_parameter_result(proc->current_task->par[0], proc, 1);
	ft_dprintf(2, "P%5d | ", proc->id + 1);
	print_instr(proc->current_task->opcode);
	ft_dprintf(2, " %d %d r%d\n", j, i, proc->current_task->par[2].value);
	ft_dprintf(2, "       | -> load from %d + %d = %d (with pc and mod %d)\n",
			j, i, i + j, (i + j) % IDX_MOD +
			(((proc->pc + proc->owner->spawn % MEM_SIZE) + MEM_SIZE)
				% MEM_SIZE));
}

void		print_lld(t_proc *proc)
{
	print_norm_line(proc, 2, 0);
}

void		print_lldi(t_proc *proc)
{
	int i;
	int j;

	i = get_parameter_result(proc->current_task->par[1], proc, 1);
	j = get_parameter_result(proc->current_task->par[0], proc, 1);
	ft_dprintf(2, "P%5d | ", proc->id + 1);
	print_instr(proc->current_task->opcode);
	ft_dprintf(2, " %d %d r%d\n", j, i, proc->current_task->par[2].value);
	ft_dprintf(2, "       | -> load from %d + %d = %d (with pc %d)\n",
			j, i, i + j, (i + j) % MEM_SIZE +
			(((proc->pc + proc->owner->spawn % MEM_SIZE) + MEM_SIZE)
				% MEM_SIZE));
}
