/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:27:00 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/18 04:29:15 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbose.h"

void		print_add(t_proc  *proc)
{
	print_norm_line(proc, 3, 1);
}

void		print_sub(t_proc  *proc)
{
	print_norm_line(proc, 3, 1);
}

void		print_st(t_proc  *proc)
{
	proc->current_task->par[1].type = 0;
	proc->current_task->par[1].value = (short)proc->current_task->par[1].value;
	print_norm_line(proc, 2, 1);
}

void		print_sti(t_proc *proc)
{
	unsigned long i;
	unsigned long j;

	i = get_parameter_result(proc->current_task->par[2], proc, 1);
	j = get_parameter_result(proc->current_task->par[1], proc, 1);
	ft_printf("P%5d | ", proc->id + 1);
	print_instr(proc->current_task->opcode);
	ft_printf(" r%ld %ld %ld\n", proc->current_task->par[0].value, j % IDX_MOD,
			i % IDX_MOD);
	ft_printf("       | -> store to %ld + %ld = %ld (with pc and mod %ld)\n",
			j % IDX_MOD, i % IDX_MOD, (i + j) % IDX_MOD, (i + j + proc->pc)
			% MEM_SIZE);
}
