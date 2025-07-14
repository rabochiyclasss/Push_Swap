/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanbudko <ivanbudko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:41:26 by student           #+#    #+#             */
/*   Updated: 2025/07/14 16:11:53 by ivanbudko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_next_min(t_node *stack)//aims  to find next min value to assign the index if its not
{
	t_node	*min;
	t_node	*current;

	min = NULL;
	current = stack;
	while (current)
	{
		if (current->index == -1 && (!min || current ->value < min->value))
			min = current;
		current = current->next;
	}
	return (min);
}

int	stack_size(t_node *stack)
{
	int	size;
	
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	assign_index(t_node *stack)
{
	t_node	*min;
	int		index;
	int		size;
	
	index = 0;
	size = stack_size(stack);
	while (index < size)
	{
		min = find_next_min(stack);
		if (min)
			min->index = index;
		index++;
	}
}

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}