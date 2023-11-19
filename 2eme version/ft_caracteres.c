/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caracteres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:35:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 17:35:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(unsigned int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += print_char(str[i]);
	return (i);
}

int	print_percent(void)
{
	return (print_char('%'));
}
