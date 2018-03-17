/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 22:45:40 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/17 15:35:24 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		zjmp(void *or_proc)
{
	t_proc	*proc;
	t_instr	*instr;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	if (proc->carry)
		proc->pc += get_parameter_result(instr->par[0], proc, 0);
}
