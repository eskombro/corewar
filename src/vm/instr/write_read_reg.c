/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_read_reg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:52:27 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/15 22:22:29 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				write_reg(t_reg reg, unsigned long value)
{
	int				i;

	i = REG_SIZE;
	while (i-- > 0)
	{
		reg[i] = value & 0xFF;
		value >>= 8;
	}
}

unsigned long		read_reg(t_reg reg)
{
	int				i;
	unsigned long	value;

	i = -1;
	value = 0;
	while (++i < REG_SIZE)
	{
		value <<= 8;
		value |= reg[i] & 0xFF;
	}
	return (value);
}

unsigned long		get_parameter_result(t_par par, t_proc *process, int restricted)
{
	unsigned long	result;
	unsigned char	*read;
	int				i;

	result = 0;
	if (par.type == T_RG)
		result = read_reg(process->reg[par.value - 1]);
	else if (par.type == T_ID)
	{
		read = read_memory(process->pc + process->owner->spawn, par.value, REG_SIZE, restricted);
		i = -1;
		while (++i < REG_SIZE)
		{
			result <<= 8;
			result |= read[i] & 0xFF;
		}
		free(read);
	}
	else
		result = par.value;
	return (result);
}
