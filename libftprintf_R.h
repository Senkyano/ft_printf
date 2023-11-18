#ifndef _LIBFTPRINTF_R_H
# define _LIBFTPRINTF_R_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int		print_char(char c);
int		print_str(char *str);
int		ft_printf(const char *str, ...);
int		same_letter(char c, const char *str);
int		lenght_output(char c, va_list args);
int		print_adr(long unsigned int ptr, const char *base);
int		print_inte(char *hexa, const char *base);
int		cible(char c, const char *base);
int		print_unsnumber(unsigned int nbr);
int		print_percent(void);
int		print_base(int n, const char *base);
int		ft_strlen(const char *str);

#endif