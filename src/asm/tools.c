/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:57:57 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/29 02:47:32 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			convert_int_endian(int num)
{
	unsigned int swapped;

	swapped = ((num >> 24) & 0xff) |
		((num << 8) & 0xff0000) |
		((num >> 8) & 0xff00) |
		((num << 24) & 0xff000000);
	return (swapped);
}

int	occur_count(char *str, char c)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

long		ft_long_atoi(char *str)
{
	int		i;
	long	nb;
	int		op;

	op = 1;
	i = 0;
	nb = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			op = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		nb = nb * 10 + (str[i++] - '0');
	return (nb * op);
}
