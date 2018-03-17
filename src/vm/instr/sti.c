/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:47:11 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/17 16:03:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				sti(void *proc)
{
	t_proc			*p1;
	unsigned long	value;
	unsigned long	address;
	t_par			par;

	p1 = (t_proc *)proc;
	value = read_reg(p1->reg[p1->current_task->par[0].value - 1]);
	address = get_parameter_result(p1->current_task->par[1], p1, 1);
	address += get_parameter_result(p1->current_task->par[2], p1, 1);
	par.type = T_D4;
	par.size = S_D4;
	par.value = value;
	write_memory(p1->pc + p1->owner->spawn, address, par);
}
