/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:29:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/19 21:29:28 by hbouillo         ###   ########.fr       */
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
	child = load_process(proc->owner, proc->pc +
			get_parameter_result(instr->par[0], proc, 0), proc);
	spawn_process(child);
}
