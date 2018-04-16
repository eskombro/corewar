/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:57:57 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/16 21:33:03 by bacrozat         ###   ########.fr       */
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
	*name = ft_strdup(*name);
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
