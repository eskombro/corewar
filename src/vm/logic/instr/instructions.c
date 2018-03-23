/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:08:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/24 00:08:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./instr.h"

t_instr_def				get_instr_def(int opcode)
{
	static t_instr_def	defs[17] = {
{ 0, 0, { 0, 0, 0 }, 1, 0, NULL},
{ I_LIVE, 1, { T_D4 }, 10, 0, &live },
{ I_LD, 2, { T_ID | T_D4, T_RG }, 5, OCP, &ld },
{ I_ST, 2, { T_RG, T_RG | T_ID }, 5, OCP, &st },
{ I_ADD, 3, { T_RG, T_RG, T_RG }, 10, OCP, &add },
{ I_SUB, 3, { T_RG, T_RG, T_RG }, 10, OCP, &sub },
{ I_AND, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, OCP, &and },
{ I_OR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, OCP, &or },
{ I_XOR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, OCP, &xor },
{ I_ZJMP, 1, { T_D2 }, 20, 0, &zjmp },
{ I_LDI, 3, { T_RG | T_ID | T_D2, T_RG | T_D2, T_RG }, 25, OCP, &ldi },
{ I_STI, 3, { T_RG, T_RG | T_ID | T_D2, T_RG | T_D2 }, 25, OCP, &sti },
{ I_FORK, 1, { T_D2 }, 800, 0, &sfork },
{ I_LLD, 2, { T_ID | T_D4, T_RG }, 10, OCP, &lld },
{ I_LLDI, 3, { T_RG | T_ID | T_D2, T_ID | T_D2, T_RG }, 50, OCP, &lldi },
{ I_LFORK, 1, { T_D2 }, 1000, 0, &lfork },
{ I_AFF, 1, { T_RG }, 2, OCP, &aff }};

	return (defs[opcode < 0 || opcode > 16 ? 0 : opcode]);
}

void					del_instr(void *data)
{
	t_instr				*instr;

	instr = (t_instr *)data;
	free(instr);
}

void					fill_instr(t_proc *process)
{
	t_instr_def			def;
	t_instr				*instr;

	instr = process->current_task;
	def = get_instr_def(instr->opcode);
	if (fill_parameters(process, def, instr))
	{
		instr->run_instr = NULL;
	}
}

t_instr					*load_instr(t_proc *process)
{
	t_instr_def			def;
	t_instr				*instr;
	t_uchar				*buf;

	buf = read_memory(process->pc + process->owner->spawn, 0, 1, 0);
	def = get_instr_def((int)*buf);
	free(buf);
	if (!def.opcode && CRASH_ON_ERROR)
		return (NULL);
	if (!(instr = (t_instr *)ft_memalloc(sizeof(t_instr))))
		return (NULL);
	instr->mem_size = 1;
	instr->opcode = def.opcode;
	instr->wait_cycles = def.cycles;
	instr->run_instr = def.run_instr;
	return (instr);
}
