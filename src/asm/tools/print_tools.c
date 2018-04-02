/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 02:32:22 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/02 02:40:22 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

int		print_champ_path(char *path, char *origin)
{
	if (!path)
		ft_printf("Error on champ : %s\n", origin);
	else if (path)
		ft_printf("Error on champ : %s\n", path + 1);
	return (0);
}
