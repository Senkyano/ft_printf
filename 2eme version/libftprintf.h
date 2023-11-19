#ifndef _LIBFTPRINTF_R_H
# define _LIBFTPRINTF_R_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int	ft_printf(const char *str, ...);
int	length_output(char c, va_list args);

#endif