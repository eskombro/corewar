/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:24:19 by dhigelin          #+#    #+#             */
/*   Updated: 2018/03/13 17:36:27 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar.h"
#include "../../libft/inc/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int			analyse_line(char *line)
{
	line = NULL;
	return (1);
}

void		error()
{
	write(1, "Error\n", 6);
	exit(1);
}

/*
**			renaming champion name from .s to .cor
**			don't forget to free the returned name
*/
char		*rename_champion(char *name)
{
	char	*tmp;

	if (!(tmp = (char*)ft_memalloc(ft_strlen(name) + 3)))
		return (NULL);
	ft_memcpy(tmp, name, ft_strlen(name) - 1);
	ft_memcpy(tmp + ft_strlen(tmp), "cor", 3);
	return (tmp);
}

char		*fill_buffer(char **buff)
{
	return (NULL);
}

int			main (int argc, char **argv)
{
	int		fd;
	int		champion_fd;
	char	*champion_name;
	char	*line;
	char	*buff;

	line = NULL;
	if (argc == 2)
	{
		if (!(champion_name = rename_champion(argv[1])))
			error();
		fd = open(argv[1], O_RDONLY);
		champion_fd = open(champion_name, O_CREAT);
		if (fd < 0 || champion_fd < 0)
			error();
		while (ft_gnl(fd, &line))
		{
			if (!analyse_line(line))
				error();
			free(line);
		}
		ft_printf("Writing output program to %s\n", champion_name);
		close(fd);
		close(champion_fd);
	}
	else
		error();
	return (1);
}