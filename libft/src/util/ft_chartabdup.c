/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartabdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:17:08 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/10 19:47:40 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_chartabdup(char **tab)
{
	char	**dup;
	int		len;

	len = ft_chartablen(tab);
	if (!tab)
		return (NULL);
	if (!(dup = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (len--)
	{
		if (!(dup[len] = ft_strdup(tab[len])))
			return (NULL);
	}
	return (dup);
}
