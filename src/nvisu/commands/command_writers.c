/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_writers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:27:58 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/08 00:22:58 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int				write_char(unsigned char *buf, char val)
{
	buf[0] = (unsigned char)val;
	return (1);
}

int				write_short(unsigned char *buf, short val)
{
	buf[0] = ((val >> 8) & 0xFF);
	buf[1] = (val) & 0xFF;
	return (2);
}

int				write_int(unsigned char *buf, int val)
{
	buf[0] = ((val >> 24) & 0xFF);
	buf[1] = ((val >> 16) & 0xFF);
	buf[2] = ((val >> 8) & 0xFF);
	buf[3] = (val) & 0xFF;
	return (4);
}

int				write_str(unsigned char *buf, char const *val)
{
	ft_memcpy(buf, val, ft_strlen(val));
	return (ft_strlen(val));
}

int				write_buf(unsigned char *buf, char const *val, int size)
{
	ft_memcpy(buf, val, size);
	return (size);
}
