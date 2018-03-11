/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_memoire.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 22:47:20 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/11 02:32:56 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"

/*
**	get_arena:
**	Returns a pointer to the arena, which is allocated in static. If it is not
**	initialized, it clears the memory with fT_bzero();
*/

uchar				*get_arena(void)
{
	static uchar	arena[MEM_SIZE];

	return (arena);
}

/*
**	write_reg:
**	Wites the string passed as par.value in the specified address
*/

void				write_memory(t_addr pc, t_addr address, t_par par)
{
	int				i;
	uchar			*arena;

	arena = get_arena();
	while (par.size--)
	{
		i = (pc + (((address - pc) + par.size) % IDX_MOD)) % MEM_SIZE;
		arena[i] = (uchar)(par.value & 0xFF);
		par.value >>= 8;
	}
}

/*
**	read_memory:
**	Returns a string (malloc) with a copy of whats written in memory.
**	DONT FORGET TO FREE after read_memory;
*/

uchar				*read_memory(int address, int size)
{
	uchar			*arena;
	uchar			*reg;

	arena = get_arena();
	if (!(reg = (uchar *)ft_memalloc(sizeof(uchar) * (size + 1))))
		return (NULL);
	reg[--size] = arena[0];
	while (size-- >= 0)
	{
		reg[size] = arena[address];
		ft_printf("%rgb%.2x%0rgb ", 0x0099FF, reg[size]);
		++address == MEM_SIZE ? address = 0 : 0;
	}
	return (reg);
}

/*
**	print_memory:
**	Writes a piece of the arena in stdout.
*/

void				print_memory(int address, int size)
{
	uchar			*arena;
	int				i;

	arena = get_arena();
	i = 0;
	while (size)
	{
		if (arena[address] != 0)
			ft_printf("%rgb%.2x%0rgb ", 0x0099FF, arena[address]);
		else
			ft_printf("%rgb00%0rgb ", 0x0000FF);
		i++ % 64 == 63 ? ft_putchar('\n') : 0;
		++address == MEM_SIZE ? address = 0 : 0;
		size--;
	}
	ft_putchar('\n');
}

/*
**	print_arena:
**	Writes the arena content in stdout.
*/

void				print_arena(void)
{
	uchar			*arena;
	int				i;

	i = -1;
	arena = get_arena();
	while (++i < MEM_SIZE)
	{
		if (arena[i] != 0)
			ft_printf("%rgb%.2x%0rgb ", 0x0099FF, arena[i]);
		else
			ft_printf("%rgb00%0rgb ", 0x0000FF);
		i % 64 == 63 ? ft_putchar('\n') : 0;
	}
}
