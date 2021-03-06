/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:28:37 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/27 00:09:52 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H

# include "corewar.h"

/*
** Process
*/
void					kill_process(t_proc *process);
void					del_process(void *data);

/*
** Instructions
*/
void					del_instr(void *data);

/*
** Lives
*/
void					check_lives(void);

#endif
