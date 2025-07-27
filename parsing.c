/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:28:33 by ibudko            #+#    #+#             */
/*   Updated: 2025/07/27 18:07:39 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_duplicates(t_node *a)
{
	t_node	*current;
	t_node	*compare;

	current = a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				exit_error(&a);
			compare = compare->next;
		}
		current = current->next;
	}
}

static int	is_all_space(const char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

static int	safe_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		exit_simple_error();
	while (*str)
	{
		if (*str < '0' || *str > '9')
			exit_simple_error();
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			exit_simple_error();
		str++;
	}
	return ((int)(num * sign));
}

static void	append_node(t_node **a, int value)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		exit_error(a);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		return ;
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = new;
}

int	parse_args(int argc, char **argv, t_node **a)
{
	int		i;
	char	**split;
	int		j;
	int		num;

	i = 1;
	while (i < argc)
	{
		if (is_all_space(argv[i]) || argv[i][0] == '\0')
			exit_simple_error();
		split = ft_split(argv[i], ' ');
		if (!split)
			exit_error(a);
		j = 0;
		while (split[j])
		{
			num = safe_atoi(split[j]);
			append_node(a, num);
			free(split[j++]);
		}
		free(split);
		i++;
	}
	check_duplicates(*a);
	return (0);
}
