/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:44:22 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/11 16:36:50 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void				error(int errcode, char const *const errmsg, char *errtype,
						int errexit)
{
	ft_dprintf(2, "%s (ERRCODE=%d, ERRMSG=\"%s\")\n", errtype, errcode, errmsg);
	if (errexit)
	{
		SDL_Quit();
		exit(1);
	}
}
