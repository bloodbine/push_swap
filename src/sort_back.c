/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:18:56 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/03 15:08:18 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/push_swap.h"

void	sort_b_4(t_stackdata *data, t_top3 top)
{
	if (top.md >= top.sd && top.md >= top.td && top.sd >= top.td)
	{
		move_to_top(data, &(data->b), top.tmax, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.smax, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.max, data->b_len);
		sa(data, 1);
		ra(data, 1);
		pa(data);
		sa(data, 1);
		return (rra(data, 1));
	}
}

void	sort_b_3(t_stackdata *data, t_top3 top)
{
	if (top.md <= top.sd && top.md >= top.td && top.sd >= top.td)
	{
		move_to_top(data, &(data->b), top.tmax, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.max, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.smax, data->b_len);
		sa(data, 1);
		pa(data);
		return (sa(data, 1));
	}
	if (top.md >= top.sd && top.md >= top.sd && top.sd <= top.td)
	{
		move_to_top(data, &(data->b), top.smax, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.tmax, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.max, data->b_len);
		ra(data, 1);
		pa(data);
		sa(data, 1);
		return (rra(data, 1));
	}
	sort_b_4(data, top);
}

void	sort_b_2(t_stackdata *data, t_top3 top)
{
	if (top.md >= top.sd && top.md <= top.td && top.sd <= top.td)
	{
		move_to_top(data, &(data->b), top.smax, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.max, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.tmax, data->b_len);
		sa(data, 1);
		return (pa(data));
	}
	if (top.md <= top.sd && top.md <= top.td && top.sd >= top.td)
	{
		move_to_top(data, &(data->b), top.max, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.tmax, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.smax, data->b_len);
		pa(data);
		return (sa(data, 1));
	}
	sort_b_3(data, top);
}

void	sort_b(t_stackdata *data)
{
	t_top3	top;

	top.max = find_max(data->b);
	top.md = calculate_distance(data->b, top.max, data->b_len);
	top.smax = find_max(data->b);
	top.sd = calculate_distance(data->b, top.smax, data->b_len);
	top.tmax = find_max(data->b);
	top.td = calculate_distance(data->b, top.tmax, data->b_len);
	if (top.md <= top.sd && top.md <= top.td && top.sd <= top.td)
	{
		move_to_top(data, &(data->b), top.max, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.smax, data->b_len);
		pa(data);
		move_to_top(data, &(data->b), top.tmax, data->b_len);
		return (pa(data));
	}
	sort_b_2(data, top);
}
