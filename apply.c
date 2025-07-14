/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanbudko <ivanbudko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:55:41 by ivanbudko         #+#    #+#             */
/*   Updated: 2025/07/14 15:55:49 by ivanbudko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Apply double rotations as needed */
void	apply_double_rotations(t_node **a, t_node **b, int *pos_a, int *pos_b)
{
	while (*pos_a > 0 && *pos_b > 0)
	{
		rr(a, b);
		(*pos_a)--;
		(*pos_b)--;
	}
}

/* Apply double reverse rotations as needed */
void	apply_double_rev_rotations(t_node **a, t_node **b, int *pos_a, int *pos_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	while (*pos_a < size_a && *pos_b < size_b)
	{
		rrr(a, b);
		(*pos_a)++;
		(*pos_b)++;
	}
}

/* Apply rotations based on cost */
void	apply_rotations_case1(t_node **a, t_node **b, int pos_a, int pos_b)
{
	apply_double_rotations(a, b, &pos_a, &pos_b);
	while (pos_a-- > 0)
		ra(a);
	while (pos_b-- > 0)
		rb(b);
}

/* Apply rotations based on cost */
void	apply_rotations_case2(t_node **a, t_node **b, int pos_a, int pos_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	apply_double_rev_rotations(a, b, &pos_a, &pos_b);
	while (pos_a++ < size_a)
		rra(a);
	while (pos_b++ < size_b)
		rrb(b);
}

/* Apply rotations based on cost */
void	apply_rotations_mixed(t_node **a, t_node **b, int pos_a, int pos_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	if (pos_a <= size_a / 2 && pos_b > size_b / 2)
	{
		while (pos_a-- > 0)
			ra(a);
		while (pos_b++ < size_b)
			rrb(b);
	}
	else
	{
		while (pos_a++ < size_a)
			rra(a);
		while (pos_b-- > 0)
			rb(b);
	}
}

/* Apply rotation operations as needed */
void	apply_rotations(t_node **stack_a, t_node **stack_b, t_cost cost)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	pos_a = find_target_position(*stack_a, cost.num);
	pos_b = find_position(*stack_b, cost.num);
	if (pos_a <= size_a / 2 && pos_b <= size_b / 2)
		apply_rotations_case1(stack_a, stack_b, pos_a, pos_b);
	else if (pos_a > size_a / 2 && pos_b > size_b / 2)
		apply_rotations_case2(stack_a, stack_b, pos_a, pos_b);
	else
		apply_rotations_mixed(stack_a, stack_b, pos_a, pos_b);
}
