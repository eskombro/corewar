/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:01:51 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/14 23:15:09 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/corewar.h"
#include "../../../inc/instructions.h"
#include "../../../inc/types.h"
#include "../../../inc/vm_params.h"

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
