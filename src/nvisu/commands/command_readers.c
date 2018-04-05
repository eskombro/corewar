/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_readers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:14:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/01 22:46:13 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

short			read_short(unsigned char *buf)
{
	short		result;

	result = 0;
	result |= (((short)buf[0]) << 8);
	result |= (((short)buf[1]));
	return (result);
}

int				read_int(unsigned char *buf)
{
	int			result;

	result = 0;
	result |= (((int)buf[0]) << 24);
	result |= (((int)buf[1]) << 16);
	result |= (((int)buf[2]) << 8);
	result |= (((int)buf[3]));
	return (result);
}

char			*read_str(unsigned char *buf, unsigned int size)
{
	char		*result;

	if (!(result = ft_strnew(size)))
		exit(1);
	ft_memcpy(result, buf, size);
	return (result);
}
