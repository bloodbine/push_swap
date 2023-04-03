/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:32:49 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/03 15:08:37 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	sort_3(t_stackdata *data)
{
	int	pos1;
	int	pos2;

	pos1 = find_index(data->a, (find_min(data->a))->num) + 1;
	pos2 = find_index(data->a, (find_max(data->a))->num) + 1;
	if (pos1 == 1 && pos2 == 2)
	{
		rra(data, 1);
		sa(data, 1);
	}
	else if (pos1 == 3 && pos2 == 1)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (pos1 == 2 && pos2 == 3)
		sa(data, 1);
	else if (pos1 == 3 && pos2 == 2)
		rra(data, 1);
	else if (pos1 == 2 && pos2 == 1)
		ra(data, 1);
}

void	sort_5(t_stackdata *data)
{
	t_stack	*max;

	while (data->a_len != 3)
	{
		max = find_max(data->a);
		move_to_top(data, &(data->a), max, data->a_len);
		pb(data);
	}
	sort_3(data);
	while (data->b_len != 0)
		pa(data);
	if (data->a->num > data->a->next->num && data->a_len == 5)
		sa(data, 1);
	ra(data, 1);
	if (data->a_len == 5)
		ra(data, 1);
}

void	sort_100(t_stackdata *data, int mid, int multi, int border)
{
	while (data->a_len != 0)
	{
		if (border * 2 * multi - 4 < data->b_len)
			multi++;
		if (data->a->num >= mid - border * multi && data->a->num <= mid)
		{
			pb(data);
			rb(data, 1);
		}
		else if (data->a->num <= mid + border * multi && data->a->num > mid)
			pb(data);
		else
			ra(data, 1);
	}
	while (data->b_len > 2)
		sort_b(data);
	if (data->b_len == 2)
	{
		move_to_top(data, &(data->b), find_max(data->b), data->b_len);
		pa(data);
	}
	if (data->b_len == 1)
		pa(data);
}
