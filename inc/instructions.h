/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 00:19:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/18 01:17:43 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# define I_LIVE 0x01
# define I_LD 0x02
# define I_ST 0x03
# define I_ADD 0x04
# define I_SUB 0x05
# define I_AND 0x06
# define I_OR 0x07
# define I_XOR 0x08
# define I_ZJMP 0x09
# define I_LDI 0x0a
# define I_STI 0x0b
# define I_FORK 0x0c
# define I_LLD 0x0d
# define I_LLDI 0x0e
# define I_LFORK 0x0f
# define I_AFF 0x10

/*
** Handlers
*/
void				add(void *proc);
void				aff(void *proc);
void				and(void *proc);
void				sfork(void *proc);
void				ld(void *proc);
void				lld(void *proc);
void				ldi(void *proc);
void				lldi(void *proc);
void				lfork(void *proc);
void				live(void *proc);
void				or(void *proc);
void				st(void *proc);
void				sti(void *proc);
void				sub(void *proc);
void				xor(void *proc);
void				zjmp(void *proc);

#endif
