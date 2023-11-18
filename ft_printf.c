/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>              +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:35:04 by rihoy            #+#    #+#              */
/*   Updated: 2023/11/17 15:35:04 by rihoy           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_R.h"

int	ft_printf(const char *str, ...)
{
	int	lenght;
	va_list	args;
	va_start(args, *str);

	lenght = 0;
	while (*str != '\0')
	{
		if (*str == '%' && same_letter(str[1], "cspdiuxX%") == 1)
		{
			lenght += lenght_output(str[1], args);
			str += 2;
		}
		else
		{
			print_char(*str);
			lenght++;
		}
		str++;
	}
	va_end(args);
	return (lenght);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	same_letter(char c, const char *str)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	lenght_output(char c, va_list args)
{
	int	lenght;

	lenght = 0;
	if (c == 'c')
		lenght = print_char(va_arg(args, int));
	else if (c == 's')
		lenght = print_str(va_arg(args, char *));
	else if (c == 'p')
		lenght = print_adr(va_arg(args, void *), "0123456789abcdef");
	else if (c == 'd')
		lenght = print_base(va_arg(args, int), "0123456789");
	else if (c == 'i')
		lenght = print_inte(va_arg(args, char *), "0123456789");
	else if (c == 'u')
		lenght = print_unsnumber(va_arg(args, unsigned int));
	else if (c == 'x')
		lenght = print_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		lenght = print_base(va_arg(args, int), "0123456789ABCDEF");
	else
		lenght = print_percent();
	return (lenght);
}

/* ************************************************************************** */
/*                               %c                                           */
/* ************************************************************************** */
int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/* ************************************************************************** */
/*                               %s                                           */
/* ************************************************************************** */
int	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		print_char(str[i++]);
	return (i);
}

/* ************************************************************************** */
/*                               %p                                           */
/* ************************************************************************** */
int	print_adr(long unsigned int ptr, const char *base)
{
	int	lenght;

	lenght = 0;
	lenght += print_char('0');
	lenght += print_char('x');
	if (ptr > ft_strlen(base))
		lenght += print_adr(ptr / ft_strlen(base), base);
	lenght += print_char(base[ptr % ft_strlen(base)]);
	return (lenght);
}

/* ************************************************************************** */
/*                               %i                                           */
/* ************************************************************************** */
int	print_inte(char *hexa, const char *base)
{
	int	nbr;
	int	n;

	n = 1;
	nbr = 0;
	if (*hexa == '-')
	{
		n = -1;
		hexa++;
	}
	while (*hexa != '\0' && cible(*hexa, base) != -1)
	{
		nbr = nbr * ft_strlen(base) + cible(*hexa, base);
		hexa++;
	}
	nbr *= n;
	return (print_base(nbr, base));
}

int	cible(char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}
/* ************************************************************************** */
/*                               %u                                           */
/* ************************************************************************** */
int	print_unsnumber(unsigned int nbr)
{
	int	lenght;

	lenght = 0;
	if (nbr > 9)
		lenght += print_unsnumber(nbr / 10);
	lenght += print_char((nbr % 10) + '0');
	return (lenght);
}

/* ************************************************************************** */
/*                               %%                                           */
/* ************************************************************************** */
int	print_percent(void)
{
	return (print_char('%'));
}

/* ************************************************************************** */
/*                  %x        et        %X        et        %d                */
/* ************************************************************************** */

int	print_base(int n, const char *base)
{
	long int nbr;
	int	lenght;

	lenght = 0;
	nbr = n;
	if (nbr < 0)
	{
		lenght += print_char('-');
		nbr = -nbr;
	}
	if (nbr >= ft_strlen(base))
		lenght += print_base(nbr / ft_strlen(base), base);
	lenght += print_char(base[nbr % ft_strlen(base)]);
	return (lenght);
}
