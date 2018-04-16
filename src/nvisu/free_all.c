/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 02:02:17 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/16 04:06:18 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"

void			free_all(void)
{
	int			i;
	t_v_proc	*tmp;
	t_v_proc	*tmp_proc;

	i = -1;
	ft_strdel((char**)&get_visu()->mem);
	while (++i < get_visu()->champ_nb)
	{
		ft_strdel(&get_visu()->champs[i]->name);
		ft_memdel((void**)&get_visu()->champs[i]);
	}
	ft_memdel((void**)&get_visu()->champs);
	i = -1;
	tmp_proc = NULL;
	while (++i < PROC_TAB_SIZE)
	{
		tmp_proc = get_visu()->procs[i];
		while (tmp_proc)
		{
			tmp = tmp_proc->next;
			ft_memdel((void**)&tmp_proc);
			tmp_proc = tmp;
		}
	}
	ft_memdel((void**)&get_visu()->procs);
}
