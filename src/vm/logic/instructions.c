/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:08:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/15 22:34:44 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_instr_def		get_instr_def(int opcode)
{
	static t_instr_def	defs[17] = {
		{ 0, 0, { 0, 0, 0 }, 0, 0, NULL},
		{ I_LIVE, 1, { T_D4 }, 10, 0, NULL },
		{ I_LD, 2, { T_ID | T_D4, T_RG }, 5, F_OCP | F_ADDR, &ld },
		{ I_ST, 2, { T_RG, T_RG | T_ID }, 5, F_OCP | F_ADDR, NULL },
		{ I_ADD, 3, { T_RG, T_RG, T_RG }, 10, F_OCP, &add },
		{ I_SUB, 3, { T_RG, T_RG, T_RG }, 10, F_OCP, &sub },
		{ I_AND, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, &and },
		{ I_OR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, &or },
		{ I_XOR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, &xor },
		{ I_ZJMP, 1, { T_D2 }, 20, 0, &zjmp },
		{ I_LDI, 3, { T_RG | T_ID | T_D2 | T_D2, T_RG }, 25, F_OCP | F_ADDR, NULL },
		{ I_STI, 3, { T_RG, T_RG | T_ID | T_D2, T_D2 }, 25, F_OCP | F_ADDR, NULL },
		{ I_FORK, 1, { T_D2 }, 800, F_ADDR, NULL },
		{ I_LLD, 2, { T_ID | T_D4, T_RG }, 10, F_OCP, NULL },
		{ I_LLDI, 3, { T_RG | T_ID | T_D2, T_ID | T_D2, T_RG }, 50, F_OCP, NULL },
		{ I_LFORK, 1, { T_D2 }, 1000, 0, NULL },
		{ I_AFF, 1, { T_RG }, 2, F_OCP, &aff } };

	if (opcode < 0 || opcode > 16)
		opcode = 0;
	return (defs[opcode]);
}

static void			init_par(t_par *par, char type)
{
	par->type = type;
	if (par->type == T_RG)
		par->size = S_RG;
	else if (par->type == T_ID)
		par->size = S_ID;
	else if (par->type == T_D2)
		par->size = S_D2;
	else if (par->type == T_D4)
		par->size = S_D4;
}

static void			default_types(t_instr_def def, t_instr *instr)
{
	int				i;

	i = -1;
	while (++i < 3)
		init_par(instr->par + i, def.par_type[i]);
}

static void			read_ocp(t_proc *process, t_instr_def def,
						t_instr *instr, t_addr instr_addr)
{
	uchar			*buf;
	int				i;
	//TODO: Erreurs de parametres ?
	buf = read_memory(process->pc + process->owner->spawn,
		instr_addr + instr->mem_size, 1, 0);
	i = 3;
	instr->mem_size += 1;
	while (i--)
	{
		(*buf) >>= 2;
		if (((*buf) & 0x03) == MT_RG)
			init_par(instr->par + i, T_RG);
		else if (((*buf) & 0x03) == MT_ID)
			init_par(instr->par + i, T_ID);
		else if (((*buf) & 0x03) == MT_DT)
			init_par(instr->par + i, def.par_type[i] & T_D2 ? T_D2 : T_D4);
	}
	free(buf);
}

static long			result_from_mem(unsigned int size, uchar *mem)
{
	long			result;
	unsigned int	i;

	i = 0;
	result = 0;
	while (i < size)
	{
		result <<= 8;
		result |= mem[i] & 0xFF;
		i++;
	}
	return (result);
}

static void			fill_parameters(t_proc *process, t_instr_def def, t_instr *instr,
						t_addr instr_addr)
{
	uchar			*buf;
	int				i;

	if (def.flags & F_OCP)
		read_ocp(process, def, instr, instr_addr);
	else
		default_types(def, instr);
	i = -1;
	while (++i < 3)
	{
		buf = read_memory(process->pc + process->owner->spawn,
			instr_addr + instr->mem_size, instr->par[i].size, 0);
		instr->par[i].value = result_from_mem(instr->par[i].size, buf);
		instr->mem_size += instr->par[i].size;
		free(buf);
	}
}

t_instr				*load_instr(t_proc *process, t_addr instr_addr)
{
	t_instr_def		def;
	t_instr			*instr;
	uchar			*buf;

	buf = read_memory(process->pc + process->owner->spawn, instr_addr, 1, 0);
	def = get_instr_def((int)*buf);
	free(buf);
	if (!def.opcode && CRASH_ON_NULL_INSTR)
		return (NULL);
	if (!(instr = (t_instr *)ft_memalloc(sizeof(t_instr))))
		return (NULL);
	instr->mem_size = 1;
	instr->opcode = def.opcode;
	instr->wait_cycles = def.cycles;
	instr->run_instr = def.run_instr;
	fill_parameters(process, def, instr, instr_addr);
	return (instr);
}
