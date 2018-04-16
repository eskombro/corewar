/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 02:32:22 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 22:01:53 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		print_champ_path(char *path, char *origin)
{
	if (!path)
		ft_printf("Error on champ : %s\n", origin);
	else if (path)
		ft_printf("Error on champ : %s\n", path + 1);
	return (0);
}

int		end_free(char *name, char *input, t_expr *list)
{
	t_expr	*tmp;
	int		freed;

	freed = 1;
	if (name)
		ft_strdel(&name);
	if (input)
		ft_strdel(&input);
	if (list)
	{
		while (list)
		{
			tmp = list;
			if (tmp->instr)
				ft_memdel((void**)&tmp->instr);
			if (tmp->alloced && tmp->expr)
				ft_memdel((void**)&tmp->expr);
			else if (--freed == 0)
				ft_memdel((void**)&tmp->expr);
			list = list->next;
			free(tmp);
		}
	}
	return (0);
}
