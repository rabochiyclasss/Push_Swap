/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanbudko <ivanbudko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:09:44 by ibudko            #+#    #+#             */
/*   Updated: 2025/07/14 16:02:09 by ivanbudko        ###   ########.fr       */
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

void	rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	reverse_rotate(t_node **stack);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

void	push(t_node **dst, t_node **src);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	sort_large(t_node **a, t_node **b);
void	turk_sort(t_node **stack_a, t_node **stack_b);
void	initial_push_to_b(t_node **stack_a, t_node **stack_b);
void	push_first_half(t_node **a, t_node **b, int size, int *pushed);

t_cost	calculate_cost(t_node *stack_a, t_node *stack_b, int pos_b);
void	calculate_total_cost(t_cost *cost);
t_cost	set_cost_values(t_node *stack_a, t_node *stack_b, int pos_b);

int	ft_max(int a, int b);
int	ft_min(int a, int b);
int	find_position(t_node *stack, int index);
int	find_smallest_index(t_node *stack);
int	find_target_position(t_node *stack_a, int index_b);
t_cost	find_min_cost_element(t_node *stack_a, t_node *stack_b);
int	find_largest_index(t_node *stack);

void	apply_double_rotations(t_node **a, t_node **b, int *pos_a, int *pos_b);
void	apply_double_rev_rotations(t_node **a, t_node **b, int *pos_a, int *pos_b);
void	apply_rotations_case1(t_node **a, t_node **b, int pos_a, int pos_b);
void	apply_rotations_case2(t_node **a, t_node **b, int pos_a, int pos_b);
void	apply_rotations_mixed(t_node **a, t_node **b, int pos_a, int pos_b);
void	apply_rotations(t_node **stack_a, t_node **stack_b, t_cost cost);

#endif