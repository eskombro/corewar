/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:32:08 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/07 01:45:52 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int		get_next_instr(char **src, t_par *par, t_expr *list,
		t_expr *expr)
{
	char *tmp;

	tmp = *src;
	if (par->type & T_RG)
		par->size = 1;
	else if ((par->type & T_ID) || (par->type & T_D2))
		par->size = 2;
	else if (par->type & T_D4)
		par->size = 4;
	if (*tmp && (*tmp == REG_CHAR || *tmp == DIRECT_CHAR))
		tmp++;
	if (*tmp == LABEL_CHAR)
		return ((*src = get_label_addr(list, tmp, par)) ? 1 : ERR(2, expr, 0));
	if (!(par->value = ft_long_atoi(tmp)) && *tmp != '0')
		return (error_param(3, expr, 0));
	if (par->type & T_RG && (par->value <= 0 || par->value > REG_NUMBER))
		return (error_param(4, expr, 0));
	while (*tmp && *tmp != SEPARATOR_CHAR)
		tmp++;
	if (*tmp == SEPARATOR_CHAR)
		tmp++;
	*src = tmp;
	return (1);
}

static int		check_type(char *tmp, t_instr_type *type, int i, t_instr *instr)
{
	if ((ft_isdigit(*tmp) || *tmp == LABEL_CHAR || *tmp == '-') &&
			type->par_type[i] & T_ID)
		instr->par[i].type |= T_ID;
	else if (*tmp == DIRECT_CHAR && (type->par_type[i] & T_D4))
		instr->par[i].type |= T_D4;
	else if (*tmp == DIRECT_CHAR && (type->par_type[i] & T_D2))
		instr->par[i].type |= T_D2;
	else if (*tmp == 'r' && (type->par_type[i] & T_RG))
		instr->par[i].type |= T_RG;
	else
		return (0);
	return (1);
}

int				check_instr(t_expr *expr, t_expr *list, t_instr_type *type)
{
	char	*tmp;
	int		i;
	t_instr	*instr;

	instr = expr->instr;
	i = -1;
	tmp = expr->expr;
	tmp += ft_strlen(type->name);
	while (*tmp)
	{
		i++;
		if (!check_type(tmp, type, i, instr))
			return (error_param(1, expr, i));
		instr->ocp = type->flags;
		instr->op = type->opcode;
		instr->par_nbr = type->par_nbr;
		if (!(get_next_instr(&tmp, &instr->par[i], list, expr)))
			return (0);
	}
	calc_size(expr);
	return (1);
}
