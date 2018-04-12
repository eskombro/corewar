/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 04:26:03 by hbouillo          #+#    #+#             */
/*   Updated: 2018/04/12 15:33:46 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./display.h"

void			set_display_grid_color(void *component, t_color color)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	display->grid_00 = color;
}

void			set_display_ocolor(void *component, t_color color)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	display->ocolor = color;
}

void			set_display_player_color(int n, void *component, t_color color)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	if (n == 1)
		display->p1 = color;
	if (n == 2)
		display->p2 = color;
	if (n == 3)
		display->p3 = color;
	if (n == 4)
		display->p4 = color;
}

void			set_display_edge(void *component, int edge)
{
	t_display	*display;

	display = (t_display *)sg_get_component_data(component);
	display->edge = edge;
}
