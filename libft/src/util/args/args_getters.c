/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:39:28 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/10 22:07:17 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./args.h"

char			**ft_args_data(void *args, char *name)
{
	t_llist		*args_list;
	t_arg		*arg;

	args_list = ((t_args *)args)->args;
	while (args_list)
	{
		arg = (t_arg *)args_list->data;
		if (ft_strequ(arg->name, name))
			return (ft_chartabdup(arg->data));
		args_list = args_list->next;
	}
	return (NULL);
}
