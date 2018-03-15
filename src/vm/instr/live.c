/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:51:38 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/15 23:06:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		live(void *ptr)
{
	t_proc	*proc;

	proc = (t_proc *)ptr;
	proc->lives++;
	report_live(get_parameter_result(proc->current_task->par[0], proc, 0));
}
