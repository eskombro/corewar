/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nvisualizer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:17:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/14 00:27:41 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "libft.h"
# include "types.h"
# include "commands.h"

# include <unistd.h>
# include <ncurses.h>

# define	MEM_TAB_LENGTH 64
# define	PROC_TAB_SIZE 100

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
}						t_visu;

void					parent(int *to_vm, int *from_vm);
void					child(int *to_vm, int *from_vm, char **argv);
void					run_corewar(char **argv);
void					debug_command(t_command command);

#endif
