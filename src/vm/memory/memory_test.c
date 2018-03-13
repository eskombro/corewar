/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 23:10:48 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/12 18:15:54 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		test_write_memory(unsigned char *arena, t_par par)
{
	ft_printf("\nWrite mem: write_memory(10, 520, par);\n");
	write_memory(10, 520, par);
	ft_printf("\nPrint arena:\n");
	print_arena();
	ft_printf("\nWrite mem: write_memory(MEM_SIZE - 2,MEM_SIZE - 2, par);\n");
	write_memory(MEM_SIZE - 2, MEM_SIZE - 2, par);
	ft_printf("\nPrint arena:\n");
	print_arena();
}

void		test_read_memory(unsigned char *arena, t_par par)
{
	int				i;
	unsigned char	ustr[500];
	int				len;

	ft_printf("\nRead memory (and printf): 0, 11\n");
	i = -1;
	len = 11;
	ft_memcpy(ustr, read_memory(0, len), len);
	while (++i < len)
		ft_printf("%rgb%.2x%0rgb ", 0x0099FF, ustr[i]);
	ft_putchar('\n');
	ft_bzero((char*)ustr, len);
	ft_printf("\nRead memory (and printf): MEM_SIZE - 2, 16\n");
	i = -1;
	len = 16;
	ft_memcpy(ustr, read_memory(MEM_SIZE - 2, len), len);
	while (++i < len)
		ft_printf("%rgb%.2x%0rgb ", 0x0099FF, ustr[i]);
	ft_bzero((char*)ustr, len);
	ft_putchar('\n');
}

int			main(void)
{
	unsigned char	*arena;
	t_par			par;

	par.size = 3;
	par.value = 0xABCDEF;
	arena = get_arena();
	ft_printf("Print arena:\n");
	print_arena();
	test_write_memory(arena, par);
	ft_printf("\nPrint memory: 0, 10\n");
	print_memory(0, 10);
	ft_printf("\nPrint memory: MEM_SIZE -2, 20\n");
	print_memory(MEM_SIZE - 2, 20);
	ft_printf("\nPrint memory: 0, 128\n");
	print_memory(0, 128);
	test_read_memory(arena, par);
	return (0);
}
