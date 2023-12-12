/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:07:29 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/12 17:57:27 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		length;
	int		error;
	va_list	args;

	length = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%' && ft_strcharcmp(str[1], "cspdiuxX%") == 1)
		{
			error = ft_output(str[1], args, length);
			if (error == -1)
				return (-1);
			length += error;
			str += 2;
		}
		else
		{
			ft_print_char(*str);
			length++;
			str++;
		}
	}
	va_end(args);
	return (length);
}

int	ft_output(char c, va_list args, int length)
{
	if (c == 'c')
		length = ft_print_char(va_arg(args, int));
	else if (c == 's')
		length = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		length = ft_addr(va_arg(args, uintptr_t), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		length = ft_nbr(va_arg(args, int));
	else if (c == 'u')
		length = ft_unnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		length = ft_nbhexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		length = ft_nbhexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		length = ft_print_char('%');
	else
		return (-1);
	return (length);
}
