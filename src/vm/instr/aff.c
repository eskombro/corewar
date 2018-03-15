/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:18:16 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/15 18:52:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	ft_putchar(i);
}
