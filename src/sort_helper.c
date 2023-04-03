/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:42:14 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/03 14:19:36 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

int	ft_sqrt(int nbr)
{
	float	sqrt;
	float	temp;

	sqrt = nbr / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nbr / temp + temp) / 2;
	}
	return ((int)sqrt);
}

int	calculate_distance(t_stack *head, t_stack *node, int len)
{
	int	dist;

	if (find_index(head, node->num) < len / 2)
		dist = find_index(head, node->num);
	else
		dist = len - find_index(head, node->num);
	return (dist);
}

void	move_to_top(t_stackdata *data, t_stack **head, t_stack *node, int len)
{
	void	(*func_ptr)(t_stackdata *, int);

	if (*head == data->a && find_index(*head, node->num) < (len / 2))
		func_ptr = &ra;
	else if (*head == data->a)
		func_ptr = &rra;
	else if (*head == data->b && find_index(*head, node->num) < (len / 2))
		func_ptr = &rb;
	else if (*head == data->b)
		func_ptr = &rrb;
	while (find_index(*head, node->num) != 0)
		func_ptr(data, 1);
}
