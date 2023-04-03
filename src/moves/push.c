/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:59:26 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/18 14:44:28 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stackdata *data)
{
	t_stack	*temp;

	if (data->b != NULL)
	{
		temp = pop_head(&data->b);
		if (data->a == NULL)
			data->a = temp;
		else
		{
			temp->next = data->a;
			data->a = temp;
		}
		data->a_len++;
		data->b_len--;
		ft_printf("pa\n");
	}
}

void	pb(t_stackdata *data)
{
	t_stack	*temp;

	if (data->a != NULL)
	{
		temp = pop_head(&data->a);
		if (data->b == NULL)
			data->b = temp;
		else
		{
			temp->next = data->b;
			data->b = temp;
		}
		data->a_len--;
		data->b_len++;
		ft_printf("pb\n");
	}
}
