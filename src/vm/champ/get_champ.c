/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <bacrozat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 22:19:27 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/17 01:59:40 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "asm.h"

static int	get_bin_champ(int size, int fd, t_champ *champ)
{
	char	*champion;
	char	buf[INT_SIZE];
	int		ret;

	if (!(champion = (char *)malloc(sizeof(char) * (size + 1))))
		exit(1);
	if ((read(fd, buf, INT_SIZE)) <= 0)
		return (error_msg(3) | end_free(champion, NULL, NULL));
	if (*(int*)buf)
		return (error_msg(7) | end_free(champion, NULL, NULL));
	champ->size = size;
	ret = read(fd, champion, size);
	if (ret <= 0)
		return (error_msg(3) | end_free(champion, NULL, NULL));
	champ->champion = champion;
	champ->champion[size] = '\0';
	if (ret < size)
		return (error_msg(8));
	ret = read(fd, buf, INT_SIZE);
	if (ret < 0)
		return (error_msg(3));
	if (ret > 0)
		return (error_msg(9));
	return (1);
}

static long	get_com(int fd, t_champ *champ)
{
	char	buf[COMMENT_LENGTH + 1];
	char	buf_int[INT_SIZE];
	int		champ_size;

	if ((read(fd, buf_int, INT_SIZE)) <= 0)
		return (error_msg(3));
	if (*(int*)buf_int)
		return (error_msg(5));
	if ((read(fd, buf_int, INT_SIZE)) <= 0)
		return (error_msg(3));
	if ((read(fd, buf, COMMENT_LENGTH)) <= 0)
		return (error_msg(3));
	buf[COMMENT_LENGTH] = '\0';
	champ_size = convert_int_endian(*(int*)buf_int);
	if (!(champ->comment = ft_strdup(buf)))
		exit(1);
	if (champ_size > CHAMP_MAX_SIZE)
		return (error_msg(6));
	if (!get_bin_champ(champ_size, fd, champ))
		return (0);
	return (champ_size);
}

static int	open_champ(char *path, t_champ *champ)
{
	char	buf[INT_SIZE];
	char	buf2[PROG_NAME_LENGTH + 1];
	int		fd;
	int		parse;

	if (!(fd = open(path, O_RDONLY)))
		return (error_msg(1));
	if (is_asm(path))
		return (convert_to_hex(path, champ));
	if (fd < 0)
		return (error_msg(2));
	if ((read(fd, buf, INT_SIZE)) <= 0)
		return (error_msg(3));
	parse = convert_int_endian(*(int*)buf);
	if (parse != COREWAR_EXEC_MAGIC)
		return (error_msg(4));
	if ((read(fd, buf2, PROG_NAME_LENGTH)) <= 0)
		return (error_msg(3));
	buf2[PROG_NAME_LENGTH] = '\0';
	if (!(champ->name = ft_strdup(buf2)))
		exit(1);
	if (!get_com(fd, champ))
		return (0);
	return (1);
}

t_champ		*get_all_champ(char **jcvd)
{
	int			i;
	t_champ		*champs;

	i = 0;
	if (!(champs = (t_champ *)ft_memalloc(sizeof(t_champ) *
					(ft_chartablen(jcvd) + 1))))
		return (NULL);
	while (*jcvd)
	{
		if (i >= MAX_CHAMPS)
		{
			ft_dprintf(2, "%rgbToo Many Champions%0rgb\n", 0xff0000);
			return (free_champs(champs));
		}
		champs[i].fixed_id = i + 1;
		champs[i].id = -i - 1;
		champs[i].name = NULL;
		if (!open_champ(*jcvd, champs + i))
			return (free_champs(champs));
		i++;
		jcvd++;
	}
	return (champs);
}
