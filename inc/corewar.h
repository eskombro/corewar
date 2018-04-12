/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 06:06:44 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 12:46:15 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "types.h"
# include "commands.h"
# include "instructions.h"

# include <unistd.h>
# include <fcntl.h>
# include <ncurses.h>

/*
** Logic getter
*/
t_logic				*get_logic();

/*
** Corewar parameters
*/
t_params			get_params(void);

/*
** Champions importation
*/
t_champ				*get_all_champ(char **champ_files);
int					calc_spawn(int players, t_champ *champs);

/*
**	Memory
*/
unsigned char		*get_arena(void);
void				write_memory(t_proc *process, t_addr pc,
						t_addr address, t_par par);
unsigned char		*read_memory(t_addr pc, t_addr address, int size, int mod);
void				print_memory(t_addr address, int size);
void				print_arena_dump(void);
void				write_champ(t_champ *champ);

/*
** Loop
*/
void				run_loop(t_champ *champs);

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
t_uchar				*get_arena_visu(void);
void				update_arena_visu(t_proc *process);
void				print_screen(t_logic *logic);

/*
** Commands
*/
void				start_command_reader();

/*
** Callers
*/
void				call_champ_spawn(t_champ *champ);
void				call_champ_win(t_champ *champ);

void				call_process_spawn(t_proc *process);
void				call_process_move(t_proc *process);
void				call_process_death(t_proc *process);

void				call_memory_write(t_proc *writer, t_addr final_address,
						int value);

void				call_instr_start(t_proc *process);
void				call_instr_exec(t_proc *process);

void				call_new_cycle(t_logic *logic);
void				call_live_report(t_proc *process, int player);

void				call_core_begin(void);
void				call_core_end(void);

#endif
