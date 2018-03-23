/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:45:04 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 23:38:34 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "vm_params.h"

# define S_RG 1
# define S_ID 2
# define S_D2 2
# define S_D4 4

typedef struct					s_params
{
	char						**champs_files;
	int							players;
	int							dump;
	int							verbose;
	int							ncurse;
}								t_params;

typedef unsigned char			t_uchar;

typedef char					t_reg[REG_SIZE];

typedef int						t_addr;

typedef int						t_value;

typedef struct					s_champ
{
	int							fixed_id;
	int							id;
	int							lives;
	t_addr						spawn;
	char						*name;
	char						*comment;
	char						*champion;
	int							size;
}								t_champ;

typedef struct					s_par
{
	char						type;
	unsigned int				size;
	t_value						value;
}								t_par;

# define MT_RG 0x01
# define MT_DT 0x02
# define MT_ID 0x03

typedef struct					s_instr
{
	unsigned int				mem_size;
	int							wait_cycles;
	char						opcode;
	t_par						par[3];
	void						(*run_instr)(void *process);
}								t_instr;

# define T_RG 0x01
# define T_D2 0x02
# define T_D4 0x04
# define T_ID 0x08

# define OCP 0x01

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
	int							alive;
	t_champ						*owner;
	t_addr						pc;
	int							carry;
	t_instr						*current_task;
	t_reg						reg[REG_NUMBER];
}								t_proc;

typedef struct					s_logic
{
	t_params					params;
	t_champ						*champs;
	t_llist						*queue;
	int							cycles;
	int							cycles_to_die;
	int							cycles_left;
	int							lives;
	t_champ						*last_live;
}								t_logic;

#endif
