/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:56:34 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/28 13:16:28 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr(int n)
{
	long int	nbr;
	int			length;

	length = 0;
	nbr = n;
	if (nbr < 0)
	{
		length += ft_print_char('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		length += ft_nbr(nbr / 10);
	length += ft_print_char((nbr % 10) + 48);
	return (length);
}

int	ft_unnbr(unsigned int n)
{
	long int	nbr;
	int			length;

	length = 0;
	nbr = n;
	if (nbr > 9)
		length += ft_nbr(nbr / 10);
	length += ft_print_char((nbr % 10) + '0');
	return (length);
}
