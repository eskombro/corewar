/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 22:12:41 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/14 22:45:52 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/corewar.h"
#include "../../../inc/instructions.h"
#include "../../../inc/types.h"
#include "../../../inc/vm_params.h"

void		or(void *or_proc)
{
	t_proc	*proc;
	t_instr	*instr;
	int		res;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	res = get_parameter_result(instr->par[0], proc, 1) |
		get_parameter_result(instr->par[1], proc, 1);
	write_reg(proc->reg[instr->par[2].value], res);
	if (res == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
