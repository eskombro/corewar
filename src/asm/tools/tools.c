/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:57:57 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/07 01:38:02 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

char		*get_name(char **name, char *champ)
{
	char *tmp;

	tmp = champ;
	tmp = ft_strchr(tmp, '"');
	tmp++;
	*name = tmp;
	tmp = ft_strchr(tmp, '"');
	*tmp = '\0';
	tmp++;
	return (tmp);
}

char		*get_comment(char *comment)
{
	char *tmp;

	tmp = comment;
	tmp = ft_strchr(tmp, '"');
	tmp++;
	*ft_strchr(tmp, '"') = '\0';
	return (tmp);
}

int			is_asm(char *path)
{
	if (ft_strequ(".s", ft_strrchr(path, '.')) &&
			ft_strlen(ft_strrchr(path, '.')) == 2)
		return (1);
	else
		return (0);
}

int			noccur_count(char *str, char c, char d)
{
	int i;

	i = 0;
	while (*str && *str != d && *str != COMMENT_CHAR)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int			occur_count(char *str, char c)
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
