/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:45:42 by ivanbudko         #+#    #+#             */
/*   Updated: 2025/07/27 18:10:10 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	calculate_cost(t_node *stack_a, t_node *stack_b, int pos_b)
{
	t_cost	cost;
	
	cost = set_cost_values(stack_a, stack_b, pos_b);
	calculate_total_cost(&cost);
	return (cost);
}

void	calculate_total_cost(t_cost *cost)
{
	int	cost1;
	int	cost2;
	int	cost3;
	int	cost4;

	cost1 = ft_max(cost->ra, cost->rb);
	cost2 = ft_max(cost->rra, cost->rrb);
	cost3 = cost->ra + cost->rrb;
	cost4 = cost->rra + cost->rb;
	cost->total = ft_min(ft_min(cost1, cost2), ft_min(cost3, cost4));
}

t_cost	set_cost_values(t_node *stack_a, t_node *stack_b, int pos_b)
{
	t_cost	cost;
	int		size_a;
	int		size_b;
	t_node	*elem_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	elem_b = stack_b;
	while (pos_b--)
		elem_b = elem_b->next;
	cost.ra = find_target_position(stack_a, elem_b->index);
	cost.rra = size_a - cost.ra;
	cost.rb = find_position(stack_b, elem_b->index);
	cost.rrb = size_b - cost.rb;
	cost.num = elem_b->index;
	return (cost);
}
