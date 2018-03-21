/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 06:06:44 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/21 02:56:21 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "types.h"
# include "instructions.h"

#include <unistd.h>
#include <ncurses.h>

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
void				print_arena(void);
void				print_arena_dump(void);
void				write_champ(t_champ *champ);

/*
** Loop
*/
void				run_loop(t_champ *champs, int players_count, int dump,
		int verbose, int visu);

void				spawn_process(t_proc *process);

void				report_live(t_proc *proc, int player);
/*
** Process
*/
t_proc				*load_process(t_champ *owner, t_addr addr, t_proc *parent);

/*
** Instructions
*/
t_instr				*load_instr(t_proc *process);
void				fill_instr(t_proc *process);

/*
** Instructions
*/
void				ld_funct(void *proc);

void				write_reg(t_reg reg, t_value value);
t_value				read_reg(t_reg reg);
t_value				get_parameter_result(t_par par, t_proc *process,
						int restricted);
/*
** Debug
*/
int					verbose(void *or_proc);
void				debug_instr(int cycle, t_instr *instr, t_proc *process);
void				debug_reg(t_proc *proc);
void				debug_live_report(t_proc *proc, t_champ *champ);
void				debug_process_crash(t_proc *proc);

/*
** visu_ncurses
*/
uchar				*get_arena_visu(void);
void				update_arena_visu(t_proc *process);
void				print_screen(t_logic *logic);

#endif
