/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:44:55 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/18 04:19:30 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verbose.h"

void		print_instr(int code)
{
	static char *tab[16] = { "null", "live", "ld", "st", "add", "sub", "and",
		"or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "aff" };
	ft_printf("%s", tab[code]);
}

void		print_norm_line(t_proc *proc, int nb_param, int restr)
{
	int i;

	i = 0;
	ft_printf("P%5d | ", proc->id + 1);
	print_instr(proc->current_task->opcode);
	while (i < nb_param)
	{
		if (proc->current_task->par[i].type != T_RG)
		{
			ft_printf(" %ld", get_parameter_result(proc->current_task->par[i],
						proc, restr));
		}
		else
			ft_printf(" r%ld", proc->current_task->par[i].value);
		i++;
	}
	ft_printf("\n");
}

int			verbose(void *or_proc)
{
	t_proc *proc;

	proc = (t_proc*)or_proc;
	static void (*const print[17])(t_proc *or_proc) = { NULL, &print_live,
		&print_ld, &print_st, &print_add, &print_sub, &print_and, &print_or,
		&print_xor, &print_zjmp, &print_ldi, &print_sti, &print_fork,
		&print_lld, &print_lldi, &print_lfork, &print_aff};

	print[(int)proc->current_task->opcode](proc);
	return(0);
}
/*
int			verbose(void *or_proc)
{
	t_proc *proc;

	proc = (t_proc*)or_proc;
	static void (*const print[17])(t_proc *or_proc) = { NULL, &print_live, &print_ld,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL };

	print[(int)proc->current_task->opcode](proc);
	return(0);
}*/
