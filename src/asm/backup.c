/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 21:47:03 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/28 20:55:22 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

static t_instr_type		get_instr_type(char *name, int size)
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
		{ "zjmp", I_ZJMP, 1, { T_D4 }, 0 },
		{ "ldi", I_LDI, 3, { T_RG | T_ID | T_D4, T_RG | T_D4, T_RG }, F_OCP },
		{ "sti", I_STI, 3, { T_RG, T_RG | T_ID | T_D4, T_RG | T_D4 }, F_OCP },
		{ "fork", I_FORK, 1, { T_D4 }, 0 },
		{ "lld", I_LLD, 2, { T_ID | T_D4, T_RG }, F_OCP },
		{ "lldi", I_LLDI, 3, { T_RG | T_ID | T_D4, T_ID | T_D4, T_RG }, F_OCP },
		{ "fork", I_LFORK, 1, { T_D4 }, 0 },
		{ "aff", I_AFF, 1, { T_RG }, F_OCP} };

	i = 1;
	while (i < 16 && !ft_strnequ(defs[i].name, name, size))
		i++;
	return (i == 16 ? defs[0] : defs[i]);
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



t_label		*push_front(t_label *list)
{
	t_label *new;
	if (!(new = (t_label*)ft_memalloc(sizeof(t_label))))
		exit(1);
	new->next = list;
	return (new);
}

int			check_dup(char *champ, int size, t_label *list)
{
	while (list)
	{
		if (ft_strnequ(list->name, champ, size))
			return (0);
		list = list->next;
	}
	return (1);
}

int			parse_label(char *champ, t_label **list, t_addr *addr)
{
	char *tmp;

	tmp = champ;
	while (*champ && *champ != ' ' && *champ != '\t' && *champ != LABEL_CHAR)
		champ++;
	if (*champ != LABEL_CHAR)
		return (0);
	if (!*list)
	{
		if (!(*list = (t_label*)ft_memalloc(sizeof(t_label))))
			exit(1);
	}
	else if (check_dup(tmp, champ - tmp, *list))
	{
		*list = push_front(*list);
		if (!((*list)->name = (char*)ft_memalloc(sizeof(char) * (champ - tmp + 1))))
			exit(1);
	}
	else
		return (0);
	(*list)->name = ft_strncpy((*list)->name, champ, champ - tmp);
	(*list)->addr = *addr;
	return (champ - tmp);
}

char		*get_next_param(char *champ)
{
	char *tmp;

	tmp = champ;
	if (*champ == '\n')
		return (0);
	while (*champ && (*champ == ' ' || *champ == '\t'))
		champ++;
	if (*champ == '\n')
		return (0);
	if (!ft_isdigit(*tmp) && *tmp != DIRECT_CHAR && *tmp != 'r' && *tmp != LABEL_CHAR)
		return (0);
	return (champ);
}

int			parse_next_param(char *champ, t_instr_type *type, int nbr_param)
{
	char *tmp;

	tmp = champ;

	if (*champ == LABEL_CHAR)
		champ++;
	if (*champ == 'r' && !(type->par_type[nbr_param] & T_RG))
		return (0);
	if (*champ == DIRECT_CHAR && !(type->par_type[nbr_param] & T_D4))
		return (0);
	if ((ft_isdigit(*champ) || ft_isalpha(*champ)) && !(type->par_type[nbr_param] & T_ID))
		return (0);
	while (*champ && *champ != ' ' && *champ != '\t' && *champ != '\n')
		champ++;
	while (*champ && (*champ == ' ' || *champ == '\t'))
		champ++;
	if ();
	return (1);
}

char *parse_next_instr(char *champ, t_label **list, t_addr *addr)
{
	char *tmp;
	t_instr_type type;
	int ret;
	int ret_ptr;

	tmp = champ;
	ret = 0;
	ft_memset(&type, 0, sizeof(t_instr_type));
	if ((ret = parse_label(champ ,list, addr)))
		return (tmp + ret);
	while (*champ && *champ != ' ' && *champ != '\t' && *champ != '\n')
		champ++;
	get_instr_type(tmp, champ - tmp);
	if (!type.name)
		return (NULL);
	while (get_next_param(champ))
	{
		champ = get_next_param(champ);
		if (!champ || (ret_ptr = parse_next_param(get_next_param(champ), &type, ret)) >= 0)
			break ;
		champ += ret_ptr;
		ret++;
	}
	if (ret == -1)
		return (0);
	return (ret == type.par_nbr ? champ : NULL);
}


int			parse_instr(char *champ, int lines)
{
	char	*tmp;
	t_addr	addr;
	t_label *label;

	label = NULL;
	addr = 0;
	while (champ && *champ)
	{
		while (*champ && (*champ == ' ' || *champ == '\t' || *champ == '\n'))
		{
			if (*champ == '\n')
				lines++;
			champ++;
		}
		champ = parse_next_instr(champ, &label, &addr);
		if (!champ)
			break ;
	}
	if (!champ)
		return (0);
	return (1);
}

int			count_lines(char *champ, char *tmp)
{
	int lines;

	lines = 0;
	while (*champ && champ != tmp)
	{
		if (*champ == '\n')
			lines++;
		champ++;
	}
	return (lines);
}

int			parse_champ(char *champ)
{
	char *tmp;

	tmp = (char*)parse_name(champ);
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp != '\n')
		return (error_msg_asm(6, *tmp));
	if (*tmp == '.' && ft_strnequ(COMMENT_CMD_STRING, tmp, ft_strlen(COMMENT_CMD_STRING)))
		return (error_msg_asm(7, 0));
	tmp++;
	tmp = (char*)parse_comment(tmp);
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp != '\n')
		return (error_msg_asm(6, *tmp));
	while (*tmp && (*tmp == ' ' || *tmp == '\t' || *tmp == '\n'))
		tmp++;
	parse_instr(tmp, count_lines(champ, tmp));
	return (1);
}

int			convert_champ(char *champ_path)
{
	int fd;
	char *mod;
	int ret;
	char *tmp;
	char buf[14];

	mod = ft_strnew(0);
	if ((fd = open(champ_path, O_RDONLY)) <= 0)
		return (error_msg(1));
	//	*ft_strrchr(champ_path, '.') = '\0';
	//	mod = ft_strjoin(champ_path, ".cor");
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
	parse_champ(mod);
	return (1);
}
