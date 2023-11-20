/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:14:19 by rihoy             #+#    #+#             */
/*   Updated: 2023/11/20 12:15:22 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <inttypes.h>

int		ft_strcharcmp(char c, const char *cmp);
int		ft_strlen(char *str);
size_t	ft_lenhexa(unsigned int n, char *base);
size_t	ft_lenaddr(uintptr_t ptr, char *base);
int		ft_print_char(unsigned char c);
int		ft_print_str(char *str);
int		ft_nbhexa(unsigned int n, char *base);
int		ft_addr(uintptr_t ptr, char *base);
int		ft_nbr(int n);
int		ft_unnbr(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_output(char c, va_list args, int length);

#endif