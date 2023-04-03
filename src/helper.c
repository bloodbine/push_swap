/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:40:04 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/26 14:19:03 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

t_stack	*find_min(t_stack *head)
{
	t_stack	*temp;
	int		min;

	temp = head;
	min = INT_MAX;
	while (temp != NULL)
	{
		if (temp->num < min && temp->bool == 0)
			min = temp->num;
		temp = temp->next;
	}
	temp = head;
	while (temp->num != min)
		temp = temp->next;
	return (temp);
}

t_stack	*find_max(t_stack *head)
{
	t_stack	*temp;
	int		max;

	temp = head;
	max = INT_MIN;
	while (temp != NULL)
	{
		if (temp->num > max && temp->bool == 0)
			max = temp->num;
		temp = temp->next;
	}
	temp = head;
	while (temp->num != max)
		temp = temp->next;
	temp->bool = 1;
	return (temp);
}

int	find_index(t_stack *head, int num)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = head;
	while (temp != NULL)
	{
		if (temp->num == num)
			return (i);
		temp = temp->next;
		i++;
	}
	return (0);
}

void	set_bool(t_stackdata *data)
{
	t_stack	*temp;

	temp = data->a;
	while (temp != NULL)
	{
		temp->bool = 0;
		temp = temp->next;
	}
}

void	transform_stack(t_stackdata	*data)
{
	t_stack	*temp;
	int		i;

	i = 0;
	while (i != data->a_len)
	{
		temp = find_min(data->a);
		temp->num = i++;
		temp->bool = 1;
	}
	set_bool(data);
}
