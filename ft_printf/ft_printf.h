/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:29:06 by sali              #+#    #+#             */
/*   Updated: 2021/11/01 15:23:25 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct print_flags
{
	va_list	arg;
	int		len;
	int		plus;
	int		space;
	int		hash;
	int		zero;
}t_list;

void			ft_putchar(char c, t_list *plist);
unsigned int	ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
void			ft_putun(unsigned n, t_list *plist);
void			ft_putnbr(int n, t_list *plist);
void			ft_putbase(unsigned long long num, char *base, t_list *plist);
void			ft_pchar(int c, int *i, t_list *plist);
void			ft_pstr(char *str, int *i, t_list *plist);
void			ft_ppoint(unsigned long long int s, int *i, t_list *plist);
void			ft_ppercent(int *i, t_list *plist);
void			ft_phex(unsigned int n, int *i, t_list *plist);
void			ft_pcaphex(unsigned int n, int *i, t_list *plist);
void			ft_pint(int num, int *i, t_list *plist);
void			ft_punsinged(unsigned int n, int *i, t_list *plist);

#endif
