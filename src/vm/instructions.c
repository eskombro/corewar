/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:08:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/13 13:18:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_instr_def		get_instr_def(int opcode)
{
	static t_instr_def	defs[17] = {
		{ 0, 0, { 0, 0, 0 }, 0, 0 },
		{ I_LIVE, 1, { T_D4 }, 10, 0 },
		{ I_LD, 2, { T_ID | T_D4, T_RG }, 5, F_OCP | F_ADDR },
		{ I_ST, 2, { T_RG, T_RG | T_ID }, 5, F_OCP | F_ADDR },
		{ I_ADD, 3, { T_RG, T_RG, T_RG }, 10, F_OCP },
		{ I_SUB, 3, { T_RG, T_RG, T_RG }, 10, F_OCP },
		{ I_AND, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR },
		{ I_OR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR },
		{ I_XOR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR },
		{ I_ZJMP, 1, { T_D2 }, 20, 0 },
		{ I_LDI, 3, { T_RG | T_ID | T_D2, T_ID | T_D2, T_RG }, 25, F_OCP | F_ADDR },
		{ I_STI, 3, { T_RG, T_RG | T_ID | T_D2, T_ID | T_D2 }, 25, F_OCP | F_ADDR },
		{ I_FORK, 1, { T_D2 }, 800, F_ADDR },
		{ I_LLD, 2, { T_ID | T_D4, T_RG }, 10, F_OCP },
		{ I_LLDI, 3, { T_RG | T_ID | T_D2, T_ID | T_D2, T_RG }, 50, F_OCP },
		{ I_LFORK, 1, { T_D2 }, 1000, 0 },
		{ I_AFF, 1, { T_RG }, 2, F_OCP } };

	if (opcode < 0 || opcode >= 16)
		opcode = 0;
	return (defs[opcode]);
}

t_instr				*load_instr(t_addr instr_addr, t_instr_def def)
{
	t_instr		*instr;

	if (!(instr = (t_instr *)ft_memalloc(sizeof(t_instr))))
		exit(1);
	instr->opcode = def.opcode;
	instr->wait_cycles = def.cycles;
	instr_addr = 0; // TODO: Load instr from memory
	return (instr);
}
