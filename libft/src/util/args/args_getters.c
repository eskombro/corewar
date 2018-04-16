/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:39:28 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 23:04:58 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./args.h"

/*
** Returns a duplicate of the given argument data.
**
** [ Args ]	args: a pointer to the concerned args instance
**			name: argument to seek for
** [Return]	An array of char * with all the data set for this argument.
*/

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

/*
** Returns an int to indicate wether the given parameter has been set or not.
**
** [ Args ]	args: a pointer to the concerned args instance
**			name: argument to seek for
** [Return]	Status 1 if set, 0 if not set.
*/

int				ft_args_get(void *args, char *name)
{
	t_llist		*args_list;
	t_arg		*arg;

	args_list = ((t_args *)args)->args;
	while (args_list)
	{
		arg = (t_arg *)args_list->data;
		if (ft_strequ(arg->name, name) && arg->set)
			return (1);
		args_list = args_list->next;
	}
	return (0);
}
