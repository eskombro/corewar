/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 21:46:04 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/17 23:13:09 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE_H
# define VERBOSE_H

#include "corewar.h"

void		print_live(t_proc *or_proc);
void		print_ld(t_proc *proc);
void		print_st(t_proc *proc);
void		print_add(t_proc *proc);
void		print_sub(t_proc *proc);
void		print_and(t_proc *proc);
void		print_or(t_proc *proc);
void		print_xor(t_proc *proc);
void		print_zjmp(t_proc *proc);
void		print_ldi(t_proc *proc);
void		print_sti(t_proc *proc);
void		print_fork(t_proc *proc);
void		print_lld(t_proc *proc);
void		print_lldi(t_proc *proc);
void		print_lfork(t_proc *proc);
void		print_aff(t_proc *proc);
void		print_norm_line(t_proc *proc, int nb_param, int restr);

#endif
