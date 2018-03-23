/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:35:46 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 22:41:54 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./instr.h"

static void			init_par(t_par *par, char type)
{
	par->type = type;
	if (par->type == T_RG)
		par->size = S_RG;
	else if (par->type == T_ID)
		par->size = S_ID;
	else if (par->type == T_D2)
		par->size = S_D2;
	else if (par->type == T_D4)
		par->size = S_D4;
}

static void			default_types(t_instr_def def, t_instr *instr)
{
	int				i;

	i = -1;
	while (++i < 3)
		init_par(instr->par + i, def.par_type[i]);
}

static int			read_ocp(t_proc *process, t_instr_def def,
						t_instr *instr)
{
	uchar			*buf;
	int				i;

	buf = read_memory(process->pc + process->owner->spawn,
		instr->mem_size, 1, 0);
	i = 3;
	instr->mem_size += 1;
	while (i--)
	{
		(*buf) >>= 2;
		if (i >= def.par_nbr)
			continue ;
		if (((*buf) & 0x03) == MT_RG)
			init_par(instr->par + i, T_RG);
		else if (((*buf) & 0x03) == MT_ID)
			init_par(instr->par + i, T_ID);
		else if (((*buf) & 0x03) == MT_DT)
			init_par(instr->par + i, (def.par_type[i] & T_D2) ? T_D2 : T_D4);
	}
	free(buf);
	return (0);
}

static t_value		result_from_mem(unsigned int size, uchar *mem)
{
	t_value			result;
	unsigned int	i;

	i = 0;
	result = 0;
	while (i < size)
	{
		result <<= 8;
		result |= mem[i] & 0xFF;
		i++;
	}
	return (result);
}

int					fill_parameters(t_proc *process, t_instr_def def, t_instr *instr)
{
	uchar			*buf;
	int				i;
	int				code;

	code = 0;
	if (def.flags & F_OCP)
	{
		if (read_ocp(process, def, instr))
			code = 2;
	}
	else
		default_types(def, instr);
	i = -1;
	while (++i < def.par_nbr)
	{
		buf = read_memory(process->pc + process->owner->spawn,
			instr->mem_size, instr->par[i].size, 0);
		instr->par[i].value = result_from_mem(instr->par[i].size, buf);
		if (!(instr->par[i].type & def.par_type[i]) ||
			(instr->par[i].type == T_RG &&
			(instr->par[i].value > REG_NUMBER || instr->par[i].value <= 0)))
			code = 1;
		instr->mem_size += instr->par[i].size;
		free(buf);
	}
	return (code);
}
