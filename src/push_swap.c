/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:45:42 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/03 15:12:36 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	initialise_a(t_stackdata *data, int argc, char **argv)
{
	t_stack	*node;
	t_stack	*temp;
	int		i;

	i = 0;
	data->a = (t_stack *)malloc(sizeof(t_stack));
	node = data->a;
	while (++i != argc)
	{
		if (i < argc - 1)
		{
			node->next = (t_stack *)malloc(sizeof(t_stack));
			node->num = ft_atoi(argv[i]);
			temp = node;
		}
		if (i == argc - 1)
		{
			node->num = ft_atoi(argv[i]);
			node->next = NULL;
		}
		else
			node = node->next;
	}
	node->next = NULL;
}

void	print_stacks(t_stackdata *data)
{
	t_stack	*temp;
	int		i;

	temp = data->a;
	ft_printf("\tStack: A\t\n");
	while (temp != NULL)
	{
		i = temp->num;
		ft_printf("%d\t", i);
		while (--i != -1)
			ft_printf("|");
		ft_printf("\n");
		temp = temp->next;
	}
	temp = data->b;
	ft_printf("\tStack: B\t\n");
	while (temp != NULL)
	{
		i = temp->num + 1;
		ft_printf("%d\t", i);
		while (--i != 0)
			ft_printf("|");
		ft_printf("\n");
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stackdata	data;

	if (argc == 1)
		return (0);
	check_signs(argv);
	check_chars(argv);
	initialise_a(&data, argc, argv);
	data.b = NULL;
	data.a_len = argc - 1;
	data.b_len = 0;
	set_bool(&data);
	check_duplicates(data.a);
	transform_stack(&data);
	if (data.a_len <= 3)
		sort_3(&data);
	else if (data.a_len <= 5)
		sort_5(&data);
	else
		sort_100(&data, (data.a_len / 2), 1, ft_sqrt(data.a_len) + 6);
	return (0);
}
