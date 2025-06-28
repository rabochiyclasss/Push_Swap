/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanbudko <ivanbudko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:22:25 by ivanbudko         #+#    #+#             */
/*   Updated: 2025/06/28 13:22:50 by ivanbudko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b)
{
	int	size;
	
	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (parse_args(argc, argv, &a) != 0)
		exit_error(&a);
	if (!is_sorted(a))
	{
		assign_index(a);
		sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
