/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_writers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:27:58 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/31 19:34:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				write_short(unsigned char *buf, short val)
{
	buf[0] = ((val >> 8) & 0xFF);
	buf[1] = (val) & 0xFF;
	return (2);
}

int				write_str(unsigned char *buf, char const *val)
{
	ft_memcpy(buf, val, ft_strlen(val));
	return (ft_strlen(val));
}
