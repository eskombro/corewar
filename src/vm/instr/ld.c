/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:11:41 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/14 23:06:21 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	load_direct(void *proc, int restricted)
{
	t_proc		*p1;
	long		value;
	t_reg		*reg;

	p1 = (t_proc *)proc;
	reg = &(p1->reg[p1->current_task->par[1].value]);
	value = get_parameter_result(p1->current_task->par[0], p1, restricted);
	write_reg(*reg, value);
	p1->carry = (p1->current_task->par[0].value == 0 ? 1 : 0);
}

void		ld(void *proc)
{
	load_direct(proc, 1);
}

void		lld(void *proc)
{
	load_direct(proc, 0);
}
