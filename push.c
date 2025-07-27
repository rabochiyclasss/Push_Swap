/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanbudko <ivanbudko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:33:22 by ivanbudko         #+#    #+#             */
/*   Updated: 2025/07/27 23:20:58 by ivanbudko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dst, t_node **src)
{
	t_node	*temp;
	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
