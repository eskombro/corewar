/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:21:16 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 22:01:26 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_param(char type, char ocp, t_par *par)
{
	int code;

	code = 0;
	if ((ocp & MT_ID) == MT_ID)
	{
		if (!(type & T_ID))
			return (code);
		par->type = T_ID;
		code = 2;
	}
	else if ((ocp & MT_RG) == MT_RG)
	{
		if (!(type & T_RG))
			return (code);
		par->type = T_RG;
		code = 1;
	}
	else if ((ocp & MT_DT) == MT_DT)
	{
		if (!(type & T_D2) && !(type & T_D4))
			return (code);
		par->type = (type & T_D2) ? T_D2 : T_D4;
		code = type & T_D2 ? 2 : 4;
	}
	return (code);
}

int			get_ocp(unsigned char ocp, t_instr_type *type, t_instr_list *instr,
		int nbr)
{
	int				i;
	unsigned int	ret;

	i = 4;
	instr->mem_size += 1;
	while (i > type->par_nbr)
	{
		ocp >>= 2;
		i--;
	}
	i = type->par_nbr - 1;
	while (i >= 0)
	{
		if (!(ret = parse_param(type->par_type[i], ocp, &instr->par[i])))
			return (error_msg_instr(3, nbr));
		instr->mem_size += ret;
		instr->par[i].size = ret;
		ocp >>= 2;
		i--;
	}
	if (ocp)
		return (error_msg_instr(3, nbr));
	return (1);
}

int			fill_mem_no_ocp(t_instr_list *instr, t_instr_type *type)
{
	if (type->par_type[0] == T_D2)
		instr->mem_size += 2;
	if (type->par_type[0] == T_D4)
		instr->mem_size += 4;
	instr->par[0].size = instr->mem_size;
	instr->par[0].type = instr->mem_size == 2 ? T_D2 : T_D4;
	return (1);
}

int			convert_to_value(int size, char *bin_instr)
{
	unsigned int		value;
	int					i;

	i = 0;
	value = 0;
	while (--size >= 0)
	{
		value <<= 8;
		value |= (unsigned char)bin_instr[i];
		i++;
	}
	return (value);
}
