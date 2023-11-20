/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:11:16 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/20 08:49:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base(int n, const char *base)
{
	long int	nbr;
	int			length;

	length = 0;
	nbr = n;
	if (nbr < 0)
	{
		length += print_char('-');
		nbr = -nbr;
	}
	if (nbr >= ft_strlen(base))
		length += print_base(nbr / ft_strlen(base), base);
	length += print_char(base[nbr % ft_strlen(base)]);
	return (length);
}

int	print_unsnumber(unsigned int nbr)
{
	int	length;

	length = 0;
	if (nbr > 9)
		length += print_unsnumber(nbr / 10);
	length += print_char((nbr % 10) + '0');
	return (length);
}

int	print_adr(uintptr_t ptr, const char *base)
{
	int	length;

	length = 0;
	if (ptr > ft_strlen(base))
		length += print_adr(ptr / ft_strlen(base), base);
	length += print_char(base[ptr % ft_strlen(base)]);
	return (length);
}
