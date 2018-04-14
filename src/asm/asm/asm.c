/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:47:03 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/08 03:25:50 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

t_instr_type		get_instr_type(char *name)
{
	int						i;
	static	t_instr_type	defs[17] = {
{ NULL, 0, 0, {0, 0, 0}, 0},
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
{ "lfork", I_LFORK, 1, { T_D2 }, 0 },
{ "aff", I_AFF, 1, { T_RG }, F_OCP} };

	i = 1;
	while (i < 17 && !ft_strnequ(name, defs[i].name, get_name_len(name)))
		i++;
	return (i == 17 ? defs[0] : defs[i]);
}

int					parse_expr(t_expr *current, t_expr **list, t_addr *addr)
{
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
		current->instr->addr = *addr;
		current->addr = *addr;
		*addr += current->instr->mem_size;
		return (1);
	}
	else if (test_label(current))
	{
		current->addr = *addr;
		handle_duplicate(current, *list);
	}
	else
		return (error_instr(5, current->line, current->expr));
	return (1);
}

static int			parse_champ(char *champ, t_expr **expr)
{
	char	*tmp;
	t_expr	*list;

	if (!(tmp = (char*)parse_name(champ)))
		return (0);
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp != '\n')
		return (error_msg_asm(6, *tmp));
	if (*tmp == '.' && ft_strnequ(COMMENT_CMD_STRING, tmp,
				ft_strlen(COMMENT_CMD_STRING)))
		return (error_msg_asm(7, 0));
	tmp++;
	if (!(tmp = (char*)parse_comment(tmp)))
		return (0);
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp != '\n')
		return (error_msg_asm(6, *tmp));
	while (*tmp && (*tmp == ' ' || *tmp == '\t' || *tmp == '\n'))
		tmp++;
	if (!parse_instr(tmp, count_lines(champ, tmp), &list))
		return (0);
	*expr = list;
	return (1);
}

static int			read_champ(char *champ_path, char **src)
{
	int		fd;
	char	*mod;
	int		ret;
	char	*tmp;
	char	buf[14];

	mod = ft_strnew(0);
	if ((fd = open(champ_path, O_RDONLY)) <= 0)
		return (error_msg(1));
	while ((ret = read(fd, buf, 13)) > 0)
	{
		tmp = mod;
		buf[ret] = '\0';
		mod = ft_strjoin(mod, buf);
		if (tmp)
			free(tmp);
	}
	if (ret < 0)
		return (error_msg(3));
	*src = mod;
	return (1);
}

int					convert_champ(char *champ_path, int sig, char **src,
		t_expr **expr)
{
	char	*raw;
	char	*mod;
	int		fd;
	t_expr	*expr_list;

	if (!read_champ(champ_path, &raw))
		return (0);
	if (!parse_champ(raw, &expr_list))
		return (print_champ_path(ft_strrchr(champ_path, '/'), champ_path));
	if (!sig)
	{
		*ft_strchr(champ_path, '.') = '\0';
		mod = ft_strnew(ft_strlen(champ_path + 4));
		mod = ft_strcpy(mod, champ_path);
		mod = ft_strcat(mod, ".cor");
		if ((fd = open(mod, O_RDWR | O_CREAT, 0644)) < 0)
			return (0);
		write_champ_bin(expr_list, raw, fd);
		return (1);
	}
	*src = raw;
	*expr = expr_list;
	return (1);
}
