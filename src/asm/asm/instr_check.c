/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:46:18 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/07 01:17:49 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

t_expr			*push_new_elem(int size, char **tmp, t_expr *origin, int jump)
{
	t_expr *expr;
	if (!(expr = (t_expr*)ft_memalloc(sizeof(t_expr))))
		exit(1);
	expr->expr = ft_strncpy(ft_strnew(size), *tmp + jump, size - jump);
	expr->type = LABEL;
	if (!jump)
		expr->next = origin;
	return (expr);
}

int				trim_param(char **instr)
{
	char *tmp;

	tmp = *instr;
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp == '\n' || !*tmp || *tmp == COMMENT_CHAR)
		return (0);
	if (*tmp == SEPARATOR_CHAR)
		tmp++;
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp && *tmp != DIRECT_CHAR && *tmp != LABEL_CHAR && !ft_isdigit(*tmp)
			&& *tmp != REG_CHAR && *tmp != '-')
		return (0);
	if (*tmp == DIRECT_CHAR || *tmp == REG_CHAR)
		tmp++;
	if (*tmp == LABEL_CHAR)
	{
		while (*tmp && *tmp != '\n' && *tmp != SEPARATOR_CHAR && *tmp != COMMENT_CHAR)
			tmp++;
		*instr = tmp;
		return (1);
	}
	while (*tmp && (ft_isdigit(*tmp) || *tmp == '-'))
			tmp++;
	*instr = tmp;
	return (1);
}

int				is_instr(char *instr)
{
	int i;
	t_instr_type type;

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

static void		handle_label_instr(t_expr **exp, char **tmp, int lines, int jump)
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

static char		*get_expr(t_expr **list, char *champ, char *tmp, int *lines)
{
	t_expr *expr;

	expr = *list;
	expr->expr = champ;
	expr->line = (*lines)++;
	handle_label_instr(list, &tmp, *lines, 0);
	while (*tmp)
	{
		if (*tmp && (*tmp == COMMENT_CHAR || *tmp == ASM_COMMENT))
			tmp = jump_comment(tmp);
		if (*tmp && *tmp == '\n')
			tmp = jump_multi_nl(tmp, lines);
		if (*tmp && *tmp != ' ' && *tmp != '\t')
			*champ++ = *tmp;
		if (*tmp && *tmp == '\n' && *(tmp + 1))
		{
			handle_label_instr(&expr, &tmp, *lines, 1);
			if (!(expr->next = (t_expr*)ft_memalloc(sizeof(t_expr))))
				exit(1);
			expr = expr->next;
			expr->line = (*lines)++;
			expr->expr = champ;
		}
		tmp++;
	}
	return (champ);
}

static int		check_for_label_err(char *champ, char *tmp, int word)
{
	if (word && champ != tmp && *champ == LABEL_CHAR && (*(champ - 1)
				== ' ' || *(champ - 1) == '\t') && (!*(champ + 1) ||
				(*(champ + 1) && (*(champ + 1) == ' ' ||
								  *(champ + 1) == '\t'))))
		return (0);
	return (1);
}

static char		*trim_champ(char *champ, t_expr **list, int *lines)
{
	int		size;
	char	*tmp;
	int		word;

	tmp = champ;
	size = 0;
	while (*champ)
	{
		if (*champ == COMMENT_CHAR || *champ == ASM_COMMENT)
			champ = jump_comment(champ);
		if (*champ == '\n' || size == 0)
			word = 0;
		if (*champ != ' ' && *champ != '\t' && word++ >= 0)
			size++;
		if (!check_for_label_err(champ, tmp, word))
			return (0);
		if (*champ == '\n')
			champ = jump_multi_nl(champ, lines);
		champ++;
	}
	if (!(*list = (t_expr*)ft_memalloc(sizeof(t_expr))))
		exit(1);
	return (get_expr(list, ft_strnew(size), tmp, lines));
}

int				parse_instr(char *champ, int lines, t_expr **list)
{
	t_expr *expr;
	t_expr *begin;
	t_addr addr;

	champ = trim_champ(champ, &expr, &lines);
	begin = expr;
	*list = expr;
	addr = 0;
	if (!champ)
		return ((int)error_instr(1, 0, NULL));
	while (expr)
	{
		if (ft_strchr(expr->expr, '\n'))
			*ft_strchr(expr->expr, '\n') = '\0';
		if (ft_strlen(expr->expr) && !ft_strequ(expr->expr, ".extend"))
			if (!parse_expr(expr, &begin, &addr))
				return (0);
		expr = expr->next;
	}
	expr = begin;
	get_label_value(expr);
	return (1);
}
