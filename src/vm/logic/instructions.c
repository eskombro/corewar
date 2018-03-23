/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:08:45 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 18:02:35 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_instr_def		get_instr_def(int opcode)
{
	static t_instr_def	defs[17] = {
		{ 0, 0, { 0, 0, 0 }, 1, 0, NULL},
		{ I_LIVE, 1, { T_D4 }, 10, 0, &live },
		{ I_LD, 2, { T_ID | T_D4, T_RG }, 5, F_OCP | F_ADDR, &ld },
		{ I_ST, 2, { T_RG, T_RG | T_ID }, 5, F_OCP | F_ADDR, &st },
		{ I_ADD, 3, { T_RG, T_RG, T_RG }, 10, F_OCP, &add },
		{ I_SUB, 3, { T_RG, T_RG, T_RG }, 10, F_OCP, &sub },
		{ I_AND, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, &and },
		{ I_OR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, &or },
		{ I_XOR, 3, { T_RG | T_ID | T_D4, T_RG | T_ID | T_D4, T_RG }, 6, F_OCP | F_ADDR, &xor },
		{ I_ZJMP, 1, { T_D2 }, 20, 0, &zjmp },
		{ I_LDI, 3, { T_RG | T_ID | T_D2, T_RG | T_D2, T_RG }, 25, F_OCP | F_ADDR, &ldi },
		{ I_STI, 3, { T_RG, T_RG | T_ID | T_D2, T_RG | T_D2 }, 25, F_OCP | F_ADDR, &sti },
		{ I_FORK, 1, { T_D2 }, 800, F_ADDR, &sfork },
		{ I_LLD, 2, { T_ID | T_D4, T_RG }, 10, F_OCP, &lld },
		{ I_LLDI, 3, { T_RG | T_ID | T_D2, T_ID | T_D2, T_RG }, 50, F_OCP, &lldi },
		{ I_LFORK, 1, { T_D2 }, 1000, 0, &lfork },
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

static int			read_ocp(t_proc *process, t_instr_def def,
						t_instr *instr)
{
	uchar			*buf;
	int				i;

	buf = read_memory(process->pc + process->owner->spawn,
		instr->mem_size, 1, 0);
	i = 3;
	instr->mem_size += 1;
	while (i--)
	{
		(*buf) >>= 2;
		if (i >= def.par_nbr)
			continue ;
		if (((*buf) & 0x03) == MT_RG)
			init_par(instr->par + i, T_RG);
		else if (((*buf) & 0x03) == MT_ID)
			init_par(instr->par + i, T_ID);
		else if (((*buf) & 0x03) == MT_DT)
			init_par(instr->par + i, (def.par_type[i] & T_D2) ? T_D2 : T_D4);
	}
	free(buf);
	return (0);
}

static t_value		result_from_mem(unsigned int size, uchar *mem)
{
	t_value			result;
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

static int			fill_parameters(t_proc *process, t_instr_def def, t_instr *instr)
{
	uchar			*buf;
	int				i;
	int				code;

	code = 0;
	if (def.flags & F_OCP)
	{
		if (read_ocp(process, def, instr))
			code = 2;
	}
	else
		default_types(def, instr);
	i = -1;
	while (++i < def.par_nbr)
	{
		buf = read_memory(process->pc + process->owner->spawn,
			instr->mem_size, instr->par[i].size, 0);
		instr->par[i].value = result_from_mem(instr->par[i].size, buf);
		if (!(instr->par[i].type & def.par_type[i]) ||
			(instr->par[i].type == T_RG &&
			(instr->par[i].value > REG_NUMBER || instr->par[i].value <= 0)))
			code = 1;
		instr->mem_size += instr->par[i].size;
		free(buf);
	}
	return (code);
}

void				fill_instr(t_proc *process)
{
	t_instr_def		def;
	t_instr			*instr;

	instr = process->current_task;
	def = get_instr_def(instr->opcode);
	if (fill_parameters(process, def, instr))
	{
		instr->run_instr = NULL;
	}
}

t_instr				*load_instr(t_proc *process)
{
	t_instr_def		def;
	t_instr			*instr;
	uchar			*buf;

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
