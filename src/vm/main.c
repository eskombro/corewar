/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:16:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/14 17:00:00 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		run_corewar(char **champ_files)
{
	t_champ		*champions;
	int			amount;
	int			i;

	amount = ft_chartablen(champ_files);
	champions = get_all_champ(champ_files);
	calc_spawn(amount, champions);
	ft_chartabfree(champ_files);
	ft_printf("%d champions loaded.\n", amount);
	i = -1;
	while (++i < amount)
		write_champ(champions + i);
	print_arena();
}

int				main(int argc, char **argv)
{
	void		*args;
	char		**champ_files;

	if (argc <= 1)
		return (1);
	if (!(args = ft_args_new()))
		return (1);
	if (ft_args_parse(args, argc, argv))
		return (1);
	if (!(champ_files = ft_args_default(args)))
		return (1);
	run_corewar(champ_files);
	return (0);
}
