/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 22:45:40 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/14 23:01:20 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/corewar.h"
#include "../../../inc/instructions.h"
#include "../../../inc/types.h"
#include "../../../inc/vm_params.h"

void		zjmp(void *or_proc)
{
	t_proc	*proc;
	t_instr	*instr;

	proc = (t_proc*)or_proc;
	instr = proc->current_task;
	if (proc->carry)
		proc->pc = get_parameter_result(instr->par[0], proc, 0);
}
