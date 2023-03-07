/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:45:42 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/07 16:59:33 by gpasztor         ###   ########.fr       */
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
	data->a->prev = NULL;
	node = data->a;
	while (++i != argc)
	{
		if (i < argc)
			node->next = (t_stack *)malloc(sizeof(t_stack));
		node->num = ft_atoi(argv[i]);
		temp = node;
		if (i == argc)
			node->next = NULL;
		else
			node = node->next;
		node->prev = temp;
	}
	node->next = NULL;
}

int	main(int argc, char **argv)
{
	t_stackdata	data;

	initialise_a(&data, argc, argv);
	return (0);
}
