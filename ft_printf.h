/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:54 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/20 08:50:03 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>

int	print_char(char c);
int	print_str(char *str);
int	ft_printf(const char *str, ...);
int	same_letter(char c, const char *str);
int	length_output(char c, va_list args);
int	print_adr(uintptr_t ptr, const char *base);
int	print_inte(char *hexa, const char *base);
int	cible(char c, const char *base);
int	print_unsnumber(unsigned int nbr);
int	print_percent(void);
int	print_base(int n, const char *base);
int	ft_strlen(const char *str);
int	print_x(void);

#endif