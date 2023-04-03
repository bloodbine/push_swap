/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:59:32 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/03 14:17:13 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stackdata *data, int print)
{
	t_stack	*last;

	if (data->a != NULL && data->a->next != NULL)
	{
		last = pop_tail(&data->a);
		last->next = data->a;
		data->a = last;
		if (print == 1)
			ft_printf("rra\n");
	}
}

void	rrb(t_stackdata *data, int print)
{
	t_stack	*last;

	if (data->b != NULL && data->b->next != NULL)
	{
		last = pop_tail(&data->b);
		last->next = data->b;
		data->b = last;
		if (print == 1)
			ft_printf("rrb\n");
	}
}

void	rrr(t_stackdata *data)
{
	rra(data, 0);
	rrb(data, 0);
	ft_printf("rrr\n");
}
