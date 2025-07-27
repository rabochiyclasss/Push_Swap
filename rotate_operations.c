/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanbudko <ivanbudko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:12:03 by ivanbudko         #+#    #+#             */
/*   Updated: 2025/07/27 23:19:05 by ivanbudko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node *last;
	t_node *first;

	if(!stack || !*stack || !((*stack)->next))
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while(last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}
void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
