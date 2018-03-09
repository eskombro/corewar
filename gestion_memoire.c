/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_memoire.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 22:47:20 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/09 23:27:37 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*get_arena(void)
{
	static char		arena[MEM_SIZE];

	return (arena);
}

# define MODE_DIRECT 0xF0
# define MODE_INDIRECT 0x0F

void				write_reg(int adresse, t_process process, char mode)
{
	// Faire % IDX_MOD
	if (mode & MODE_DIRECT)
	{
		//Ecriture Direct
	}
	else
	{
		//Ecriture Indirect
	}
}

void				read_memory()
{

}

void				print_memory()
{

}
