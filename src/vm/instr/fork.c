/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 23:01:44 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/14 23:14:51 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/corewar.h"
#include "../../../inc/instructions.h"
#include "../../../inc/types.h"
#include "../../../inc/vm_params.h"

void		fork(void *or_proc)
{
	t_proc	*proc;
	t_proc	*child;
	t_instr	*instr;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	child = load_process(proc->owner, get_parameter_result(instr->par[0],
				proc, 1), proc);
	spawn_process(child);
}
