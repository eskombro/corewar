/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:46:18 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/02 04:34:41 by bacrozat         ###   ########.fr       */
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
	else if (*tp2 == LABEL_CHAR && tp2 != *tmp && *(tp2 - 1) != DIRECT_CHAR)
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
	if (!champ)
		return ((int)error_instr(1, 0, NULL));
	while (expr)
	{
		if (ft_strchr(expr->expr, '\n'))
			*ft_strchr(expr->expr, '\n') = '\0';
		if (ft_strlen(expr->expr))
			if (!parse_expr(expr, &begin, &addr))
				return (0);
		expr = expr->next;
	}
	expr = begin;
	get_label_value(expr);
	return (1);
}
