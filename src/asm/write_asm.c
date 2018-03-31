/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 02:06:44 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/31 01:51:54 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char		*get_name(char **name, char *champ)
{
	char *tmp;

	tmp = champ;
	tmp = ft_strchr(tmp, '"');
	tmp++;
	*name = tmp;
	tmp = ft_strchr(tmp, '"');
	*tmp = '\0';
	tmp++;
	return (tmp);
}
char		*get_comment(char *comment)
{
	char *tmp;

	tmp = comment;
	tmp = ft_strchr(tmp, '"');
	tmp++;
	*ft_strchr(tmp, '"') = '\0';
	return (tmp);
}

void		write_mem_str(char *src, int size, int fd)
{
	int i;

	i = 0;
	while (src[i] && i < size)
	{
		write(fd, src + i, 1);
		i++;
	}
	src += i;
	while (i < size)
	{
		write(fd, src, 1);
		i++;
	}
}


void		write_int(unsigned int nb, int fd, int size)
{
	unsigned char byte[4];
	int i;

	i = 0;
	while (i < size)
	{
		byte[size - 1 - i] = 0;
		byte[size - 1 - i] |= nb;
		nb >>= 8;
		i++;
	}
	i = 0;
	while (i < size)
	{
		write(fd, byte + i, 1);
		i++;
	}
}
void		write_instr(t_instr *instr, int fd)
{
	int i;

	i = 0;
	write_int(instr->op, fd, 1);
	if (instr->ocp)
		write_int(instr->ocp, fd, 1);
	while (i < instr->par_nbr)
	{
		write_int(instr->par[i].value, fd, instr->par[i].size);
		i++;
	}
}

void		write_body(char *name, char *comment, int fd, int champ_size)
{
	write_int(COREWAR_EXEC_MAGIC, fd, 4);
	write_mem_str(name, PROG_NAME_LENGTH, fd);
	write_int(0, fd, 4);
	write_int(champ_size, fd , 4);
	write_mem_str(comment, COMMENT_LENGTH, fd);
	write_int(0 , fd, 4);
}

void		write_champ(t_expr *list, char *champ, int fd)
{
	char *name;
	char *comment;
	t_expr *begin;
	int		last;

	begin = list;
	while (list->next && list)
	{
		if (list->type == INSTR && list->instr)
			last = list->instr->mem_size;
		list = list->next;
	}
	if (list->type == INSTR)
		last = list->instr->mem_size;
	champ = get_name(&name, champ);
	comment = get_comment(champ);
	write_body(name, comment, fd, list->addr + last);
	while (begin)
	{
		if (begin->type == INSTR)
			write_instr(begin->instr, fd);
		begin = begin->next;
	}
}
