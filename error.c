/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:26:13 by ibudko            #+#    #+#             */
/*   Updated: 2025/06/25 19:35:29 by ibudko           ###   ########.fr       */
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

	if (!stack || !*stack)//first condition check the pointer to the stack second is the check for the head of the list
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
