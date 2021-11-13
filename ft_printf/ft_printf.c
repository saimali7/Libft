/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:53:37 by sali              #+#    #+#             */
/*   Updated: 2021/11/01 15:20:28 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_list(t_list *plist)
{
	plist->plus = 0;
	plist->space = 0;
	plist->hash = 0;
	plist->zero = 0;
}

char	get_specifier(const char *input, int *i, t_list *plist)
{
	if (input[*i] == '%')
		*i = *i + 1;
	while (ft_strchr("+ #0", input[*i]) != NULL)
	{
		if (input[*i] == '+')
			plist->plus = 1;
		else if (input[*i] == ' ')
			plist->space = 1;
		else if (input[*i] == '#')
			plist->hash = 1;
		else if (input[*i] == '0')
			plist->zero = 1;
		*i = *i + 1;
	}
	if (ft_strchr("icspduxX%", input[*i]) != NULL)
		return (input[*i]);
	return (0);
}

void	print_specifier(const char *input, t_list *plist, int *i)
{
	char	specifier;

	reset_list(plist);
	specifier = get_specifier(input, i, plist);
	if (specifier == 'c')
		ft_pchar(va_arg(plist->arg, int), i, plist);
	else if (specifier == 's')
		ft_pstr(va_arg(plist->arg, char *), i, plist);
	else if (specifier == 'p')
		ft_ppoint(va_arg(plist->arg, unsigned long long int), i, plist);
	else if (specifier == 'd' || specifier == 'i')
		ft_pint(va_arg(plist->arg, int), i, plist);
	else if (specifier == 'u')
		ft_punsinged(va_arg(plist->arg, unsigned long), i, plist);
	else if (specifier == 'x')
		ft_phex(va_arg(plist->arg, unsigned int), i, plist);
	else if (specifier == 'X')
		ft_pcaphex(va_arg(plist->arg, unsigned int), i, plist);
	else if (specifier == '%')
		ft_ppercent(i, plist);
	else
	{
		ft_putchar(input[*i], plist);
		*i = *i + 1;
	}
}

int	ft_printf(const char *input, ...)
{
	t_list	*plist;
	int		i;

	plist = NULL;
	i = 0;
	plist = (t_list *) malloc(sizeof(t_list) * 1);
	reset_list(plist);
	plist->len = 0;
	va_start(plist->arg, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
			print_specifier(input, plist, &i);
		else
		{
			write(1, &input[i], 1);
			i++;
			plist->len++;
		}
	}
	va_end(plist->arg);
	i = plist->len;
	free(plist);
	return (i);
}
