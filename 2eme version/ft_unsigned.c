/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:02:28 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 20:02:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_unsigned(unsigned int n, char *base)
{
	size_t	index;
	int		lenbase;
	char	*number;

	lenbase = ft_strlen(base);
	index = sizetot(n, lenbase);
	number = malloc((index + 1) * sizeof(char));
	number[index--] = '\0';
	while (n > lenbase - 1)
	{
		number[index--] = base[n % lenbase];
		n /= lenbase;
	}
	number[index] = base[n % lenbase];
	lenbase = print_str(number);
	free(number);
	return (lenbase);
}