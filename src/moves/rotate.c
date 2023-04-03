/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:59:29 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/03 14:18:12 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stackdata *data, int print)
{
	t_stack	*temp;
	t_stack	*moved;

	if (data->a != NULL && data->a->next != NULL)
	{
		moved = pop_head(&data->a);
		temp = data->a;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = moved;
		if (print == 1)
			ft_printf("ra\n");
	}
}

void	rb(t_stackdata *data, int print)
{
	t_stack	*temp;
	t_stack	*moved;

	if (data->b != NULL && data->b->next != NULL)
	{
		moved = pop_head(&data->b);
		temp = data->b;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = moved;
		if (print == 1)
			ft_printf("rb\n");
	}
}

void	rr(t_stackdata *data)
{
	ra(data, 0);
	rb(data, 0);
	ft_printf("rr\n");
}
