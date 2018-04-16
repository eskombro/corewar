/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:22:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/26 23:25:59 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strfjoin(char *str1, char *str2)
{
	char	*join;

	if (!str1 || !str2)
		return (NULL);
	if (!(join = ft_strnew(ft_strlen(str1) + ft_strlen(str2))))
		return (NULL);
	ft_strcpy(join, str1);
	ft_strcat(join, str2);
	free(str1);
	free(str2);
	return (join);
}
