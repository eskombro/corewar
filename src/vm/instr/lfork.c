/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:01:51 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/15 18:36:31 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		lfork(void *or_proc)
{
	t_proc	*proc;
	t_proc	*child;
	t_instr	*instr;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	child = load_process(proc->owner, get_parameter_result(instr->par[0],
				proc, 0), proc);
	spawn_process(child);
}