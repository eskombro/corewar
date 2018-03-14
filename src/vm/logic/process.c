/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 23:00:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/13 13:19:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc			*load_process(t_champ *owner, t_addr addr, t_proc *parent)
{
	t_proc		*process;
	int			i;

	if (!(process = (t_proc *)ft_memalloc(sizeof(t_proc))))
		exit(1);
	process->owner = owner;
	process->pc = addr;
	if (parent)
	{
		i = -1;
		while (++i < REG_NUMBER)
			ft_memcpy(process->reg[i], parent->reg[i], sizeof(t_reg));
	}
	return (process);
}