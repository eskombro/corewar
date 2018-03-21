/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:16:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/21 02:24:54 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		run_corewar(char **champ_files, int dump, int verbose, int visu)
{
	t_champ		*champions;
	int			amount;
	int			i;

	amount = ft_chartablen(champ_files);
	if (!(champions = get_all_champ(champ_files)))
		exit(1);
	calc_spawn(amount, champions);
	ft_chartabfree(champ_files);
	//ft_printf("%d champions loaded.\n", amount);
	i = -1;
	while (++i < amount)
		write_champ(champions + i);
	run_loop(champions, amount, dump, verbose, visu);
	free(champions);
}

int				main(int argc, char **argv)
{
	void		*args;
	char		**champ_files;
	char		**tmp;
	int			dump;
	int			verbose;
	int			visu;

	dump = -1;
	verbose = -1;
	visu = 0;
	if (argc <= 1)
		return (1);
	if (!(args = ft_args_new()))
		return (1);
	if (ft_args_add(args, "dump", 'd', 1))
		return (1);
	if (ft_args_add(args, "verbose", 'v', 1))
		return (1);
	if (ft_args_add(args, "visu", 'n', 0))
		return (1);
	if (ft_args_parse(args, argc, argv))
		return (1);
	if (!(champ_files = ft_args_default(args)))
		return (1);
	if (ft_args_get(args, "dump"))
	{
		if (!(tmp = ft_args_data(args, "dump")))
			return (1);
		dump = ft_atoi(*tmp);
		ft_chartabfree(tmp);
	}
	if (ft_args_get(args, "verbose"))
	{
		if (!(tmp = ft_args_data(args, "verbose")))
			return (1);
		verbose = ft_atoi(*tmp);
		ft_chartabfree(tmp);
	}
	if (ft_args_get(args, "visu"))
	{
		if (!(tmp = ft_args_data(args, "visu")))
			return (1);
		visu = 1;
		ft_chartabfree(tmp);
	}
	run_corewar(champ_files, dump, verbose, visu);
	return (0);
}
