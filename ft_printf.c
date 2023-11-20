/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 06:48:54 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/20 08:58:48 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;

	va_start(args, str);
	length = 0;
	while (*str != '\0')
	{
		if (*str == '%' && same_letter(str[1], "cspdiuxX%") == 1)
		{
			length += length_output(str[1], args);
			str += 2;
		}
		else
		{
			print_char(*str);
			length++;
			str++;z
		}
	}
	va_end(args);
	return (length);
}

int	length_output(char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = print_char(va_arg(args, int));
	else if (c == 's')
		length = print_str(va_arg(args, char *));
	else if (c == 'p')
		length += print_adr(va_arg(args, uintptr_t), "0123456789abcdef");
	else if (c == 'd')
		length = print_base(va_arg(args, int), "0123456789");
	else if (c == 'i')
		length = print_base(va_arg(args, int), "0123456789");
	else if (c == 'u')
		length = print_unsnumber(va_arg(args, unsigned int));
	else if (c == 'x')
		length = print_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		length = print_base(va_arg(args, int), "0123456789ABCDEF");
	else
		length = print_percent();
	return (length);
}
