/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llabel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhigelin <dhigelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:45:25 by dhigelin          #+#    #+#             */
/*   Updated: 2018/03/13 19:18:55 by dhigelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			put the new label to the head of the list and return the new head
*/
t_llabel	*add_label(t_llabel *head, char *name, char *address)
{
	t_llabel	*tmp;

	if (!(tmp = (t_llabel*)malloc(sizeof(t_llabel))))
		return (NULL);
	tmp->name = ft_strdup(name);
	tmp->address = ft_strdup(address);
	if (!tmp->address || !tmp->name)
		return (NULL);
	if (!head)
		tmp->next = NULL;
	else
		tmp->next = head;
	return (tmp);
}

/*
**		free the label list
*/
void	free_llabel(t_llabel **head)
{
	t_llabel *tmp;

	if (head)
	{
		while (*head)
		{
			tmp = *head;
			head = tmp->next;
			free(tmp->name);
			free(tmp->address);
			free(tmp);
		}
		*head = NULL;
	}
}