/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:27:00 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/20 23:11:21 by bacrozat         ###   ########.fr       */
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
	t_par par;

	par = proc->current_task->par[1];
	proc->current_task->par[1].type = 0;
	proc->current_task->par[1].value = (short)par.value;
	print_norm_line(proc, 2, 1);
	proc->current_task->par[1] = par;
	
}

void		print_sti(t_proc *proc)
{
	int i;
	int j;

	i = get_parameter_result(proc->current_task->par[2], proc, 1) % IDX_MOD;
	j = get_parameter_result(proc->current_task->par[1], proc, 1) % IDX_MOD;
	ft_printf("P%5d | ", proc->id + 1);
	print_instr(proc->current_task->opcode);
	ft_printf(" r%d %d %d\n", proc->current_task->par[0].value, j ,
			i);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			j, i, i + j, (i + j) % IDX_MOD +
			(((proc->pc % MEM_SIZE) + MEM_SIZE) % MEM_SIZE));
}
