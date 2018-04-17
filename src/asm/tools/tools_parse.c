/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 01:51:58 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/17 01:08:33 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static t_expr	*push_new_elem(int size, char **tmp, t_expr *origin, int jump)
{
	t_expr	*expr;
	char	*new;

	if (!(expr = (t_expr*)ft_memalloc(sizeof(t_expr))))
		exit(1);
	if (!(new = ft_strnew(size)))
		exit(1);
	expr->expr = ft_strncpy(new, *tmp + jump, size - jump);
	expr->alloced = 100;
	expr->type = LABEL;
	if (!jump)
		expr->next = origin;
	return (expr);
}

static int		trim_param(char **instr)
{
	char *tmp;

	tmp = *instr;
	jump_white_spaces(&tmp);
	if (*tmp == '\n' || !*tmp || *tmp == COMMENT_CHAR)
		return (0);
	if (*tmp == SEPARATOR_CHAR)
		tmp++;
	jump_white_spaces(&tmp);
	if (*tmp && *tmp != DIRECT_CHAR && *tmp != LABEL_CHAR && !ft_isdigit(*tmp)
			&& *tmp != REG_CHAR && *tmp != '-')
		return (0);
	if (*tmp == DIRECT_CHAR || *tmp == REG_CHAR)
		tmp++;
	if (*tmp == LABEL_CHAR)
	{
		while (*tmp && *tmp != '\n' && *tmp != S_C && *tmp != COMMENT_CHAR)
			tmp++;
		*instr = tmp;
		return (1);
	}
	while (*tmp && (ft_isdigit(*tmp) || *tmp == '-'))
		tmp++;
	*instr = tmp;
	return (1);
}

static int		is_instr(char *instr)
{
	int				i;
	t_instr_type	type;

	i = 0;
	if (ft_strlen(instr) == 1)
		return (0);
	instr++;
	if (*instr == '\n' || *instr == COMMENT_CHAR)
		return (1);
	while (*instr && (*instr == ' ' || *instr == '\t'))
		instr++;
	type = get_instr_type(instr);
	if (!type.name)
		return (0);
	if (noccur_count(instr, SEPARATOR_CHAR, '\n') != type.par_nbr - 1)
		return (0);
	if (ft_strlen(instr) > ft_strlen(type.name))
		instr += ft_strlen(type.name);
	while (trim_param(&instr))
		i++;
	if (i != type.par_nbr)
		return (0);
	return (1);
}

void			handle_label_instr(t_expr **exp, char **tmp, int jump)
{
	char *tp2;

	tp2 = *tmp + jump;
	while (*tp2 && (*tp2 == ' ' || *tp2 == '\t'))
		tp2++;
	while (*tp2 && *tp2 != '\n' && *tp2 != LABEL_CHAR && *tp2 != ' ' &&
			*tp2 != '\t')
		tp2++;
	if (!*tp2 || *tp2 == '\n' || *tp2 == ' ' || *tp2 == '\t')
		return ;
	else if (*tp2 == LABEL_CHAR && tp2 != *tmp && is_instr(tp2))
	{
		tp2++;
		if (*tp2 && *tp2 != '\n')
		{
			if (jump)
			{
				(*exp)->next = push_new_elem(tp2 - *tmp, tmp, NULL, jump);
				*exp = (*exp)->next;
			}
			else
				*exp = push_new_elem(tp2 - *tmp, tmp, *exp, jump);
			*tmp = tp2;
		}
	}
}

long			get_op_value(char *tmp)
{
	while (*tmp && *tmp != '-' && *tmp != '+' && *tmp != SEPARATOR_CHAR)
		tmp++;
	return (ft_long_atoi(tmp));
}
