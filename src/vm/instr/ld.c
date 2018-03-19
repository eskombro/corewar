/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:11:41 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/19 19:46:48 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			load_direct(void *proc, int restricted)
{
	t_proc			*p1;
	t_value			value;
	char			*reg;

	p1 = (t_proc *)proc;
	reg = p1->reg[p1->current_task->par[1].value - 1];
	value = get_parameter_result(p1->current_task->par[0], p1, restricted);
	write_reg(reg, value);
	p1->carry = (value == 0 ? 1 : 0);
}

void				ld(void *proc)
{
	load_direct(proc, 1);
}

void				lld(void *proc)
{
	load_direct(proc, 0);
}
