/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:07:29 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/20 12:16:09 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	args;

	length = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%' && ft_strcharcmp(str[1], "cspdiuxX%") == 1)
		{
			length += ft_output(str[1], args, length);
			str += 2;
		}
		else
		{
			ft_print_char(*str);
			length++;
			str++;
		}
	}
	return (length);
}

int	ft_output(char c, va_list args, int length)
{
	char	*tmp;

	if (c == 'c')
		length = ft_print_char(va_arg(args, int));
	else if (c == 's')
	{
		tmp = va_arg(args, char *);
		if (tmp == NULL)
			return (ft_print_str("(null)"));
		else
			return (ft_print_str(tmp));
	}
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
	else
		length = ft_print_char('%');
	return (length);
}
