/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:27:00 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/18 02:55:45 by bacrozat         ###   ########.fr       */
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
	print_norm_line(proc, 2, 1);
}

void		print_sti(t_proc *proc)
{
	int i;
	int j;

	i = get_parameter_result(proc->current_task->par[0], proc, 1);
	j = get_parameter_result(proc->current_task->par[1], proc, 1);
	print_norm_line(proc, 3, 1);
	ft_printf("       | -> store from %d + %d = %d (with pc and mod %d)", j,
			i, i + j, i + j + proc->pc);
	ft_printf("(%ld + %ld )\n", read_reg(proc->reg[proc->current_task->par[1].value]) , read_reg(proc->reg[proc->current_task->par[1].value]));
}
