/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_carac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:12:10 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/20 08:17:43 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(void)
{
	return (print_char('%'));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		print_char(str[i++]);
	return (i);
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_x(void)
{
	int	length;

	length = 0;
	length += print_char('0');
	length += print_char('x');
	return (length);
}
