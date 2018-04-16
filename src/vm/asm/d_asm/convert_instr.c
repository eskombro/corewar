/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:24:46 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 22:01:13 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_instr_type	tget_instr_type(int opcode)
{
	static t_instr_type	defs[17] = {
{ NULL, 0, 0, { 0, 0, 0 }, 0},
{ "live", I_LIVE, 1, { T_D4 }, 0},
{ "ld", I_LD, 2, { T_ID | T_D4, T_RG }, F_OCP },
{ "st", I_ST, 2, { T_RG, T_RG | T_ID }, F_OCP },
{ "add", I_ADD, 3, { T_RG, T_RG, T_RG }, F_OCP },
{ "sub", I_SUB, 3, { T_RG, T_RG, T_RG }, F_OCP },
{ "and", I_AND, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, F_OCP },
{ "or", I_OR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, F_OCP },
{ "xor", I_XOR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, F_OCP },
{ "zjmp", I_ZJMP, 1, { T_D2 }, 0 },
{ "ldi", I_LDI, 3, { T_RG | T_ID | T_D2, T_RG | T_D2, T_RG }, F_OCP },
{ "sti", I_STI, 3, { T_RG, T_RG | T_ID | T_D2, T_RG | T_D2 }, F_OCP },
{ "fork", I_FORK, 1, { T_D2 }, 0 },
{ "lld", I_LLD, 2, { T_ID | T_D4, T_RG }, F_OCP },
{ "lldi", I_LLDI, 3, { T_RG | T_ID | T_D2, T_ID | T_D2, T_RG }, F_OCP },
{ "fork", I_LFORK, 1, { T_D2 }, 0 },
{ "aff", I_AFF, 1, { T_RG }, F_OCP} };

	if (opcode < 0 || opcode > 16)
		opcode = 0;
	return (defs[opcode]);
}

static int			get_instr(char *bin_instr, t_instr_list *instr, int nbr)
{
	t_instr_type type;

	type = tget_instr_type((unsigned char)*bin_instr);
	if (!type.opcode)
		return (error_msg_instr(1, nbr));
	if (!(bin_instr[1]) && type.flags)
		return (error_msg_instr(2, nbr));
	instr->mem_size += 1;
	if (type.flags)
	{
		if (!get_ocp(bin_instr[1], &type, instr, nbr))
			return (0);
	}
	else
		fill_mem_no_ocp(instr, &type);
	instr->name = type.name;
	instr->opcode = type.opcode;
	instr->par_nbr = type.par_nbr;
	return (1);
}

static void			fill_param(t_instr_list *instr, char *bin_instr)
{
	int				i;
	t_instr_type	type;

	type = tget_instr_type(instr->opcode);
	i = type.par_nbr - 1;
	bin_instr++;
	if (type.flags)
		bin_instr++;
	else
		instr->par[0].size--;
	while (i >= 0)
	{
		instr->par[type.par_nbr - 1 - i].value =
			convert_to_value(instr->par[type.par_nbr - 1 - i].size, bin_instr);
		if (instr->par[type.par_nbr - 1 - i].type & T_D2 ||
				instr->par[type.par_nbr - 1 - i].type & T_ID)
			instr->par[type.par_nbr - 1 - i].value =
				(short)instr->par[type.par_nbr - 1 - i].value;
		bin_instr += instr->par[type.par_nbr - 1 - i].size;
		i--;
	}
}

static int			fill_instr_list(t_bin_champ *champ, t_instr_list *instr)
{
	int				i;
	int				j;

	i = 0;
	j = 1;
	while (i < champ->size)
	{
		if (!get_instr(champ->champion + i, instr, j))
			return (0);
		fill_param(instr, champ->champion + i);
		instr->pos = i;
		i += instr->mem_size;
		j++;
		if (i < champ->size)
		{
			if (!(instr->next = ft_memalloc(sizeof(t_instr_list))))
				exit(1);
			instr = instr->next;
		}
	}
	return (1);
}

int					get_all_instr(t_bin_champ *champ, int fd)
{
	t_instr_list	*instr;
	t_instr_list	*tmp;

	if (!(instr = ft_memalloc(sizeof(t_instr_list))))
		exit(1);
	if (!fill_instr_list(champ, instr))
		return (0);
	get_labels(instr, champ);
	print_head(champ, fd);
	print_instr_list(instr, fd);
	while (instr)
	{
		tmp = instr;
		instr = instr->next;
		free(tmp);
	}
	return (0);
}
