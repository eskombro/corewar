/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:51:38 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/17 15:35:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		live(void *ptr)
{
	t_proc	*proc;

	proc = (t_proc *)ptr;
	report_live(proc,
		get_parameter_result(proc->current_task->par[0], proc, 0));
}
