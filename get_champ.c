/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:19:27 by bacrozat          #+#    #+#             */
/*   Updated: 2018/03/11 03:28:42 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/inc/libft.h"
#include "types.h"
#include <unistd.h>
#include <stdio.h>

static int	get_champ(long size, int fd, t_champion *champ)
{
	char	*champion;
	char	buf[4];
	int		ret;

	champion = (char *)malloc(sizeof(char) * size);
	read(fd, buf, 4);
	ret = read(fd, champion, size);
	champion[size] = '\0';
	champ->champion = champion;
	if (ret != size)
		return (0);
	if ((ret = read(fd, buf, 4)))
		return (0);
	return (1);
}

static long	convert_endian(long num)
{
	long swapped;

	swapped = ((num >> 56) & 0xff) |
		((num >> 40) & 0xff00) |
		((num >> 24) & 0xff0000) |
		((num >> 8) & 0xff000000) |
		((num << 8) & 0xff00000000) |
		((num << 24) & 0xff0000000000) |
		((num << 40) & 0xff000000000000) |
		((num << 56) & 0xff00000000000000);
	return (swapped);
}

static long	get_com(int fd, t_champion *champ)
{
	char	buf[2049];
	char	buf2[8];
	long	*champ_size;

	read(fd, buf2, 8);
	read(fd, buf, 2048);
	buf[2048] = '\0';
	champ_size = (long*)buf2;
	*champ_size = convert_endian(*champ_size);
	champ->comment = ft_strdup(buf);
	if (!get_champ(*champ_size, fd, champ))
		return (0);
	return (*champ_size);
}

static int	open_champ(char *path, t_champion *champ)
{
	char	buf[4];
	char	buf2[128];
	int		fd;
	int		*parse;

	if (!(fd = open(path, O_RDONLY)))
		return (0);
	if (fd < 0)
		return (0);
	read(fd, buf, 4);
	parse = (int*)buf;
	if (*parse != -209458688)
		return (0);
	read(fd, buf2, 128);
	champ->name = ft_strdup(buf2);
	if (!get_com(fd, champ))
		return (0);
	return (1);
}

t_champion	*get_all_champ(char **jcvd)
{
	int			i;
	t_champion	*champs;

	i = 0;
	if (!(champs = (t_champion*)malloc(sizeof(t_champion) *
					ft_chartablen(jcvd))))
		return (NULL);
	while (*jcvd)
	{
		champs[i].id = i + 1;
		open_champ(*jcvd, champs + i);
		jcvd++;
	}
	return (champs);
}
