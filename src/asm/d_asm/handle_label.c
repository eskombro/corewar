/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:17:40 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/01 01:27:44 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int		*check_list(t_instr_list *instr, int addr)
{
	static int	label = 0;
	int			ret;

	ret = 0;
	while (instr)
	{
		if (instr->pos == addr)
		{
			if (instr->labels)
				ret = instr->labels;
			else
			{
				label++;
				instr->labels = label;
				ret = label;
			}
			break ;
		}
		instr = instr->next;
	}
	return (instr ? &instr->labels : 0);
}

static int		check_labels(t_par par[3], int size, t_instr_list *instr,
		t_instr_list *current)
{
	int i;
	int *ret;

	i = 0;
	while (i < current->par_nbr)
	{
		if (par[i].value && par[i].value + current->pos < size &&
				!(par[i].type & T_RG))
		{
			if ((ret = check_list(instr, par[i].value + current->pos)))
			{
				par[i].type |= T_LB;
				par[i].label = ret;
			}
		}
		i++;
	}
	return (1);
}

void			get_labels(t_instr_list *instr, t_bin_champ *champ)
{
	t_instr_list	*begin;
	int				i;

	i = 1;
	begin = instr;
	while (instr)
	{
		check_labels(instr->par, champ->size, begin, instr);
		instr = instr->next;
	}
	while (begin)
	{
		if (begin->labels)
		{
			begin->labels = i;
			i++;
		}
		begin = begin->next;
	}
}

int				convert_int_endian(int num)
{
	unsigned int swapped;

	swapped = ((num >> 24) & 0xff) |
		((num << 8) & 0xff0000) |
		((num >> 8) & 0xff00) |
		((num << 24) & 0xff000000);
	return (swapped);
}
