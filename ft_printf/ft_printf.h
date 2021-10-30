/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:29:06 by sali              #+#    #+#             */
/*   Updated: 2021/10/30 23:20:09 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_putchar.c"
# include "ft_strlen.c"
# include "ft_putnbr.c"
# include "ft_putbase.c"
# include "char.c"
# include "string.c"
# include "pointer.c"
# include "int.c"
# include "unsigned.c"
# include "hex.c"
# include "caphex.c"
# include "percent.c"

typedef struct print_flags
{
	va_list arg;
	char *str;
	int len;
	int c;
	int s;
	int p;
	int d;
	int i;
	int u;
	int x;
	int cap_x;
	int percent;
	int minus;
	int plus;
	int space;
	int hash;
} p_list;

#endif
