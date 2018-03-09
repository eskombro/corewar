/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:45:04 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/09 22:42:26 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define SIZE_OPCODE 1
typedef char[SIZE_OPCODE]		t_opcode;

# define SIZE_OCP 1
typedef char[SIZE_OCP]			t_ocp;

# define SIZE_REGISTER_IDX 1
typedef char[SIZE_REGISTER_IDX]	t_register_idx;

# define SIZE_INDIRECT 2
typedef char[SIZE_INDIRECT]		t_indirect;

# define SIZE_DIRECT 2
typedef char[SIZE_DIRECT]		t_direct;

# define SIZE_LONG_DIRECT 4
typedef char[SIZE_LONG_DIRECT]	t_ldirect;

# define REG_NUMBER 16

# define REG_SIZE 4
typedef char[REG_SIZE]			t_register;

typedef struct					s_champion
{
	int							id;
	char						*name;
	char						*comment;
	char						*champion;
}								t_champion;

typedef union					u_parameter
{
	t_register_idx				reg;
	t_indirect					ind;
	t_direct					dir;
}								t_parameter;

typedef struct					s_instruction
{
	int							wait_cycles;
	int							opcode;
	t_parameter					*parameters;
}								t_instruction;

typedef struct					s_process
{
	int							owner;
	int							id;
	int							pc;
	t_instruction				*current_task;
	t_register					registers[REG_NUMBER];
}								t_process;

#endif
