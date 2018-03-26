/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 06:07:56 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 20:51:42 by bacrozat         ###   ########.fr       */
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

# define CRASH_ON_ERROR 0

/*
** Champions parameters
*/
# define MAX_CHAMPS 4
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

/*
** Ncurse parameters
*/
# define NCURSE_DELAY 1000000 / 2

#endif
