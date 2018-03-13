/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 06:06:44 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/13 19:55:07 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "types.h"
# include "instructions.h"

/*
** Process
*/
t_proc		*load_process(t_champ *owner, t_addr addr, t_proc *parent);

/*
** Instructions
*/
t_instr		*load_instr(t_addr instr_addr);


#endif
