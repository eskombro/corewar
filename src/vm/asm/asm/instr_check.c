/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:46:18 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 21:58:32 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*get_expr(t_expr **list, char *champ, char *tmp, int *lines)
{
	t_expr *expr;

	expr = *list;
	expr->expr = champ;
	handle_label_instr(list, &tmp, 0);
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
			handle_label_instr(&expr, &tmp, 1);
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
	if (word && champ != tmp && *champ == LABEL_CHAR && (*(champ - 1) == ' ' ||
				*(champ - 1) == '\t') && (!*(champ + 1) ||
				*(champ + 1) == '\n'))
		return (0);
	if (word && champ != tmp && *champ == LABEL_CHAR && (*(champ - 1) == ' ' ||
				*(champ - 1) == '\t') && *(champ + 1) && (*(champ + 1) == ' '
				|| *(champ + 1) == '\t'))
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
	*list = champ ? expr : NULL;
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
