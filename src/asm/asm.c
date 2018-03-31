/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:47:03 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/31 17:57:58 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		get_name_len(char *name)
{
	int i;

	i = 0;
	while (name[i] != DIRECT_CHAR && name[i] != LABEL_CHAR && name[i] !=
			SEPARATOR_CHAR && name[i] != REG_CHAR && !ft_isdigit(name[i]) && name[i] != '-')
		i++;
	return (i);
}

static t_instr_type		get_instr_type(char *name)
{
	int i;
	static t_instr_type	defs[17] = {
		{ NULL , 0, 0, 0, 0},
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

	i = 1;
	while (i < 17 && !ft_strnequ(name, defs[i].name, get_name_len(name)))
		i++;
	return (i == 17 ? defs[0] : defs[i]);
}

long parse_name(char *tmp)
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

long parse_comment(char *tmp)
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

int			handle_duplicate(t_expr *expr, t_expr *list)
{
	if (!expr || !expr->expr)
		return (0);
	while (list)
	{
		if (list->type & LABEL && expr->expr && list && list->expr && ft_strstr(expr->expr, list->expr))
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

char		*jump_label(char *tmp)
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

int			test_params(char *tmp, int i)
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
			return(test_params(tmp, i + 1));
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

int			test_instr(t_expr *expr, t_instr_type *type)
{
	char *tmp;

	if (!ft_strnequ(expr->expr, type->name, ft_strlen(type->name)))
		return (0);
	tmp = expr->expr;
	tmp += ft_strlen(type->name);
	if (!ft_isdigit(*tmp) && *tmp != LABEL_CHAR && *tmp != REG_CHAR && *tmp != DIRECT_CHAR && *tmp != '-')
		return (error_instr(2, expr->line, expr->expr));
	if (occur_count(tmp, SEPARATOR_CHAR) != type->par_nbr - 1)
		return (error_instr(3, expr->line, expr->expr));
	if (test_params(tmp, 0) + 1 != type->par_nbr)
		return (error_instr(4, expr->line, expr->expr));
	expr->type |= INSTR;
	return (1);
}

int		unbr_len(long nb)
{
	int		i;

	i = 0;
	if (nb < 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int			cmp_label_to_expr(t_expr *current, char *cmp)
{
	char *tmp;

	tmp = cmp;
	tmp++;
	while (*tmp && *tmp != SEPARATOR_CHAR)
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
	}
	while (*tmp && *tmp != SEPARATOR_CHAR)
		tmp++;
	if (*tmp)
		tmp++;
	return (tmp);
}

int			get_next_instr(char **src, t_par *par, t_expr *list, t_expr *expr)
{
	char *tmp;
	int value;

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
	{
		*src = get_label_addr(list, tmp, par);
		return (*src ? 1 : error_param(2, expr, 0));
	}
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

void		calc_size(t_expr *expr)
{
	int i;
	t_instr *instr;
	int op;

	i = 0;
	op = 0;
	instr = expr->instr;
	instr->mem_size = 1;
	if (instr->ocp)
	{
		op = 1;
		instr->mem_size++;
	}
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

int			check_instr(t_expr *expr, t_expr *list, t_instr_type *type)
{
	char *tmp;
	int i;
	t_instr *instr;

	instr = expr->instr;
	i = -1;
	tmp = expr->expr;
	tmp += ft_strlen(type->name);
	while (*tmp)
	{
		i++;
		if ((ft_isdigit(*tmp) || *tmp == LABEL_CHAR || *tmp == '-') && type->par_type[i] & T_ID)
			instr->par[i].type |= T_ID;
		else if (*tmp == DIRECT_CHAR && (type->par_type[i] & T_D4))
			instr->par[i].type |= T_D4;
		else if (*tmp == DIRECT_CHAR && (type->par_type[i] & T_D2))
			instr->par[i].type |= T_D2;
		else if (*tmp == 'r' && (type->par_type[i] & T_RG))
			instr->par[i].type |= T_RG;
		else
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

int			parse_expr(t_expr *current, t_expr **list)
{
	static int addr = 0;
	t_instr_type type;

	type = get_instr_type(current->expr);
	if (!test_label(current) && type.name)
	{
		if (!test_instr(current, &type))
			return (0);
		if (!(current->instr = (t_instr*)ft_memalloc(sizeof(t_instr))))
			exit(1);
		if (!(check_instr(current, *list, &type)))
			return (0);
		current->instr->addr = addr;
		current->addr = addr;
		addr += current->instr->mem_size;
		return (1);
	}
	else if (test_label(current))
	{
		current->addr = addr;
		handle_duplicate(current, *list);
	}
	else
		return (error_instr(5, current->line, current->expr));
	return (1);
}

char		*jump_multi_nl(char *src, int *lines)
{
	while (*src && *(src + 1) && *src == '\n' && *(src + 1) == '\n')
	{
		src++;
		lines[0]++;
	}
	return (src);
}

char		*get_expr(t_expr **list, char *champ, char *tmp, int *lines)
{
	t_expr *expr;

	expr = *list;
	expr->expr = champ;
	expr->line = (*lines)++;
	while (*tmp)
	{
		if (*tmp == COMMENT_CHAR)
			tmp = ft_strchr(champ, '\n');
		if (*tmp == '\n')
			tmp = jump_multi_nl(tmp, lines);
		if (*tmp != ' ' && *tmp != '\t')
			*champ++ = *tmp;
		if (*tmp == '\n' && *(tmp + 1))
		{
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

char		*trim_champ(char *champ, t_expr **list, int *lines)
{
	int		size;
	char	*tmp;
	int		word;

	tmp = champ;
	size = 0;
	while (*champ)
	{
		if (*champ == COMMENT_CHAR)
			champ = ft_strchr(champ, '\n');
		if (*champ == '\n' || size == 0)
			word = 0;
		if (*champ != ' ' && *champ != '\t' && word++ >= 0)
			size++;
		if (word && champ != tmp && *champ == LABEL_CHAR && (*(champ - 1)
					== ' ' || *(champ - 1) == '\t') && (!*(champ + 1) ||
					(*(champ + 1) && (*(champ + 1) == ' ' ||
									*(champ + 1) == '\t'))))
			return (0);
		if (*champ == '\n')
			champ = jump_multi_nl(champ, lines);
		champ++;
	}
	if (!(*list = (t_expr*)ft_memalloc(sizeof(t_expr))))
		exit(1);
	return (get_expr(list, ft_strnew(size), tmp, lines));
}

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
					expr->instr->par[i].value = *expr->instr->par[i].label -
						expr->addr;
				i++;
			}
		}
		expr = expr->next;
	}
}

int			parse_instr(char *champ, int lines, char *src, t_expr **list)
{
	t_expr *expr;
	t_expr *begin;
	int		cse;

	champ = trim_champ(champ, &expr, &lines);
	begin = expr;
	*list = expr;
	if (!champ)
		return ((int)error_instr(1, 0, NULL));
	while (expr)
	{
		if (ft_strchr(expr->expr, '\n'))
			*ft_strchr(expr->expr, '\n') = '\0';
		if (!parse_expr(expr, &begin))
			return (0);
		expr = expr->next;
	}
	expr = begin;
	get_label_value(expr);
	return (1);
}

int			count_lines(char *champ, char *tmp)
{
	int lines;

	lines = 1;
	while (*champ && champ != tmp)
	{
		if (*champ == '\n')
			lines++;
		champ++;
	}
	return (lines);
}

int			parse_champ(char *champ, t_expr **expr)
{
	char *tmp;
	t_expr *list;

	tmp = (char*)parse_name(champ);
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp != '\n')
		return (error_msg_asm(6, *tmp));
	if (*tmp == '.' && ft_strnequ(COMMENT_CMD_STRING, tmp, ft_strlen(COMMENT_CMD_STRING)))
		return (error_msg_asm(7, 0));
	tmp++;
	tmp = (char*)parse_comment(tmp);
	if (!tmp)
		return (0);
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp != '\n')
		return (error_msg_asm(6, *tmp));
	while (*tmp && (*tmp == ' ' || *tmp == '\t' || *tmp == '\n'))
		tmp++;
	if (!parse_instr(tmp, count_lines(champ, tmp), champ, &list))
		return (0);
	*expr = list;
	return (1);
}

int			read_champ(char *champ_path, char **src)
{
	int fd;
	char *mod;
	int ret;
	char *tmp;
	char buf[14];

	mod = ft_strnew(0);
	if ((fd = open(champ_path, O_RDONLY)) <= 0)
		return (error_msg(1));
	while ((ret = read(fd, buf, 13)) > 0)
	{
		tmp = mod;
		buf[ret] = '\0';
		mod = ft_strjoin(mod ,buf);
		if (tmp)
			free(tmp);
	}
	if (ret < 0)
		return (error_msg(3));
	*src = mod;
	return (1);
}


int convert_champ(char *champ_path)
{
	char *raw;
	char *mod;
	int fd;
	t_expr *expr_list;

	if (!read_champ(champ_path, &raw))
		return (0);
	if (!parse_champ(raw, &expr_list))
		return (0);
	*ft_strchr(champ_path, '.') = '\0';
	mod = ft_strnew(ft_strlen(champ_path + 4));
	mod = ft_strcpy(mod, champ_path);
	mod = ft_strcat(mod, ".cod");
	if ((fd = open(mod, O_RDWR | O_CREAT, 0644)) < 0)
		return (0);
	write_champ(expr_list, raw, fd);
	return(1);
}
