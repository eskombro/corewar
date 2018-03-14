/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:11:41 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/14 23:02:24 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	load_indirect(void *proc, int restricted)
{
	t_proc		*p1;
	long		address;
	t_reg		*reg;
	uchar		*ustr;
	int			i;

	p1 = (t_proc *)proc;
	i = -1;
	reg = &(p1->reg[p1->current_task->par[2].value]);
	address = get_parameter_result(p1->current_task->par[0], p1, restricted);
	address += get_parameter_result(p1->current_task->par[1], p1, restricted);
	ustr = read_memory(p1->pc, address, REG_SIZE, 1);
	while (++i < REG_SIZE)
		*reg[i] = ustr[i];
	p1->carry = (!ustr ? 1 : 0);
}

void		ldi(void *proc)
{
	load_indirect(proc, 1);
}

void		lldi(void *proc)
{
	load_indirect(proc, 0);
}
