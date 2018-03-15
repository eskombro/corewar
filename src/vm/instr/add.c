/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:11:01 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/15 20:14:33 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		add(void *or_proc)
{
	t_proc	*proc;
	t_instr	*instr;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	write_reg(proc->reg[instr->par[2].value - 1],
			read_reg(proc->reg[instr->par[1].value - 1]) +
			read_reg(proc->reg[instr->par[0].value - 1]));
	if (read_reg(proc->reg[instr->par[2].value - 1]) == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
