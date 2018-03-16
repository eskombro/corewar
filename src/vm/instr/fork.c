/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:01:44 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/16 18:36:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		sfork(void *or_proc)
{
	t_proc	*proc;
	t_proc	*child;
	t_instr	*instr;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	child = load_process(proc->owner,
				proc->pc +
				(get_parameter_result(instr->par[0], proc, 1) % IDX_MOD), proc);
	spawn_process(child);
}
