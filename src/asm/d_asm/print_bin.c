/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 23:14:04 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/14 23:29:03 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static void	print_instr_param(int i, t_instr_list *instr, int fd)
{
	if (i)
		ft_dprintf(fd, ", ");
	if ((instr->par[i].type & T_D2) || (instr->par[i].type & T_D4))
		ft_dprintf(fd, "%%");
	if (instr->par[i].type & T_RG)
		ft_dprintf(fd, "r");
	if (instr->par[i].type & T_LB)
		ft_dprintf(fd, ":label_%d", *instr->par[i].label);
	else
		ft_dprintf(fd, "%d", instr->par[i].value);
}

void		print_instr_list(t_instr_list *instr, int fd)
{
	int		i;

	while (instr)
	{
		if (instr->labels)
			ft_dprintf(fd, "\nlabel_%d:\n", instr->labels);
		ft_dprintf(fd, "\t%s\t\t\t\t", instr->name);
		if (ft_strlen(instr->name) < 4)
			ft_dprintf(fd, "\t");
		i = 0;
		while (i < (int)instr->par_nbr)
		{
			print_instr_param(i, instr, fd);
			i++;
		}
		instr = instr->next;
		ft_dprintf(fd, "\n");
	}
}

void		print_head(t_bin_champ *bin, int fd)
{
	ft_dprintf(fd, "%s ", NAME_CMD_STRING);
	ft_dprintf(fd, "%c", 34);
	ft_dprintf(fd, "%s", bin->name);
	ft_dprintf(fd, "%c\n", 34);
	ft_dprintf(fd, "%s ", COMMENT_CMD_STRING);
	ft_dprintf(fd, "%c", 34);
	ft_dprintf(fd, "%s", bin->comment);
	ft_dprintf(fd, "%c\n", 34);
}
