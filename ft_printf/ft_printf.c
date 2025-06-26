/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:32:48 by ibudko            #+#    #+#             */
/*   Updated: 2025/03/09 14:12:48 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive_print_unsigned(unsigned long number, char specifier,
	int is_hex, int *printed_chars)
{
	char	*digit_set;

	if (is_hex)
	{
		if (specifier == 'x')
			digit_set = "0123456789abcdef";
		else
			digit_set = "0123456789ABCDEF";
		if (number > 15)
			recursive_print_unsigned(number / 16, specifier,
				is_hex, printed_chars);
		ft_putchar_fd(digit_set[number % 16], 1);
	}
	else
	{
		if (number >= 10)
			recursive_print_unsigned(number / 10, specifier,
				is_hex, printed_chars);
		ft_putchar_fd((char)(number % 10) + '0', 1);
	}
	(*printed_chars)++;
}

static int	adjust_char_count(int *printed_chars, va_list args,
	const char *format_str, int pos)
{
	char	*temp_str;

	if (format_str[pos] == 's')
	{
		temp_str = va_arg(args, char *);
		if (temp_str)
			(*printed_chars) += (int)(ft_strlen(temp_str));
	}
	else if (format_str[pos] == 'c' || format_str[pos] == '%')
		(*printed_chars)++;
	else if (format_str[pos] == 'd' || format_str[pos] == 'i')
	{
		temp_str = ft_itoa(va_arg(args, int));
		(*printed_chars) += (int)(ft_strlen(temp_str));
		free(temp_str);
	}
	(*printed_chars)--;
	return (1);
}

static int	handle_null_argument(va_list args, int *printed_chars,
	int *pos_ptr, const char *format_str)
{
	va_list	args_copy;
	void	*argument_address;

	va_copy(args_copy, args);
	(*pos_ptr)++;
	if (format_str[(*pos_ptr)] == 'p' || format_str[(*pos_ptr)] == 's')
	{
		argument_address = va_arg(args_copy, void *);
		if (argument_address == 0 && format_str[(*pos_ptr)] == 'p')
		{
			ft_putstr_fd("(nil)", 1);
			(*printed_chars) += 5;
			va_end(args_copy);
			return (0);
		}
		else if (argument_address == 0 && format_str[(*pos_ptr)] == 's')
		{
			ft_putstr_fd("(null)", 1);
			(*printed_chars) += 6;
			va_end(args_copy);
			return (0);
		}
	}
	va_end(args_copy);
	return (1);
}

static void	process_format_specifier(const char *format_str, int *pos_ptr,
	va_list args, int *printed_chars)
{
	if (handle_null_argument(args, printed_chars, pos_ptr, format_str))
	{
		if (format_str[(*pos_ptr)] == 'c')
			ft_putchar_fd((char)va_arg(args, int), 1);
		else if (format_str[(*pos_ptr)] == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		else if (format_str[(*pos_ptr)] == 'p')
		{
			ft_putstr_fd("0x", 1);
			(*printed_chars) += 2;
			recursive_print_unsigned((unsigned long)va_arg(args, void *),
				'x', 1, printed_chars);
		}
		else if (format_str[(*pos_ptr)] == 'd' || format_str[(*pos_ptr)] == 'i')
			ft_putnbr_fd(va_arg(args, int), 1);
		else if (format_str[(*pos_ptr)] == 'u')
			recursive_print_unsigned((unsigned long)va_arg(args, unsigned int),
				0, 0, printed_chars);
		else if (format_str[(*pos_ptr)] == 'x' || format_str[(*pos_ptr)] == 'X')
			recursive_print_unsigned(va_arg(args, unsigned int),
				format_str[(*pos_ptr)],
				1, printed_chars);
		else if (format_str[(*pos_ptr)] == '%')
			ft_putchar_fd('%', 1);
	}
}

int	ft_printf(const char *format_str, ...)
{
	int		i;
	int		printed;
	va_list	argument_list;
	va_list	argument_list_copy;

	va_start(argument_list, format_str);
	i = 0;
	printed = 0;
	while (format_str[i])
	{
		if (format_str[i] != '%')
			ft_putchar_fd(format_str[i], 1);
		else
		{
			va_copy(argument_list_copy, argument_list);
			process_format_specifier(format_str, &i, argument_list, &printed);
			adjust_char_count(&printed, argument_list_copy,
				format_str, i);
		}
		i++;
		printed++;
	}
	va_end(argument_list);
	va_end(argument_list_copy);
	return (printed);
}
