/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:03:52 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/01 18:04:27 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static char		*jump_label(char *tmp)
{
	tmp++;
	while (*tmp && ft_strchr(LABEL_CHARS, *tmp))
		tmp++;
	if (*tmp && *tmp != SEPARATOR_CHAR)
		return (0);
	if (*tmp && *tmp == SEPARATOR_CHAR)
		tmp++;
	return (tmp);
}

static int		test_params(char *tmp, int i)
{
	if (*tmp == REG_CHAR || *tmp == DIRECT_CHAR)
		tmp++;
	if (*tmp == LABEL_CHAR)
	{
		if (!(tmp = jump_label(tmp)))
			return (error_instr(8, 0, NULL));
		if (!*tmp)
			return (i);
		else
			return (test_params(tmp, i + 1));
	}
	while (*tmp && (ft_isdigit(*tmp) || *tmp == '-'))
		tmp++;
	if (*tmp && *tmp != SEPARATOR_CHAR && *tmp != '-')
		return (error_instr(6, 0, tmp));
	else if (*tmp && *tmp == SEPARATOR_CHAR)
	{
		tmp++;
		if (*tmp)
			i = test_params(tmp, i + 1);
		else
			return (error_instr(7, 0, NULL));
	}
	return (i);
}

int				test_instr(t_expr *expr, t_instr_type *type)
{
	char *tmp;

	if (!ft_strnequ(expr->expr, type->name, ft_strlen(type->name)))
		return (0);
	tmp = expr->expr;
	tmp += ft_strlen(type->name);
	if (!ft_isdigit(*tmp) && *tmp != LABEL_CHAR && *tmp != REG_CHAR && *tmp !=
			DIRECT_CHAR && *tmp != '-')
		return (error_instr(2, expr->line, expr->expr));
	if (occur_count(tmp, SEPARATOR_CHAR) != type->par_nbr - 1)
		return (error_instr(3, expr->line, expr->expr));
	if (test_params(tmp, 0) + 1 != type->par_nbr)
		return (error_instr(4, expr->line, expr->expr));
	expr->type |= INSTR;
	return (1);
}
