/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:08:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/13 19:57:21 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_instr_def		get_instr_def(int opcode)
{
	static t_instr_def	defs[17] = {
		{ 0, 0, { 0, 0, 0 }, 0, 0, NULL},
		{ I_LIVE, 1, { T_D4 }, 10, 0, NULL },
		{ I_LD, 2, { T_ID | T_D4, T_RG }, 5, F_OCP | F_ADDR, NULL },
		{ I_ST, 2, { T_RG, T_RG | T_ID }, 5, F_OCP | F_ADDR, NULL },
		{ I_ADD, 3, { T_RG, T_RG, T_RG }, 10, F_OCP, NULL },
		{ I_SUB, 3, { T_RG, T_RG, T_RG }, 10, F_OCP, NULL },
		{ I_AND, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, NULL },
		{ I_OR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, NULL },
		{ I_XOR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, NULL },
		{ I_ZJMP, 1, { T_D2 }, 20, 0, NULL },
		{ I_LDI, 3, { T_RG | T_ID | T_D2 | T_D2, T_RG }, 25, F_OCP | F_ADDR, NULL },
		{ I_STI, 3, { T_RG, T_RG | T_ID | T_D2, T_D2 }, 25, F_OCP | F_ADDR, NULL },
		{ I_FORK, 1, { T_D2 }, 800, F_ADDR, NULL },
		{ I_LLD, 2, { T_ID | T_D4, T_RG }, 10, F_OCP, NULL },
		{ I_LLDI, 3, { T_RG | T_ID | T_D2, T_ID | T_D2, T_RG }, 50, F_OCP, NULL },
		{ I_LFORK, 1, { T_D2 }, 1000, 0, NULL },
		{ I_AFF, 1, { T_RG }, 2, F_OCP, NULL } };

	if (opcode < 0 || opcode >= 16)
		opcode = 0;
	return (defs[opcode]);
}

t_instr				*load_instr(t_addr instr_addr)
{
	t_instr_def	def;
	t_instr		*instr;

	//TODO: Load def from opcode, load opcode from memory
	if (!def.opcode)
		return (NULL);
	if (!(instr = (t_instr *)ft_memalloc(sizeof(t_instr))))
		exit(1);
	instr->opcode = def.opcode;
	instr->wait_cycles = def.cycles;
	instr->run_instr = def.run_instr;
	instr_addr = 0; // TODO: Load instr from memory
	return (instr);
}
