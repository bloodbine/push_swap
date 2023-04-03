/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:47:44 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/03 14:18:35 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stackdata *data, int print)
{
	t_stack	*temp;

	if (data->a != NULL && data->a->next != NULL)
	{
		temp = pop_head(&data->a);
		temp->next = data->a->next;
		data->a->next = temp;
		if (print == 1)
			ft_printf("sa\n");
	}
}

void	sb(t_stackdata *data, int print)
{
	t_stack	*temp;

	if (data->b != NULL && data->b->next != NULL)
	{
		temp = pop_head(&data->b);
		temp->next = data->a->next;
		data->a->next = temp;
		if (print == 1)
			ft_printf("sb\n");
	}
}

void	ss(t_stackdata *data)
{
	sa(data, 0);
	sb(data, 0);
	ft_printf("ss\n");
}
