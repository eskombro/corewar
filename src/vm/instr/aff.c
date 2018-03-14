/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:18:16 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/14 23:32:03 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/corewar.h"
#include "../../../inc/instructions.h"
#include "../../../inc/types.h"
#include "../../../inc/vm_params.h"

void		aff(void *or_proc)
{
	int		i;
	t_proc	*proc;
	t_instr *instr;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	i = read_reg(proc->reg[instr->par[0].value]);
	i = i % 256;
	if (i == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	write(1, &i, 1);
}
