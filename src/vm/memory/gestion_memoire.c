/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_memoire.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 22:47:20 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/14 22:28:25 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	get_arena:
**	Returns a pointer to the arena, which is allocated in static.
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
	unsigned int	ct;
	uchar			*arena;

	arena = get_arena();
	ct = 0;
	i = par.size - 1 + pc + (address % IDX_MOD);
	while (i < MEM_SIZE)
		i += MEM_SIZE;
	while (ct < par.size)
		arena[i-- % MEM_SIZE] = (uchar)((par.value >> (8 * (ct++))) & 0xFF);
}

/*
**	read_memory:
**	Returns a string (malloc) with a copy of whats written in memory.
**	DONT FORGET TO FREE after read_memory;
*/

uchar				*read_memory(t_addr pc, t_addr address, int size, int mod)
{
	uchar			*arena;
	uchar			*reg;
	int				i;

	arena = get_arena();
	if (!(reg = (uchar *)ft_memalloc(sizeof(uchar) * (size + 1))))
		return (NULL);
	reg[size] = 0;
	i = -1;
	address = (mod ? pc + (address % IDX_MOD) : pc + address);
	while (address < MEM_SIZE)
		address += MEM_SIZE;
	while (++i < size)
		reg[i] = arena[address++ % MEM_SIZE];
	return (reg);
}

/*
**	print_memory:
**	Writes a piece of the arena in stdout.
*/

void				print_memory(t_addr address, int size)
{
	uchar			*arena;
	int				i;

	arena = get_arena();
	i = 0;
	while (size)
	{
		if (arena[address] != 0)
			ft_printf("%rgb%.2x%0rgb ", 0x00CC99, arena[address]);
		else
			ft_printf("%rgb00%0rgb ", 0x0000CC);
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
	int				last;

	i = -1;
	arena = get_arena();
	while (++i < MEM_SIZE)
	{
		if (arena[i] != 0 && last != 1)
		{
			ft_printf("%rgb", 0x00CC99);
			last = 1;
		}
		else if (arena[i] == 0 && last != 0)
		{
			ft_printf("%rgb", 0x0000CC);
			last = 0;
		}
		ft_printf("%.2x ", arena[i]);
		i % 64 == 63 ? ft_putchar('\n') : 0;
	}
	ft_printf("%0rgb");
}
