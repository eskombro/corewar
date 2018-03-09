/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:45:04 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/10 00:06:59 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define SIZE_OPCODE 1
# define SIZE_OCP 1
# define SIZE_REGISTER_IDX 1
# define SIZE_INDIRECT 2
# define SIZE_DIRECT 2
# define SIZE_LONG_DIRECT 4

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

typedef struct					s_parameter
{
	int							size;
	int							value;
}								t_parameter;

typedef struct					s_instruction
{
	int							wait_cycles;
	int							opcode;
	t_parameter					*parameters;
}								t_instruction;

typedef struct					s_process
{
	int							id;
	int							owner;
	int							spawn;
	int							pc;
	t_instruction				*current_task;
	t_register					registers[REG_NUMBER];
}								t_process;

#endif
