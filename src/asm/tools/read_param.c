/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 02:02:58 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/07 02:36:52 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

long		ft_atoi_hex(char *str)
{
	long nb;
	char *base;
	char *ret;

	base = "0123456789abcdef";
	nb = 0ll;
	while (*str != 'x')
		str++;
	str++;
	while (*str == '0')
		str++;
	while (*str && (ret = ft_strchr(base, *str)))
	{
		nb = nb * 16 + ret - base;
		str++;
	}
	return (nb);
}

long		ft_long_atoi(char *str)
{
	int		i;
	long	nb;
	int		op;

	op = 1;
	i = 0;
	nb = 0;
	if (ft_strstr(str, "0x"))
		return (ft_atoi_hex(str));
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

void		jump_white_spaces(char **src)
{
	char *tmp;

	tmp = *src;
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	*src = tmp;
}
