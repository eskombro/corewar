/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:16:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/17 16:31:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void				run_corewar(void)
{
	t_champ				*champions;
	int					i;
	t_params			params;

	params = get_params();
	get_logic()->params = params;
	if (!(champions = get_all_champ(params.champs_files)))
		return ;
	if (params.ids)
		get_champnbr(champions, params.ids);
	calc_spawn(params.players, champions);
	i = -1;
	while (++i < params.players)
		write_champ(champions + i);
	call_core_begin();
	run_loop(champions);
	free_champs(champions);
	call_core_end();
	ft_chartabfree(params.champs_files);
	if (params.ids)
		free(params.ids);
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
		if (ft_args_add(args, "commands", 'c', 0))
			return (NULL);
		if (ft_args_add(args, "id", 'n', 1))
			return (NULL);
		if (ft_args_parse(args, argc, argv))
			return (NULL);
	}
	return (args);
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
		params.command_io = 0;
		fill_params(args, &params);
		ft_args_del(init_args(0, NULL));
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
