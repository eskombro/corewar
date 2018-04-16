/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 02:02:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/16 23:46:21 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./args.h"

static int		default_arg(t_args *args, char *arg)
{
	t_llist		*new;
	char		*dup;

	if (!(dup = ft_strdup(arg)))
		return (1);
	if (!(new = ft_llist_new(dup)))
		return (1);
	args->default_count++;
	ft_llist_back(&args->default_data, new);
	return (0);
}

static int		push_arg_data(t_arg *arg, char const *data)
{
	char		*dup;

	if (!(dup = ft_strdup(data)))
		return (1);
	arg->data[arg->data_len - arg->data_count] = dup;
	return (0);
}

static void		set_select_arg_params(int *shortcut, int *arg_count, int *count,
					char const *arg_name)
{
	*shortcut = *arg_name == '-' ? 0 : 1;
	*arg_count = *shortcut ? ft_strlen(arg_name) : 1;
	*count = -1;
}

static int		select_arg(t_args *args, t_arg **arg, char const *arg_name)
{
	t_llist		*list;
	int			sh;
	int			ac;
	int			count;
	t_arg		*tmp;

	set_select_arg_params(&sh, &ac, &count, arg_name);
	if (*arg && (*arg)->data_count)
		return (1);
	while (++count < ac && (list = args->args))
		while (list && (tmp = (t_arg *)list->data))
		{
			if ((!sh && ft_strequ(arg_name + 1, tmp->name)) ||
				(sh && tmp->shortcut && *(arg_name + count) == tmp->shortcut))
			{
				if ((tmp->data_len && ac > 1) || (tmp->set && tmp->data_len))
					return (1);
				*arg = tmp;
				tmp->set = 1;
				if (count >= ac - 1)
					return (0);
			}
			list = list->next;
		}
	return (1);
}

/*
** Parses the given args instance
**
** [ Args ]	args: a pointer to the concerned args instance
**			argc: argc
**			argv: argv
** [Return]	0: Success; 1: Failure
*/

int				ft_args_parse(void *args_ptr, int argc, char **argv)
{
	t_arg		*last_arg;
	int			i;

	if (((t_args *)args_ptr)->parsed)
		return (1);
	((t_args *)args_ptr)->parsed = 1;
	i = 0;
	last_arg = NULL;
	while (++i < argc)
		if (*(argv[i]) != '-')
		{
			if (last_arg && last_arg->data_count)
			{
				if (push_arg_data(last_arg, argv[i]))
					return (1);
				last_arg->data_count--;
			}
			else if (default_arg((t_args *)args_ptr, argv[i]))
				return (1);
		}
		else if (select_arg((t_args *)args_ptr, &last_arg, argv[i] + 1))
			return (1);
	if (last_arg && last_arg->data_count)
		return (1);
	return (0);
}
