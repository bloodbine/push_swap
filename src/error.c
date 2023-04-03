/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:52:31 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/01 14:14:42 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	check_signs(char **args)
{
	int	i;
	int	j;
	int	bool;

	i = 0;
	bool = 0;
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if ((args[i][j] == '+' || args[i][j] == '-') && !args[i][j + 1])
				ft_error();
			if ((args[i][j] == '+' || args[i][j] == '-') && bool == 1)
				ft_error();
			if (args[i][j] == '+' || args[i][j] == '-')
				bool = 1;
			if (args[i][j] >= '0' || args[i][j] <= '9')
				bool = 1;
		}
		bool = 0;
	}
}

void	check_chars(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[++i])
	{
		if (ft_strlen(args[i]) == 0)
			ft_error();
		j = -1;
		while (args[i][++j])
		{
			while (args[i][j] == '+' || args[i][j] == '-')
				j++;
			if (args[i][j] < '0' || args[i][j] > '9')
				ft_error();
		}
	}
}

void	check_duplicates(t_stack *head)
{
	t_stack	*temp;
	t_stack	*checktemp;

	temp = head;
	while (temp->next != NULL)
	{
		if (temp->num > INT_MAX)
			ft_error();
		checktemp = temp->next;
		while (checktemp != NULL)
		{
			if (checktemp->num == temp->num)
				ft_error();
			checktemp = checktemp->next;
		}
		temp = temp->next;
	}
}
