/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:10:39 by rihoy             #+#    #+#             */
/*   Updated: 2023/12/12 17:34:15 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbhexa(unsigned int n, char *base)
{
	size_t	lenhexa;
	char	*nbrhexa;
	int		lenbase;

	lenhexa = ft_lenhexa(n, base);
	lenbase = ft_strlen(base);
	nbrhexa = malloc((lenhexa + 1) * sizeof(char));
	if (!nbrhexa)
		return (0);
	nbrhexa[lenhexa] = '\0';
	lenhexa--;
	while (n > lenbase - 1)
	{
		nbrhexa[lenhexa--] = base[n % lenbase];
		n /= lenbase;
	}
	nbrhexa[lenhexa] = base[n % lenbase];
	lenbase = ft_print_str(nbrhexa);
	free(nbrhexa);
	return (lenbase);
}

int	ft_addr(uintptr_t ptr, char *base)
{
	size_t	lenaddr;
	char	*addr;
	int		lenbase;

	if (ptr == 0)
		return (ft_print_str("(nil)"));
	lenaddr = ft_lenaddr(ptr, base) + 2;
	lenbase = ft_strlen(base);
	addr = malloc((lenaddr + 1) * sizeof(char));
	if (!addr)
		return (0);
	addr[lenaddr] = '\0';
	lenaddr--;
	addr[0] = '0';
	addr[1] = 'x';
	while (ptr > lenbase - 1)
	{
		addr[lenaddr--] = base[ptr % lenbase];
		ptr /= lenbase;
	}
	addr[lenaddr] = base[ptr % lenbase];
	lenbase = ft_print_str(addr);
	free(addr);
	return (lenbase);
}
