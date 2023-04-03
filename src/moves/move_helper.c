/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:24:07 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/19 13:40:32 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*pop_head(t_stack **head)
{
	t_stack	*temp;

	if (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		temp->next = NULL;
		return (temp);
	}
	return (NULL);
}

t_stack	*pop_tail(t_stack **head)
{
	t_stack	*temp;
	t_stack	*tail;

	if (*head != NULL)
	{
		if ((*head)->next == NULL)
		{
			tail = pop_head(head);
			return (tail);
		}
		if ((*head)->next->next == NULL)
		{
			tail = (*head)->next;
			(*head)->next = NULL;
			return (tail);
		}
		temp = *head;
		while (temp->next->next != NULL)
			temp = temp->next;
		tail = temp->next;
		temp->next = NULL;
		return (tail);
	}
	return (NULL);
}
