/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:51:48 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 17:51:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	sizetot(int	n, int sizebase)
{
	long int	nbr;
	size_t		length;

	length = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		length++;
	}
	while (nbr > 0)
	{
		nbr = nbr / sizebase;
		length++;
	}
	return (length);
}

/* *************************************************************************** */
/*          %X , %x , %d , %i                                                  */
/* *************************************************************************** */
int	print_digit(int n, char *base)
{
	long int	nbr;
	char		*number;
	size_t		index;

	index = sizetot(n, ft_strlen(base));
	number = malloc((index + 1) * sizeof(char));
	if (!number)
		return (0);
	nbr = n;
	if (nbr < 0)
	{
		number[0] = '-';
		nbr = -nbr;
	}
	number[index] = '\0';
	while (nbr > ft_strlen(base) - 1)
	{
		number[--index] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
	}
	number[--index] = base[nbr % ft_strlen(base)];
	n = print_str(number);
	free(number);
	return (n);
}

/* *************************************************************************** */
/*          %p                                                                 */
/* *************************************************************************** */

size_t	sizeaddr(unsigned long int n, int sizebase)
{
	size_t	length;

	length = 0;
	while (n > 0)
	{
		n /= sizebase;
		length++;
	}
	return (length);
}

int	print_addr(unsigned long int n, char *base)
{
	size_t	index;
	char	*digaddr;
	int		lenbase;

	lenbase = ft_strlen(base);
	index = sizeaddr(n, lenbase);
	digaddr = malloc((index + 1) * sizeof(char));
	if (!digaddr)
		return (0);
	digaddr[index] = '\0';
	while (n > lenbase - 1)
	{
		digaddr[--index] = base[n % lenbase];
		n /= lenbase;
	}
	digaddr[--index] = base[n % lenbase];
	print_char('0');
	print_char('x');
	lenbase = print_str(digaddr) + 2;
	free(digaddr);
	return (lenbase);
}