/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:29:06 by sali              #+#    #+#             */
/*   Updated: 2021/10/28 17:39:01 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

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
