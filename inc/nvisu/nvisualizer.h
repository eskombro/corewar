/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nvisualizer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:17:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 22:09:21 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NVISUALIZER_H
# define NVISUALIZER_H

# include "libft.h"
# include "types.h"
# include "commands.h"

# include <unistd.h>
# include <ncurses.h>
# include <time.h>

# define MEM_TAB_LENGTH 64
# define PROC_TAB_SIZE 100
<<<<<<< HEAD
# define SECOND 1000000000

typedef struct timespec	t_time;
=======
>>>>>>> acf57b6344c6d1c22fd38981c2bd082dafbd8fda

typedef struct			s_v_champ
{
	int					id;
	char				*name;
	int					spawn;
	int					spawn_x;
	int					spawn_y;
	int					lifes;
	int					lifes_round;
}						t_v_champ;

typedef struct			s_v_proc
{
	int					id;
	struct s_v_champ	*owner;
	int					owner_id;
	int					pc;
	struct s_v_proc		*next;
}						t_v_proc;

typedef struct			s_v_stats
{
	int					cycles;
	int					cycles_to_die;
	int					cycles_left;
	char				last_life[16];
}						t_v_stats;

typedef struct			s_visu
{
	t_uchar				*mem;
	int					*mem_proc;
	int					mem_tab_height;
	int					start_x;
	int					start_y;
	int					m_size;
	int					champ_nb;
	t_v_champ			**champs;
	t_v_proc			**procs;
	struct s_v_stats	*stats;
	int					cps;
	int					end;
	int					run;
}						t_visu;

/*
** main.c
*/

t_visu					*get_visu(void);

/*
** Communication_corewar.c
*/

void					parent(int *to_vm, int *from_vm);
void					child(int *to_vm, int *from_vm, char **argv);
void					run_corewar(char **argv);
void					debug_command(t_command command);

/*
** handle_champ_callers.c
*/

void					handle_champ_spawn(t_command *command);
void					handle_champ_wins(t_command *command);

/*
** handle_core_callers.c
*/

void					handle_core_begin(t_command *command);
void					handle_core_end(void);

/*
** handle_logic_callers.c
*/

void					handle_logic_cycle(t_command *command);
void					handle_logic_life(t_command *command);

/*
** handle_memory_callers.c
*/

int						find_proc_owner_nb(int proc_id);
void					handle_mem_write(t_command *command);

/*
** handle_process_callers.c
*/

void					handle_proc_spawn(t_command *command);
void					handle_proc_move(t_command *command);
void					handle_proc_death(t_command *command);

/*
** process_display.c
*/

int						display_proc_pc_calc(int col, int pc_rel_spawn);
void					display_proc_pc(t_v_proc *proc);

/*
** initialize_ncurses.c
*/

void					initialize_ncurses(void);

/*
** test_char.c
*/

void					test_char(void);

/*
** free_all.c
*/

void					free_all(void);

/*
** display_shortcuts.c
*/

void					display_shortcuts(void);

/*
** print_modules.c
*/

void					print_header(void);
void					print_header2(int y, int x, int i);
void					display_leaderboard(void);
void					display_stats(void);
void					print_win_panel(int x, int y, char *str);

#endif
