/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 22:24:46 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/26 18:42:27 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

static t_instr_type		get_instr_type(int opcode)
{
	//	ft_printf("Sent opcode == %d\n", opcode);
	static t_instr_type	defs[17] = {
		{ NULL,0, 0, { 0, 0, 0 }, 0},
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

int		parse_param(char type, char ocp, t_par *par)
{
	int code;

	code = 0;
	//	ft_printf("salut %x \n", ocp);
	if ((ocp & MT_ID) == MT_ID)
	{
		//		ft_printf("salut je suis un Indirect %.2x %.2x\n", type, type & T_ID);
		if (!(type & T_ID))
			return (code);
		par->type = T_ID;
		code = 2;
	}
	else if ((ocp & MT_RG) == MT_RG)
	{
		//		ft_printf("salut je suis un registre %x \n", type);
		if (!(type & T_RG))
			return (code);
		par->type = T_RG;
		code = 1;
	}
	else if ((ocp & MT_DT) == MT_DT)
	{
		//		ft_printf("salut je suis un direct %x \n", type);
		if (!(type & T_D2) && !(type & T_D4))
			return (code);
		par->type = (type & T_D2) ? T_D2 : T_D4;
		code = type & T_D2 ? 2 : 4;
		//		ft_printf("Je pense aue tu est un T_D%d\n",code);
	}
	//	if (!code)
	//	ft_printf("G PA TROUVE DE TYPE MDR\n");
	return (code);
}

int		get_ocp(unsigned char ocp, t_instr_type *type, t_instr_list *instr, int nbr)
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
		//		ft_printf("JE FOIRE PAS MDR ET JE RETOURNE %d \n", ret);
		instr->mem_size += ret;
		instr->par[i].size = ret;
		ocp >>= 2;
		i--;
	}
	if (ocp)
		return (error_msg_instr(3, nbr));
	return (1);
}
int		fill_mem_no_ocp(t_instr_list *instr, t_instr_type *type)
{
	if (type->par_type[0] == T_D2)
		instr->mem_size += 2;
	if (type->par_type[0] == T_D4)
		instr->mem_size += 4;
	instr->par[0].size = instr->mem_size;
	instr->par[0].type = instr->mem_size == 2 ? T_D2 : T_D4;
	return (1);
}

int		get_instr(char *bin_instr, t_instr_list *instr, int nbr)
{
	t_instr_type type;

	//	ft_printf("\n%.2x    %.2x\n", (unsigned char)*bin_instr, (unsigned char)bin_instr[1]);
	type = get_instr_type((unsigned char)*bin_instr);
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

int		convert_to_value(int size, char *bin_instr)
{
	unsigned int		value;
	int i;

	i = 0;
	value = 0;
	while (--size >= 0)
	{
		value <<= 8;
		value |= (unsigned char)bin_instr[i];
		//		ft_printf("%.2x \n", (unsigned char)bin_instr[i]);
		i++;
	}
	//	ft_printf("|%.2x|\n", value);
	return (value);
}

void	fill_param(t_instr_list *instr, char *bin_instr)
{
	int i;
	t_instr_type type;

	type = get_instr_type(instr->opcode);
	i = type.par_nbr - 1;
	bin_instr++;
	if (type.flags)
		bin_instr++;
	else
		instr->par[0].size--;
	//	ft_printf("\n%s :\n\n", instr->name);
	while (i >= 0)
	{
		instr->par[type.par_nbr - 1 - i].value =
			convert_to_value(instr->par[type.par_nbr - 1 - i].size, bin_instr);
		if (instr->par[type.par_nbr - 1 - i].type & T_D2 || instr->par[type.par_nbr - 1 - i].type & T_ID)
			instr->par[type.par_nbr - 1 - i].value = (short)instr->par[type.par_nbr - 1 - i].value;
		bin_instr += instr->par[type.par_nbr - 1 - i].size;
		i--;
	}
}

void	print_instr_list(t_instr_list *instr)
{
	t_par	tmp;
	int		i;

	while (instr)
	{
		if (instr->labels)
			ft_printf("\nlabel_%d:\n", instr->labels);
		ft_printf("\t%s\t\t\t\t",instr->name);
		if (ft_strlen(instr->name) < 4)
			ft_printf("\t");
		i = 0;
		while (i < instr->par_nbr)
		{
			if (i)
				ft_printf(", ");
			if ((instr->par[i].type & T_D2) || (instr->par[i].type & T_D4))
				ft_printf("%%");
			if (instr->par[i].type & T_RG)
				ft_printf("r");
			if (instr->par[i].type & T_LB)
				ft_printf(":label_%d", *instr->par[i].labeled);
			else
				ft_printf("%d", instr->par[i].value);
			i++;
		}
		instr = instr->next;
		ft_printf("\n");
	}
}

int		*check_list(t_instr_list *instr, int addr)
{
	static int	label = 0;
	int			ret;

	ret = 0;
//	ft_printf("%d\n", addr);
	while (instr)
	{
		if (instr->pos == addr)
		{
			if (instr->labels)
				ret = instr->labels;
			else
			{
				label++;
				instr->labels = label;
				ret = label;
			}
			break ;
		}
		instr = instr->next;
	}
	return (instr ? &instr->labels : 0);
}

int		check_labels(t_par par[3], int size, t_instr_list *instr, t_instr_list *current)
{
	int i;
	int *ret;

	i = 0;
	while (i < current->par_nbr)
	{
//		ft_printf("%d   %d   %d\n", par[i].value, current->pos, par[i].value + current->pos);
		if (par[i].value && par[i].value + current->pos < size && !(par[i].type & T_RG))
		{
//			ft_printf("%d   %d   %d\n", par[i].value, pos, par[i].value + pos);
			if ((ret = check_list(instr, par[i].value + current->pos)))
			{
				par[i].type |= T_LB;
				par[i].labeled = ret;
			}
		}
		i++;
	}
//	ft_printf("\nZZZZ\n");
	return (1);
}

void	get_labels(t_instr_list *instr, t_bin_champ *champ)
{
	t_instr_list	*begin;
	int				i;

	i = 1;
	begin = instr;
	while (instr)
	{
		check_labels(instr->par, champ->size, begin, instr);
		instr = instr->next;
	}
	while (begin)
	{
		if (begin->labels)
		{
			begin->labels = i;
			i++;
		}
		begin = begin->next;
	}
}

void print_head(t_bin_champ *bin)
{
	ft_printf("%s ", NAME_CMD_STRING);
	ft_printf("%c", 34);
	ft_printf("%s", bin->name);
	ft_printf("%c\n", 34);
	ft_printf("%s ", COMMENT_CMD_STRING);
	ft_printf("%c", 34);
	ft_printf("%s", bin->comment);
	ft_printf("%c\n", 34);
}

int		get_all_instr(t_bin_champ *champ)
{
	t_instr_list	*instr;
	t_instr_list	*begin;
	int				i;
	int				j;

	i = 0;
	j = 1;
	if (!(instr = ft_memalloc(sizeof(t_instr_list))))
		exit(1);
	begin = instr;
	//	while (i < champ->size)
	//	{
	//		ft_printf("%.2x ", (unsigned char)champ->champion[i]);
	//		if (!(i % 42) && i)
	//			ft_printf("\n");
	//		i++;
	//	}
	i = 0;
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
	get_labels(begin, champ);
	print_head(champ);
	print_instr_list(begin);
	return (0);
}
