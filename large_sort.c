/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:07:50 by ivanbudko         #+#    #+#             */
/*   Updated: 2025/07/27 18:09:26 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large(t_node **a, t_node **b)
{
	assign_index(*a);
	turk_sort(a, b);
}

void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	t_cost	min_cost;
	
	initial_push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		min_cost = find_min_cost_element(*stack_a, *stack_b);
		apply_rotations(stack_a, stack_b, min_cost);
		pa(stack_a, stack_b);
	}
	final_rotate(stack_a);
}

void	initial_push_to_b(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	pushed;

	size = stack_size(*stack_a);
	pushed = 0;
	push_first_half(stack_a, stack_b, size, &pushed);
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	push_first_half(t_node **a, t_node **b, int size, int *pushed)
{
	int	i;
	
	i = 0;
	while (size > 3 && i < size && *pushed < size - 3)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			(*pushed)++;
		}
		else
			ra(a);
		i++;
	}
}
