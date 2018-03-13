/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:45:04 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/13 21:29:05 by sjimenez         ###   ########.fr       */
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
}								t_par;

typedef struct					s_instr
{
	int							wait_cycles;
	int							opcode;
	t_par						*parameters;
}								t_instr;

typedef struct					s_proc
{
	int							id;
	t_champ						*owner;
	t_addr						pc;
	int							carry;
	t_instr						*current_task;
	t_reg						registers[REG_NUMBER];
}								t_proc;

/*
**	gestion_memoire
*/

unsigned char					*get_arena(void);
void							write_memory(t_addr pc, t_addr address, t_par par);
unsigned char					*read_memory(int address, int size);
void							print_memory(int address, int size);
void							print_arena();

#endif
