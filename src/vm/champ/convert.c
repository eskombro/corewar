/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:42:52 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/15 21:42:40 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void				*free_champs(t_champ *champs)
{
	int i;

	i = 0;
	while (champs[i].name != NULL)
	{
		if (champs[i].champion)
			free(champs[i].champion);
		if (champs[i].name)
			free(champs[i].name);
		if (champs[i].comment)
			free(champs[i].comment);
		i++;
	}
	free(champs);
	return (NULL);
}

static unsigned char	*write_instr(int value, int size, unsigned char *champ)
{
	int i;

	i = 0;
	while (i < size)
	{
		champ[size - 1 - i] = 0;
		champ[size - 1 - i] |= value;
		value >>= 8;
		i++;
	}
	return (champ + size);
}

static char				*write_to_champ(t_expr *list, int size)
{
	unsigned char	*champ;
	char			*ret;
	int				j;

	j = -1;
	if (!(champ = (unsigned char*)ft_memalloc(sizeof(char) * (size))))
		exit(1);
	ret = (char*)champ;
	while (list)
	{
		if (list->type == INSTR)
		{
			*(champ)++ = list->instr->op;
			if (list->instr->ocp)
				*(champ)++ = list->instr->ocp;
			while (++j < list->instr->par_nbr)
				champ = write_instr(list->instr->par[j].value,
						list->instr->par[j].size, champ);
			j = -1;
		}
		list = list->next;
	}
	return (ret);
}

int						convert_to_hex(char *path, t_champ *champ)
{
	char	*name_com;
	char	*tmp;
	t_expr	*list;
	t_expr	*begin;
	int		last;

	if (!convert_champ(path, 1, &name_com, &list))
		return (0);
	begin = list;
	tmp = name_com;
	while (list->next && list)
	{
		if (list->type == INSTR && list->instr)
			last = list->instr->mem_size;
		list = list->next;
	}
	if (list->type == INSTR)
		last = list->instr->mem_size;
	last += list->addr;
	name_com = get_name(&champ->name, name_com);
	champ->comment = get_comment(name_com);
	champ->size = last;
	champ->champion = write_to_champ(begin, champ->size);
	return (1 | end_free(NULL, tmp, begin));
}