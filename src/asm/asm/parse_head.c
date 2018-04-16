/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:30:22 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 21:52:10 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			calc_size(t_expr *expr)
{
	int			i;
	t_instr		*instr;
	int			op;

	i = 0;
	op = 0;
	instr = expr->instr;
	instr->mem_size = 1;
	if (instr->ocp && (op = 1))
		instr->mem_size++;
	instr->ocp = 0;
	while (i < instr->par_nbr)
	{
		if (instr->par[i].type & T_RG && op)
			instr->ocp |= MT_RG;
		if (instr->par[i].type & T_ID && op)
			instr->ocp |= MT_ID;
		if ((instr->par[i].type & T_D4 || instr->par[i].type & T_D2) && op)
			instr->ocp |= MT_DT;
		instr->ocp <<= 2;
		instr->mem_size += instr->par[i].size;
		i++;
	}
	while (i++ < 3)
		instr->ocp <<= 2;
}

static long		check_name(char *tmp)
{
	char *tmp2;

	while (*tmp && *tmp != '.' && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (!ft_strnequ(NAME_CMD_STRING, tmp, ft_strlen(NAME_CMD_STRING)))
		return (error_msg_asm(1, 0));
	tmp += ft_strlen(NAME_CMD_STRING);
	while (*tmp && *tmp != '"' && *tmp != '\n' && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (!*tmp)
		return (error_msg_asm(4, 0));
	if (*tmp == '\n')
		return (error_msg_asm(2, 0));
	else if (*tmp != '"')
		return (error_msg_asm(3, *tmp));
	if (tmp[1])
		tmp2 = tmp + 1;
	tmp++;
	while (*tmp && *tmp != '"' && tmp - tmp2 < PROG_NAME_LENGTH)
		tmp++;
	if (!*tmp)
		return (error_msg_asm(4, 0));
	else if (*tmp != '"')
		return (error_msg_asm(5, 0));
	return ((long)tmp + 1);
}

long			parse_name(char *tmp)
{
	while (tmp && *tmp && (*tmp == COMMENT_CHAR || *tmp == ASM_COMMENT))
	{
		tmp = jump_comment(tmp);
		if (*(tmp + 1))
			tmp++;
	}
	if (*tmp && *(tmp + 1) && *tmp != '.')
		tmp++;
	if (!ft_strchr(tmp, '.'))
		return (0);
	return (check_name(tmp));
}

long			parse_comment(char *tmp)
{
	char *tmp2;

	while (*tmp && *tmp != '.' && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (!ft_strnequ(COMMENT_CMD_STRING, tmp, ft_strlen(COMMENT_CMD_STRING)))
		return (error_msg_asm(8, 0));
	tmp += ft_strlen(COMMENT_CMD_STRING);
	while (*tmp && *tmp != '"' && *tmp != '\n' && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (!*tmp)
		return (error_msg_asm(11, 0));
	if (*tmp == '\n')
		return (error_msg_asm(9, 0));
	else if (*tmp != '"')
		return (error_msg_asm(3, *tmp));
	if (tmp[1])
		tmp2 = tmp + 1;
	tmp++;
	while (*tmp && *tmp != '"' && tmp - tmp2 < COMMENT_LENGTH)
		tmp++;
	if (!*tmp)
		return (error_msg_asm(11, 0));
	else if (*tmp != '"')
		return (error_msg_asm(12, 0));
	return ((long)tmp + 1);
}
