/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_asm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:29:40 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 21:59:16 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*jump_comment(char *tmp)
{
	while (*tmp != '\n' && tmp)
		tmp++;
	return (tmp);
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

int			unbr_len(long nb)
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

int			get_name_len(char *name)
{
	int i;

	i = 0;
	while (name[i] && name[i] != DIRECT_CHAR && name[i] != LABEL_CHAR &&
			name[i] != SEPARATOR_CHAR && name[i] != REG_CHAR &&
			!ft_isdigit(name[i]) && name[i] != '-' && name[i] != ' ' &&
			name[i] != '\t' && name[i] != '\n')
		i++;
	return (i);
}
