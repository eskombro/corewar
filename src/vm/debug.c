/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:01:49 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/16 19:15:22 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			debug_instr(int cycle, t_instr *instr, t_proc *proc)
{
	int			i;
	char		*type;

	ft_printf("Exec 0x%.2x at cycle %d by process %d at pc %d (spawn is %d)\n", instr->opcode,
		cycle, proc->id, proc->pc, proc->owner->spawn);
	i = -1;
	while (++i < 3)
	{
		if (instr->par[i].size)
		{
			type = NULL;
			if (instr->par[i].type == T_RG)
				type = "REGISTER";
			if (instr->par[i].type == T_D2 || instr->par[i].type == T_D4)
				type = "DIRECT";
			if (instr->par[i].type == T_ID)
				type = "INDEX";
			ft_printf("    P%d: TYPE=%s, SIZE=%d, VALUE=%ld\n", i + 1, type, instr->par[i].size, instr->par[i].value);
		}
	}
}

void			debug_reg(t_proc *proc)
{
	int			i;

	i = -1;
	while (++i < REG_NUMBER)
	{
		ft_printf("r%-2d 0x%.16lx    ", i + 1, read_reg(proc->reg[i]));
		if (!((i + 1) % 4))
			ft_putchar('\n');
	}
}

void			debug_live_report(t_proc *process, t_champ *champ)
{
	ft_printf("Process %d (lives: %d) reported %s (%d) (lives: %d) as alive\n",
		process->id, process->lives, champ->name, champ->id, champ->lives);
}
