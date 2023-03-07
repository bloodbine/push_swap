/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpasztor <gpasztor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:23:52 by gpasztor          #+#    #+#             */
/*   Updated: 2023/03/07 16:43:55 by gpasztor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<unistd.h>
# include	"../libft-gpasztor/libft.h"

# ifndef STACK_H
#  define STACK_H

typedef struct s_stack
{
	struct s_stack	*prev;
	int				num;
	struct s_stack	*next;
}				t_stack;

# endif

# ifndef STACKDATA_H
#  define STACKDATA_H

typedef struct s_stackdata
{
	t_stack	*a;
	t_stack	*b;
}			t_stackdata;

# endif

// Helper functions

// Moves

#endif