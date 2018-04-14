/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:36:54 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/07 01:56:08 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void		get_label_value(t_expr *expr)
{
	int i;

	while (expr)
	{
		i = 0;
		if (expr->type == INSTR)
		{
			while (i < expr->instr->par_nbr)
			{
				if (expr->instr->par[i].type & T_LB)
				{
					expr->instr->par[i].value = *expr->instr->par[i].label -
						expr->addr + expr->instr->par[i].add_val;
				}
				i++;
			}
		}
		expr = expr->next;
	}
}

int			handle_duplicate(t_expr *expr, t_expr *list)
{
	if (!expr || !expr->expr)
		return (0);
	while (list)
	{
		if (list->type & LABEL && expr->expr && list && list->expr &&
				ft_strstr(expr->expr, list->expr))
		{
			expr->addr = list->addr;
			return (0);
		}
		list = list->next;
	}
	return (1);
}

int			test_label(t_expr *expr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!ft_strchr(expr->expr, LABEL_CHAR))
		return (0);
	while (expr->expr[i] && expr->expr[i] != LABEL_CHAR)
	{
		while (LABEL_CHARS[j])
		{
			if (LABEL_CHARS[j] == expr->expr[i])
				break ;
			j++;
		}
		if (!LABEL_CHARS[j])
			return (0);
		j = 0;
		i++;
	}
	if (!expr->expr[i] || (expr->expr[i] == LABEL_CHAR && expr->expr[i + 1]))
		return (0);
	expr->type |= LABEL;
	return (1);
}

static int	cmp_label_to_expr(t_expr *current, char *cmp)
{
	char *tmp;

	tmp = cmp;
	tmp++;
	while (*tmp && *tmp != SEPARATOR_CHAR && *tmp != '-' && *tmp != '+')
		tmp++;
	if (!ft_strnequ(current->expr, cmp + 1, tmp - cmp - 1))
		return (0);
	else
		return (1);
}

char		*get_label_addr(t_expr *list, char *tmp, t_par *par)
{
	while (list)
	{
		if (ft_strchr(list->expr, '\n'))
			*ft_strchr(list->expr, '\n') = '\0';
		test_label(list);
		if (list->type & LABEL && cmp_label_to_expr(list, tmp))
			break ;
		list = list->next;
	}
	if (!list)
		return (0);
	else if (list->type & LABEL)
	{
		par->type |= T_LB;
		par->label = &list->addr;
		if (ft_strchr(tmp, '+') || ft_strchr(tmp, '-'))
			par->add_val = get_op_value(tmp);
	}
	while (*tmp && *tmp != SEPARATOR_CHAR)
		tmp++;
	if (*tmp)
		tmp++;
	return (tmp);
}
