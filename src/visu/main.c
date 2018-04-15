/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 00:16:17 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/15 18:23:18 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include "errno.h"

void			parent(int *to_vm, int *from_vm)
{
	close(0);
	close(1);
	if (dup2(from_vm[0], 0) == -1 || dup2(to_vm[1], 1) == -1)
	{
		ft_dprintf(2, "parent dup2 failed (%d).\n", errno);
		exit(1);
	}
	if (close(from_vm[0]) == -1 || close(from_vm[1]) == -1 ||
		close(to_vm[0]) == -1 || close(to_vm[1]) == -1)
		ft_dprintf(2, "parent close failed (%d).\n", errno);
}

void			child(int *to_vm, int *from_vm, char **argv)
{
	close(0);
	close(1);
	if (dup2(to_vm[0], 0) == -1 || dup2(from_vm[1], 1) == -1)
	{
		ft_dprintf(2, "child dup2 failed (%d).\n", errno);
		exit(1);
	}
	if (close(to_vm[0]) == -1 || close(to_vm[1]) == -1 ||
		close(from_vm[0]) == -1 || close(from_vm[1]) == -1)
		ft_dprintf(2, "child close failed (%d).\n", errno);
	argv[0] = argv[1];
	argv[1] = "-c";
	if (execv(argv[0], argv) == -1)
	{
		ft_dprintf(2, "Couldn't execute %s.\n", argv[0]);
		exit(1);
	}
}

void			run_corewar(char **argv)
{
	int			pid;
	int			to_vm[2];
	int			from_vm[2];

	if (pipe(to_vm) == -1 || pipe(from_vm) == -1)
	{
		ft_dprintf(2, "Pipe error (%d).\n", errno);
		exit(1);
	}
	if ((pid = fork()) == -1)
	{
		ft_dprintf(2, "Fork error\n");
	}
	if (pid)
		parent(to_vm, from_vm);
	else
		child(to_vm, from_vm, argv);
}

static void		init_visu(t_visu *visu)
{
	ft_bzero(visu, sizeof(t_visu));
	visu->run = 1;
	visu->mem.new_data = 1;
	visu->tps = CYCLES_PER_SECOND;
	pthread_mutex_init(&(visu->run_mutex), NULL);
}

int				main(int argc, char **argv)
{
	pthread_t	read_thread;
	t_visu		visu;

	init_visu(&visu);
	if (argc < 2)
		return (0);
	run_corewar(argv);
	read_thread = run_read(&visu);
	run_visu(&visu);
	pthread_join(read_thread, NULL);
	return (0);
}
