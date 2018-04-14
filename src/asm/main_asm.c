/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bacrozat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:14:37 by bacrozat          #+#    #+#             */
/*   Updated: 2018/04/06 22:29:23 by bacrozat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

static int	get_bin_champ(int size, int fd, t_bin_champ *champ)
{
	char	*champion;
	char	buf[INT_SIZE];
	int		ret;

	if (!(champion = (char *)malloc(sizeof(char) * (size + 1))))
		exit(1);
	if ((read(fd, buf, INT_SIZE)) <= 0)
		return (error_msg(3));
	if (*(int*)buf)
		return (error_msg(7));
	champ->size = size;
	ret = read(fd, champion, size);
	if (ret <= 0)
		return (error_msg(3));
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

static long	get_com(int fd, t_bin_champ *champ)
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
	champ->comment = ft_strdup(buf);
	if (!get_bin_champ(champ_size, fd, champ))
		return (0);
	return (champ_size);
}

static int	open_champ(char *path, t_bin_champ *champ)
{
	char	buf[INT_SIZE];
	char	buf2[PROG_NAME_LENGTH + 1];
	int		fd;
	int		parse;

	if (!(fd = open(path, O_RDONLY)))
		return (error_msg(1));
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
	champ->name = ft_strdup(buf2);
	if (!get_com(fd, champ))
		return (0);
	return (1);
}

int			get_champ(char *champ_path)
{
	int			fd;
	char		*mod;
	t_bin_champ	champs;

	if (!open_champ(champ_path, &champs))
		return (print_champ_path(ft_strrchr(champ_path, '/'), champ_path));
	mod = ft_strrchr(champ_path, '.');
	mod[1] = 's';
	mod[2] = '\0';
	if ((fd = open(champ_path, O_RDWR | O_CREAT, 0644)) < 0)
		return (0);
	get_all_instr(&champs, fd);
	close(fd);
	return (1);
}

int			main(int argc, char *argv[])
{
	int i;
	int fd;

	i = 1;
	while (argv[i])
	{
		if ((fd = open(argv[i], O_RDONLY)) >= 0)
		{
			if (ft_strequ(".cor", ft_strrchr(argv[i], '.')) &&
					ft_strlen(ft_strrchr(argv[i], '.')) == 4)
				get_champ(argv[i]);
			else if (ft_strequ(".s", ft_strrchr(argv[i], '.')) &&
					ft_strlen(ft_strrchr(argv[i], '.')) == 2)
				convert_champ(argv[i], 0, NULL, NULL);
			else
				error_msg_instr(6, i);
		}
		else
			error_msg_instr(5, i);
		close(fd);
		i++;
	}
	return (0);
}
