/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:11:41 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/19 21:44:38 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	load_indirect(void *proc, int restricted)
{
	t_proc		*p1;
	t_addr		address;
	char		*reg;
	uchar		*ustr;
	int			i;

	p1 = (t_proc *)proc;
	i = -1;
	reg = p1->reg[p1->current_task->par[2].value - 1];
	address = get_parameter_result(p1->current_task->par[0], p1, restricted);
	address += get_parameter_result(p1->current_task->par[1], p1, restricted);
	ustr = read_memory(p1->pc + p1->owner->spawn, address, REG_SIZE, restricted);
	while (++i < REG_SIZE)
		reg[i] = ustr[i];
	p1->carry = (read_reg(reg) == 0 ? 1 : 0);
}

void		ldi(void *proc)
{
	load_indirect(proc, 1);
}

void		lldi(void *proc)
{
	load_indirect(proc, 0);
}
