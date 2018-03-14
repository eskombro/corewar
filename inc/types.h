/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:45:04 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/14 19:23:56 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "vm_params.h"

# define SIZE_OPCODE 1
# define SIZE_OCP 1
# define SIZE_REGISTER_IDX 1
# define SIZE_INDIRECT 2
# define SIZE_DIRECT 2
# define SIZE_LONG_DIRECT 4

typedef unsigned char			uchar;

typedef char					t_reg[REG_SIZE];

typedef int						t_addr;

typedef struct					s_champ
{
	int							id;
	t_addr						spawn;
	char						*name;
	char						*comment;
	char						*champion;
	int							size;
}								t_champ;

typedef struct					s_par
{
	unsigned int				size;
	unsigned int				value;
	unsigned int				type;
}								t_par;

typedef struct					s_instr
{
	int							wait_cycles;
	char						opcode;
	t_par						par[3];
	void						(*run_instr)(void *process);
}								t_instr;

# define T_RG 0x01
# define T_D2 0x02
# define T_D4 0x04
# define T_ID 0x08

# define F_OCP 0x01
# define F_ADDR 0x02

typedef struct					s_instr_def
{
	char						opcode;
	char						par_nbr;
	char						par_type[3];
	int							cycles;
	char						flags;
	void						(*run_instr)(void *instr);
}								t_instr_def;

typedef struct					s_proc
{
	int							id;
	t_champ						*owner;
	t_addr						pc;
	int							carry;
	t_instr						*current_task;
	t_reg						reg[REG_NUMBER];
}								t_proc;

#endif
