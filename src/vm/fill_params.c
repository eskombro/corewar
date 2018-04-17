/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:28:22 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/17 16:35:40 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void				fill_params_norm(void *args, t_params *params)
{
	char				**tmp;
	
	if (ft_args_get(args, "id"))
	{
		if (!(tmp = ft_args_data(args, "id")))
			exit(1);
		if (!(params->ids = ft_strdup(*tmp)))
			exit(1);
		ft_chartabfree(tmp);
	}
	if (ft_args_get(args, "commands"))
		params->command_io = 1;
}

void					fill_params(void *args, t_params *params)
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
	fill_params_norm(args, params);
}
