/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanbudko <ivanbudko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:52:23 by ivanbudko         #+#    #+#             */
/*   Updated: 2025/07/14 15:54:07 by ivanbudko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Return maximum of two integers */
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/* Return minimum of two integers */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_position(t_node *stack, int index)
{
	int	pos;
	
	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

/* Find smallest index in stack */
int	find_smallest_index(t_node *stack)
{
	int	smallest;

	if (!stack)
		return (-1);
	smallest = stack->index;
	while (stack)
	{
		if (stack->index < smallest)
			smallest = stack->index;
		stack = stack->next;
	}
	return (smallest);
}
/* Find the target position in stack_a for an element from stack_b */
int	find_target_position(t_node *stack_a, int index_b)
{
	t_node	*current;
	int		target_index;
	int		target_pos;

	target_index = INT_MAX;
	target_pos = 0;
	current = stack_a;
	if (index_b < find_smallest_index(stack_a))
		return (find_position(stack_a, find_smallest_index(stack_a)));
	if (index_b > find_largest_index(stack_a))
		return (find_position(stack_a, find_smallest_index(stack_a)));
	while (current)
	{
		if (current->index > index_b && current->index < target_index)
		{
			target_index = current->index;
			target_pos = find_position(stack_a, current->index);
		}
		current = current->next;
	}
	return (target_pos);
}

t_cost	find_min_cost_element(t_node *stack_a, t_node *stack_b)
{
	t_cost	min_cost;
	t_cost	current_cost;
	int		i;
	int		size_b;
	
	size_b = stack_size(stack_b);
	min_cost.total = INT_MAX;
	i = 0;
	while (i < size_b)
	{
		current_cost = calculate_cost(stack_a, stack_b, i);//2.1
		if (current_cost.total < min_cost.total)
			min_cost = current_cost;
		i++;
	}
	return (min_cost);
}

/* Find largest index in stack */
int	find_largest_index(t_node *stack)
{
	int	largest;

	if (!stack)
		return (-1);
	largest = stack->index;
	while (stack)
	{
		if (stack->index > largest)
			largest = stack->index;
		stack = stack->next;
	}
	return (largest);
}
