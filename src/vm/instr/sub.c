/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:19:31 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/15 18:37:07 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		sub(void *or_proc)
{
	t_proc	*proc;
	t_instr	*instr;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	write_reg(proc->reg[instr->par[2].value],
			read_reg(proc->reg[instr->par[0].value]) -
			read_reg(proc->reg[instr->par[1].value]));
	if (read_reg(proc->reg[instr->par[2].value]) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
