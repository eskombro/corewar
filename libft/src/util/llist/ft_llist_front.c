/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 01:32:33 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/14 01:34:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_llist_front(t_llist **head, t_llist *new)
{
	new->next = *head;
	*head = new;
}
