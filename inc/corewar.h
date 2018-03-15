/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 06:06:44 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/15 18:24:10 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "types.h"
# include "instructions.h"

/*
** Champions importation
*/
t_champ				*get_all_champ(char **champ_files);
int					calc_spawn(int players, t_champ *champs);

/*
**	Memory
*/
unsigned char		*get_arena(void);
void				write_memory(t_addr pc, t_addr address, t_par par);
unsigned char		*read_memory(t_addr pc, t_addr address, int size, int mod);
void				print_memory(t_addr address, int size);
void				print_arena();
void				write_champ(t_champ *champ);

/*
** Loop
*/
void				run_loop(t_champ *champs, int players_count);

void				spawn_process(t_proc *process);

/*
** Process
*/
t_proc				*load_process(t_champ *owner, t_addr addr, t_proc *parent);

/*
** Instructions
*/
t_instr				*load_instr(t_proc *process, t_addr instr_addr);

/*
** Instructions handlers
*/
void				ld_funct(void *proc);

void				write_reg(t_reg reg, long value);
int					read_reg(t_reg reg);
long				get_parameter_result(t_par par, t_proc *process,
						int restricted);
/*
** Debug
*/
void				debug_instr(int cycle, t_instr *instr);

#endif
