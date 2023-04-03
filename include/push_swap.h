/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:23:52 by gpasztor          #+#    #+#             */
/*   Updated: 2023/04/03 14:18:57 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	"../libft/libft.h"

typedef struct s_stack
{
	int				bool;
	int				num;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stackdata
{
	t_stack	*a;
	t_stack	*b;
	int		a_len;
	int		b_len;
	int		min;
	int		max;
}			t_stackdata;

typedef struct s_top3
{
	t_stack	*max;
	t_stack	*smax;
	t_stack	*tmax;
	int		md;
	int		sd;
	int		td;
}			t_top3;

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

// Moves

//  Swap

//   Swap top elements of A
void	sa(t_stackdata *data, int print);
//   Swap top elements of B
void	sb(t_stackdata *data, int print);
//   Swap top elements of A and B
void	ss(t_stackdata *data);
//  Push

//   Push from B to A
void	pa(t_stackdata *data);
//   Push from A to B
void	pb(t_stackdata *data);

//  Rotate

//   Rotate A up
void	ra(t_stackdata *data, int print);
//   Rotate B up
void	rb(t_stackdata *data, int print);
//   Rotate A and B up
void	rr(t_stackdata *data);

//  Reverse Rotate

//   Rotate A down
void	rra(t_stackdata *data, int print);
//   Rotate B down
void	rrb(t_stackdata *data, int print);
//   Rotate A and B down
void	rrr(t_stackdata *data);

// Input error checks

//  Check for multiple signs
void	check_signs(char **args);
//  Check for Alphabetical characters
void	check_chars(char **args);
//  Check for Duplicate numbers
void	check_duplicates(t_stack *head);

// Helper functions

//  Remove head of list and return a pointer to it
t_stack	*pop_head(t_stack **head);
//  Remove tail of list and return a pointer to it
t_stack	*pop_tail(t_stack **head);
// Finds and returns pointer to smallest integer in linked list
t_stack	*find_min(t_stack *head);
// Finds and returns pointer to the greatest integer in linked list
t_stack	*find_max(t_stack *head);
// Finds and returns index where value is located in linked list
int		find_index(t_stack *head, int num);
// Transforms stored numbers to what their spot should be in a sorted list
void	transform_stack(t_stackdata	*data);
// Set default value for bool in nodes
void	set_bool(t_stackdata *data);
//  Find and compare the three biggest nodes in stack b then push in order
void	sort_b(t_stackdata *data);
//  Calculate absolute distance of node from the top of the stack
int		calculate_distance(t_stack *head, t_stack *node, int len);
// Move selected node to the top it's stack
void	move_to_top(t_stackdata *data, t_stack **head, t_stack *node, int len);
//	Print stacks in their current state (debug)
void	print_stacks(t_stackdata *data);
//  Find rounded square root of given number
int		ft_sqrt(int nbr);

// Sorting functions

//  Sort 3 or less numbers
void	sort_3(t_stackdata *data);
//  Sort 5 or less numbers
void	sort_5(t_stackdata *data);
//  Sort numbers greater than 5
void	sort_100(t_stackdata *data, int mid, int multi, int border);

#endif