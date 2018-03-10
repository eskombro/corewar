/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 02:02:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/10 06:45:00 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./args.h"

static void		default_arg(t_args *args, char *arg)
{
	t_llist		*new;
	char		*dup;

	if (!(dup = ft_strdup(arg)))
		exit(1);
	if (!(new = ft_llist_new(dup)))
		exit(1);
	args->default_count++;
	ft_llist_back(&args->default_data, new);
}

static void		push_arg_data(t_arg *arg, char const *data)
{
	char		*dup;

	if (!(dup = ft_strdup(data)))
		exit(1);
	arg->data[arg->data_len - arg->data_count] = dup;
}

static int		select_arg(t_args *args, t_arg **arg, char const *arg_name)
{
	t_llist		*list;
	int			shortcut;
	int			args_count;
	int			count;
	t_arg		*tmp;

	shortcut = *arg_name == '-' ? 0 : 1;
	args_count = shortcut ? ft_strlen(arg_name) : 1;
	if (*arg && (*arg)->data_count)
		return (0);
	count = -1;
	while (++count < args_count)
	{
		list = args->args;
		while (list)
		{
			tmp = (t_arg *)list->data;
			if ((!shortcut && ft_strequ(arg_name + 1, tmp->name)) ||
				(shortcut && tmp->shortcut &&
				*(arg_name + count) == tmp->shortcut))
			{
				if (tmp->data_len && args_count > 1)
					return (0);
				if (tmp->set && tmp->data_len)
					return (0);
				*arg = tmp;
				tmp->set = 1;
				if (count >= args_count - 1)
					return (1);
			}
			list = list->next;
		}
	}
	return (0);
}

int				ft_args_parse(void *args_ptr, int argc, char **argv)
{
	t_args		*args;
	t_arg		*last_arg;
	int			i;

	args = (t_args *)args_ptr;
	if (args->parsed)
		return (0);
	args->parsed = 1;
	i = 0;
	while (++i < argc)
	{
		if (*(argv[i]) != '-')
		{
			if (last_arg && last_arg->data_count)
			{
				push_arg_data(last_arg, argv[i]);
				last_arg->data_count--;
			}
			else
				default_arg(args, argv[i]);
		}
		else
		{
			ft_printf("testing %s\n", argv[i]);
			if (!select_arg(args, &last_arg, argv[i] + 1))
				return (0);
		}
	}
	if (last_arg && last_arg->data_count)
		return (0);
	return (1);
}
