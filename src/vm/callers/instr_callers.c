/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_callers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:04:54 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/27 00:12:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				call_instr_start(t_proc *process)
{
	process = 0;
}

void				call_instr_exec(t_proc *process)
{
	t_logic			*logic;

	logic = get_logic();
	if (logic->params.verbose >= 0)
		verbose(process);
}
