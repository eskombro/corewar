/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 06:07:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/15 17:33:11 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_PARAMS_H
# define VM_PARAMS_H

/*
** Memory parameters
*/
# define MEM_SIZE (4 * 1024)
# define IDX_MOD (MEM_SIZE / 8)

# define REG_NUMBER 16
# define REG_SIZE 4

/*
** VM Rules parameters
*/
# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECKS 10

# define CRASH_ON_NULL_INSTR 0

/*
** Champions parameters
*/
# define MAX_CHAMPS 4
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

#endif
