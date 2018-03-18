/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:03:05 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/18 02:18:08 by bacrozat         ###   ########.fr       */
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

	i = get_parameter_result(proc->current_task->par[0], proc, 1);
	j = get_parameter_result(proc->current_task->par[1], proc, 1);
	print_norm_line(proc, 3, 1);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n", i, j, i + j,
			i + j + proc->pc);
}

void		print_lld(t_proc *proc)
{
	print_norm_line(proc, 2, 0);
}

void		print_lldi(t_proc *proc)
{
	int i;
	int j;

	i = get_parameter_result(proc->current_task->par[0], proc, 1);
	j = get_parameter_result(proc->current_task->par[1], proc, 1);
	print_norm_line(proc, 3, 0);
	ft_printf("       | -> load from %d + %d = %d (with pc %d)\n", i, j,
			i + j, i + j + proc->pc);
}
