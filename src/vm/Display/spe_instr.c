/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:14:11 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/18 04:18:55 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbose.h"

void		print_aff(t_proc *proc)
{
	proc->current_task->opcode = I_AFF;
}

void		print_fork(t_proc *proc)
{
	ft_printf("P%5d | ", proc->id + 1);
	ft_printf("fork %ld (%ld)\n", proc->current_task->par[0].value,
			proc->current_task->par[0].value + proc->pc);
}

void		print_lfork(t_proc  *proc)
{
	ft_printf("P%5d | ", proc->id + 1);
	ft_printf("lfork %ld (%ld)\n", proc->current_task->par[0].value,
			proc->current_task->par[0].value + proc->pc);
}

void		print_zjmp(t_proc *proc)
{
	ft_printf("P%5d | ", proc->id + 1);
	print_instr((int)proc->current_task->opcode);
	ft_printf(" %ld",get_parameter_result(proc->current_task->par[0], proc, 0));
	if (proc->carry == 0)
		ft_printf(" FAILED\n");
	else
		ft_printf(" OK\n");
}

void		print_live(t_proc *proc)
{
	print_norm_line(proc, 1, 0);

// je ne sais pas qund cette ligne doit sortir...
//	ft_printf("Player %d (%s) is said to be alive\n", proc->owner->id,
//			proc->owner->name);
}
