/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 06:06:44 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/14 15:24:01 by hbouillo         ###   ########.fr       */
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

/*
**	Memory
*/
unsigned char		*get_arena(void);
void				write_memory(t_addr pc, t_addr address, t_par par);
unsigned char		*read_memory(int address, int size);
void				print_memory(int address, int size);
void				print_arena();

/*
** Process
*/
t_proc				*load_process(t_champ *owner, t_addr addr, t_proc *parent);

/*
** Instructions
*/
t_instr				*load_instr(t_addr instr_addr);


#endif
