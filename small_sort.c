/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanbudko <ivanbudko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:46:08 by student           #+#    #+#             */
/*   Updated: 2025/07/14 16:12:57 by ivanbudko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

int	find_min_pos(t_node *stack)// finds the position of the node with smallest value
{
	int		min;
	int		pos;
	int		min_pos;
	t_node	*current;

	if (!stack)
		return (-1);
	current = stack;
	min = current->value;
	pos = 0;
	min_pos = 0;

	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int third;

	if(!*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if(first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first > third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_node **a, t_node **b)//add .h
{
	int	min_pos;
	
	min_pos = find_min_pos(*a);
	if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
		rra (a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_node **a, t_node **b)//add .h
{
	int	min_pos;
	
	min_pos = find_min_pos(*a);
	
	if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_pos == 4)
		rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_small(t_node **a, t_node **b)
{
	int	size;
	
	size = stack_size(*a);
	if(size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}