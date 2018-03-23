/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:16:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/23 23:26:38 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void				run_corewar(void)
{
	t_champ				*champions;
	int					i;
	t_params			params;

	params = get_params();
	if (!(champions = get_all_champ(params.champs_files)))
		exit(1);
	calc_spawn(params.players, champions);
	i = -1;
	while (++i < params.players)
		write_champ(champions + i);
	run_loop(champions);
	ft_chartabfree(params.champs_files);
	free(champions);
}

static void				*init_args(int argc, char **argv)
{
	static void			*args;

	if (!args)
	{
		if (argc <= 1)
			return (NULL);
		if (!(args = ft_args_new()))
			return (NULL);
		if (ft_args_add(args, "dump", 'd', 1))
			return (NULL);
		if (ft_args_add(args, "verbose", 'v', 1))
			return (NULL);
		if (ft_args_add(args, "ncurse", 'n', 0))
			return (NULL);
		if (ft_args_parse(args, argc, argv))
			return (NULL);
	}
	return (args);
}

static void				fill_params(void *args, t_params *params)
{
	char				**tmp;

	if (!(params->champs_files = ft_args_default(args)))
		exit(1);
	params->players = ft_chartablen(params->champs_files);
	if (ft_args_get(args, "dump"))
	{
		if (!(tmp = ft_args_data(args, "dump")))
			exit(1);
		params->dump = ft_atoi(*tmp);
		ft_chartabfree(tmp);
	}
	if (ft_args_get(args, "verbose"))
	{
		if (!(tmp = ft_args_data(args, "verbose")))
			exit(1);
		params->verbose = ft_atoi(*tmp);
		ft_chartabfree(tmp);
	}
	if (ft_args_get(args, "ncurse"))
		params->ncurse = 1;
}

t_params				get_params(void)
{
	static void			*args;
	static t_params		params;

	if (!args)
	{
		args = init_args(0, NULL);
		params.dump = -1;
		params.verbose = -1;
		params.ncurse = 0;
		fill_params(args, &params);
		free(args);
	}
	return (params);
}

int						main(int argc, char **argv)
{
	if (!init_args(argc, argv))
		return (1);
	run_corewar();
	return (0);
}
