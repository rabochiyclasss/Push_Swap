/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:09:44 by ibudko            #+#    #+#             */
/*   Updated: 2025/06/27 11:26:21 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "ft_printf/ft_printf.h"

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_cost
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	total;
	int	num;
}	t_cost;

int		parse_args(int argc, char **argv, t_node **a);
int		is_sortded(t_node *stack);
void	exit_simple_error(void);
void	exit_error(t_node **a);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
t_node	*find_next_min(t_node *stack);
void	assign_index(t_node *stack);
int		is_sortded(t_node *stack);
void	sort_stack(t_node **a, t_node **b);
void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_small(t_node **a, t_node **b);
int		find_min_pos(t_node *stack);

#endif