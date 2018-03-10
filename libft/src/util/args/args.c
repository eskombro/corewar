/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 01:44:58 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/10 06:23:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./args.h"

static void		del_arg(void *ptr)
{
	t_arg		*arg;

	arg = (t_arg *)ptr;
	if (!arg)
		return ;
	free(arg->name);
	ft_chartabfree(arg->data);
	free(arg);
}

void			*ft_args_new(void)
{
	t_args		*args;

	if (!(args = (t_args *)ft_memalloc(sizeof(t_args))))
		return (NULL);
	return (args);
}

void			ft_args_del(void *args)
{
	if (args)
	{
		ft_llist_del(&((t_args *)args)->args, &del_arg);
		ft_llist_del(&((t_args *)args)->default_data, &free);
	}
}


void			ft_args_add(void *args, char const *name, char shortcut,
							int data_len)
{
	t_arg		*arg;
	t_llist		*new;

	if (!(arg = (t_arg *)ft_memalloc(sizeof(t_arg))))
		exit(1);
	if (!(arg->data = (char **)ft_memalloc(sizeof(char *) * (data_len + 1))))
		exit(1);
	if (!(arg->name = ft_strdup(name)))
		exit(1);
	arg->shortcut = shortcut;
	arg->data_len = data_len;
	arg->data_count = data_len;
	if (!(new = ft_llist_new(arg)))
		exit(1);
	ft_llist_front(&((t_args *)args)->args, new);
}

char			**ft_args_default(void *ptr)
{
	t_args		*args;
	char		**default_args;
	t_llist		*data;
	int			i;

	args = (t_args *)ptr;
	if (!args || !(default_args = (char **)ft_memalloc(
		sizeof(char *) * (args->default_count + 1))))
		exit(1);
	data = args->default_data;
	if (!data)
		return (NULL);
	i = -1;
	while (++i < args->default_count)
	{
		if (!(default_args[i] = ft_strdup((char *)data->data)))
			exit(1);
		data = data->next;
	}
	return (default_args);
}
