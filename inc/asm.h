/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:15:06 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 18:32:09 by hbouillo         ###   ########.fr       */
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

# define ERR error_param
# define LABEL 0x01
# define INSTR 0x02
# define F_OCP 0x01
# define T_RG 0x01
# define T_D2 0x02
# define T_D4 0x04
# define T_ID 0x08
# define T_LB 0x10
# define MT_RG 0x01
# define MT_DT 0x02
# define MT_ID 0x03
# define RED 0xff0000
# define INT_SIZE 4
# define COMMENT_CHAR			'#'
# define ASM_COMMENT			';'
# define REG_CHAR				'r'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define SEPARATOR_CHAR			','
# define S_C					','
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef int						t_addr;

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

typedef struct					s_expr
{
	char						*expr;
	char						type;
	int							addr;
	int							line;
	char						alloc;
	char						alloced;
	struct s_expr				*next;
	struct s_instr				*instr;
}								t_expr;

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
	int							add_val;
	int							*label;
}								t_par;

typedef struct					s_instr
{
	char						*expr;
	int							addr;
	char						ocp;
	char						op;
	int							par_nbr;
	int							mem_size;
	t_par						par[3];
	struct s_expr				*next;
}								t_instr;

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

void							*free_champs(t_champ *champs);
int								end_free(char *name, char *input, t_expr *list);
void							jump_white_spaces(char **src);
void							handle_label_instr(t_expr **exp, char **tmp,
		int jump);
long							get_op_value(char *tmp);
int								noccur_count(char *str, char c, char d);
t_instr_type					get_instr_type(char *name);
int								print_champ_path(char *path, char *origin);
long							parse_comment(char *tmp);
long							parse_name(char *tmp);
int								parse_expr(t_expr *current, t_expr **list, t_addr *addr);
int								parse_instr(char *champ, int lines, t_expr **list);
void							calc_size(t_expr *expr);
int								check_instr(t_expr *expr, t_expr *list, t_instr_type *type);
int								test_instr(t_expr *expr, t_instr_type *type);
char							*jump_comment(char *tmp);
int								get_name_len(char *name);
int								unbr_len(long nb);
int								count_lines(char *champ, char *tmp);
char							*jump_multi_nl(char *src, int *lines);
char							*get_label_addr(t_expr *list, char *tmp,
		t_par *par);
int								handle_duplicate(t_expr *expr, t_expr *list);
void							get_label_value(t_expr *expr);
int								test_label(t_expr *expr);
int								convert_to_value(int size, char *bin_instr);
int								fill_mem_no_ocp(t_instr_list *instr,
		t_instr_type *type);
int								get_ocp(unsigned char ocp, t_instr_type *type,
		t_instr_list *instr, int nbr);
void							get_labels(t_instr_list *instr, t_bin_champ
		*champ);
void							print_instr_list(t_instr_list *instr, int fd);
void							print_head(t_bin_champ *bin, int fd);
int								convert_to_hex(char *path, t_champ *champ);
char							*get_comment(char *comment);
char							*get_name(char **name, char *champ);
int								is_asm(char *path);
int								error_param(char cse, t_expr *expr, int nb);
int								error_instr(char cse, int line, char *instr);
void							write_champ_bin(t_expr *list, char *champ,
		int fd);
long							ft_long_atoi(char *str);
int								error_msg_asm(char cse, int nb);
int								convert_champ(char *champ_path, int flag,
		char **src, t_expr **list);
int								get_all_instr(t_bin_champ *champ, int fd);
int								error_msg(char cse);
int								error_msg_instr(char cse, int nbr);
int								convert_int_endian(int num);
int								occur_count(char *str, char c);

#endif
