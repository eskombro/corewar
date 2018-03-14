/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 23:10:48 by sjimenez          #+#    #+#             */
/*   Updated: 2018/03/14 15:14:34 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		test_write_memory(t_par par)
{
	ft_printf("\nWrite mem: write_memory(20, -10, par);\n");
	write_memory(20, -10, par);
	ft_printf("\nWrite mem: write_memory(0, 5, par);\n");
	write_memory(0, 5, par);
	ft_printf("\nWrite mem: write_memory(MEM_SIZE - 2,MEM_SIZE - 2, par);\n");
	write_memory(MEM_SIZE - 2, MEM_SIZE, par);
	ft_printf("\nPrint arena:\n");
	print_arena();
}

void		test_read_memory()
{
	int				i;
	unsigned char	ustr[5000];
	int				len;

	ft_printf("\nRead memory (and printf): 0, 11\n");
	i = -1;
	len = 11;
	ft_memcpy(ustr, read_memory(0, len), len);
	while (++i < len)
		ft_printf("%rgb%.2x%0rgb ", 0x00CC99, ustr[i]);
	ft_putchar('\n');
	ft_bzero((char*)ustr, len);
	ft_printf("\nRead memory (and printf): MEM_SIZE - 2, 16\n");
	i = -1;
	len = 16;
	ft_memcpy(ustr, read_memory(MEM_SIZE - 2, len), len);
	while (++i < len)
		ft_printf("%rgb%.2x%0rgb ", 0x00CC99, ustr[i]);
	ft_bzero((char*)ustr, len);
	ft_putchar('\n');
}

int			main(void)
{
	t_par			par;

	par.size = 3;
	par.value = 0xABCDEF;
	ft_printf("Print arena:\n");
	print_arena();
	test_write_memory(par);
	ft_printf("\nPrint memory: 0, 10\n");
	print_memory(0, 10);
	ft_printf("\nPrint memory: MEM_SIZE -2, 20\n");
	print_memory(MEM_SIZE - 2, 20);
	ft_printf("\nPrint memory: 0, 128\n");
	print_memory(0, 128);
	test_read_memory();
	return (0);
}