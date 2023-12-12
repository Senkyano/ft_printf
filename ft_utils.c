/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:30:37 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/28 13:16:21 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strcharcmp(char c, const char *cmp)
{
	while (*cmp != '\0')
	{
		if (c == *cmp)
			return (1);
		cmp++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_lenhexa(unsigned int n, char *base)
{
	size_t	length;
	size_t	lenbase;

	lenbase = ft_strlen(base);
	length = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= lenbase;
		length++;
	}
	return (length);
}

size_t	ft_lenaddr(uintptr_t ptr, char *base)
{
	size_t	length;
	size_t	lenbase;

	lenbase = ft_strlen(base);
	length = 0;
	while (ptr > 0)
	{
		ptr /= lenbase;
		length++;
	}
	return (length);
}
