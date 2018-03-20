/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 23:36:13 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/20 22:57:58 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbose.h"

void		print_and(t_proc *proc)
{
	int i;
	int j;

	i = get_parameter_result(proc->current_task->par[1], proc, 0);
	j = get_parameter_result(proc->current_task->par[0], proc, 0);
	ft_printf("P%5d | ", proc->id + 1);
	print_instr((int)proc->current_task->opcode);
	ft_printf(" %d %d r%d\n", j, i, proc->current_task->par[2].value);
}

void		print_or(t_proc *proc)
{
	print_and(proc);
}

void		print_xor(t_proc *proc)
{
	print_and(proc);
}
