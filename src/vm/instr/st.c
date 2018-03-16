/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:47:38 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/16 18:10:24 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				st(void *proc)
{
	t_proc			*p1;
	unsigned long	value;
	t_par			par;

	p1 = (t_proc *)proc;
	value = read_reg(p1->reg[p1->current_task->par[0].value - 1]);
	if (p1->current_task->par[1].type == T_RG)
		write_reg(p1->reg[p1->current_task->par[1].value - 1], value);
	else
	{
		par.type = T_D4;
		par.size = S_D4;
		par.value = value;
		write_memory(p1->pc + p1->owner->spawn,
			p1->current_task->par[1].value, par);
	}
	p1->carry = (value == 0 ? 1 : 0);
}
