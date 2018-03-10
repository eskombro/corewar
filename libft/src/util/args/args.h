/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 01:52:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/10 05:39:18 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "./libft.h"

typedef struct		s_args
{
	int				parsed;
	t_llist			*args;
	int				default_count;
	t_llist			*default_data;
}					t_args;

typedef struct		s_arg
{
	int				set;
	char			*name;
	char			shortcut;
	int				data_len;
	int				data_count;
	char			**data;
}					t_arg;

#endif
