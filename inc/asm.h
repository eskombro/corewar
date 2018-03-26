/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:15:06 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/26 18:43:00 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../lib/inc/libft.h"
# include "vm_params.h"
# include "instructions.h"

# define F_OCP 0x01
# define T_RG 0x01
# define T_D2 0x02
# define T_D4 0x04
# define T_ID 0x08
# define T_LB 0x10
# define MT_RG 0x01
# define MT_DT 0x02
# define MT_ID 0x03
# define INT_SIZE 4
# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define SEPARATOR_CHAR			','
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef int						t_addr;

typedef struct					s_instr_type
{
	char						*name;
	char						opcode;
	char						par_nbr;
	char						par_type[3];
	char						flags;
}								t_instr_type;

typedef struct					s_bin_champ
{
	char						*name;
	char						*comment;
	char						*champion;
	int							size;
}								t_bin_champ;

typedef struct					s_par
{
	char						type;
	unsigned int				size;
	int							value;
	int							*labeled;
}								t_par;

typedef struct					s_instr_list
{
	int							labels;
	unsigned int				pos;
	char						*name;
	char						opcode;
	unsigned int				mem_size;
	unsigned int				par_nbr;
	t_par						par[3];
	struct s_instr_list			*next;
}								t_instr_list;

int								get_all_instr(t_bin_champ *champ);
int								error_msg(char cse);
int								error_msg_instr(char cse, int nbr);
int								convert_int_endian(int num);


#endif
