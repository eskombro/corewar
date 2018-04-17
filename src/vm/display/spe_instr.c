/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 22:14:11 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/17 17:47:50 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbose.h"

void		print_aff(t_proc *proc)
{
	proc->current_task->opcode = I_AFF;
}

void		print_fork(t_proc *proc)
{
	ft_dprintf(2, "P%5d | ", proc->id + 1);
	ft_dprintf(2, "fork %d (%d)\n", (short)proc->current_task->par[0].value,
			(((short)proc->current_task->par[0].value % IDX_MOD) +
				proc->pc + proc->owner->spawn) % MEM_SIZE);
}

void		print_lfork(t_proc *proc)
{
	ft_dprintf(2, "P%5d | ", proc->id + 1);
	ft_dprintf(2, "lfork %d (%d)\n", (short)proc->current_task->par[0].value,
			(short)proc->current_task->par[0].value + proc->pc +
				proc->owner->spawn % MEM_SIZE);
}

void		print_zjmp(t_proc *proc)
{
	ft_dprintf(2, "P%5d | ", proc->id + 1);
	print_instr((int)proc->current_task->opcode);
	ft_dprintf(2, " %d", get_parameter_result(proc->current_task->par[0], proc, 0));
	if (proc->carry == 0)
		ft_dprintf(2, " FAILED\n");
	else
		ft_dprintf(2, " OK\n");
}

void		print_live(t_proc *proc)
{
	ft_dprintf(2, "P%5d | ", proc->id + 1);
	print_instr((int)proc->current_task->opcode);
	ft_dprintf(2, " %d\n", get_parameter_result(proc->current_task->par[0], proc,
				0));
}
