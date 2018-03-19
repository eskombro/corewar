/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_read_reg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:52:27 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/19 21:29:34 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				write_reg(t_reg reg, t_value value)
{
	int				i;

	i = REG_SIZE;
	while (i-- > 0)
	{
		reg[i] = value & 0xFF;
		value >>= 8;
	}
}

t_value				read_reg(t_reg reg)
{
	int				i;
	t_value			value;

	i = -1;
	value = 0;
	while (++i < REG_SIZE)
	{
		value <<= 8;
		value |= reg[i] & 0xFF;
	}
	return (value);
}

t_value				get_parameter_result(t_par par, t_proc *process, int restricted)
{
	t_value			result;
	unsigned char	*read;
	int				i;

	result = 0;
	if (par.type == T_RG)
		result = read_reg(process->reg[par.value - 1]);
	else if (par.type == T_ID)
	{
		read = read_memory(process->pc + process->owner->spawn, (short)par.value, REG_SIZE, restricted);
		i = -1;
		while (++i < REG_SIZE)
		{
			result <<= 8;
			result |= read[i] & 0xFF;
		}
		free(read);
	}
	else if (par.type == T_D2)
		result = (short)par.value;
	else
		result = par.value;
	return (result);
}
