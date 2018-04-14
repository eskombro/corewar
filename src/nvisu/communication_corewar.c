/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communication_corewar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjimenez <sjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 20:14:44 by sjimenez          #+#    #+#             */
/*   Updated: 2018/04/08 00:22:54 by sjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nvisualizer.h"
#include "errno.h"

void			parent(int *to_vm, int *from_vm)
{
	close(0);
	if (dup2(from_vm[0], 0) == -1)
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
		(void)0;
	}
	if (pid)
		parent(to_vm, from_vm);
	else
		child(to_vm, from_vm, argv);
}

void			debug_command(t_command command)
{
	int			i;

	ft_dprintf(2, "[COMMAND] Packet of type 0x%2.2x and size %3d \
octets contains [ ",
		command.type, command.size);
	i = -1;
	while (++i < command.size)
		ft_dprintf(2, "%02.2x ", command.data[i]);
	ft_dprintf(2, "]\n");
}
