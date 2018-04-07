/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 01:07:37 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/07 01:14:33 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void			send_command_event(t_command *command)
{
	t_command		*to_send;

	to_send = ft_memalloc(sizeof(t_command));
	ft_memcpy(to_send, command, sizeof(t_command));
	push_user_event(COREWAR_EVENT_COMMAND, to_send, NULL);
}

int					read_command(void)
{
	t_command		command;
	t_uchar			c[2];
	int				ret;

	bzero(&command, sizeof(t_command));
	if ((ret = read(0, c, 1)) > 0)
	{
		command.type = c[0];
		ret = read(0, c, 2);
		if (ret != 2)
			return (-1);
		command.size = read_short(c);
		ret = read(0, command.data, command.size);
		if (ret != command.size)
			return (-1);
		//debug_command(command);
		send_command_event(&command);
	}
	else
		return (-1);
	return (command.type == COMMAND_LOGIC_CYCLE ? 1 : 0);
}

static void			*start_read(void *arg)
{
	t_visu			*visu;
	t_time			last_time;
	t_time			current_time;
	unsigned long	delta;
	int				ret;

	visu = (t_visu *)arg;
	clock_gettime(CLOCK_MONOTONIC_RAW, &last_time);
	pthread_mutex_lock(&visu->run_mutex);
	while (visu->run)
	{
		pthread_mutex_unlock(&visu->run_mutex);
		clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
		delta = (current_time.tv_sec - last_time.tv_sec) * 1000000000 +
				current_time.tv_nsec - last_time.tv_nsec;
		if (delta > 1000000000 / FRAME_PER_SECOND)
		{
			if ((ret = read_command()) == -1)
				break;
			else if (ret == 1)
				last_time = current_time;
		}
		pthread_mutex_lock(&visu->run_mutex);
	}
	pthread_mutex_unlock(&visu->run_mutex);
	return (NULL);
}

pthread_t			run_read(t_visu *visu)
{
	pthread_t		read_thread;

	pthread_create(&read_thread, NULL, &start_read, visu);
	return (read_thread);
}