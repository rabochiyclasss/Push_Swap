/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:26:13 by ibudko            #+#    #+#             */
/*   Updated: 2025/06/26 14:52:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_simple_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	exit_error(t_node **a)
{
	if (a)
		free_stack(a);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
