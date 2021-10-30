#include "ft_printf.h"

void	reset_list(p_list *plist)	
{
	plist->str = NULL;
	plist->len = 0;
	plist->c = 0;
	plist->s = 0;
	plist->p = 0;
	plist->d = 0;
	plist->i = 0;
	plist->u = 0;
	plist->x = 0;
	plist->cap_x = 0;
	plist->percent = 0;
	plist->minus = 0;
	plist->plus = 0;
	plist->space = 0;
	plist->hash = 0;
}

char get_specifier(const char *input, int i)
{
	i++;
	if(input[i] == 'c' || input[i] == 's' || input[i] == 'p' || input[i] == 'd' || input[i] == 'u' || input[i] == 'x' || input[i] == 'X' || input[i] == '%')
		return (input[i]);
	return (0);
}

void	print_specifier(const char *input, p_list *plist, int *i)
{
	char specifier;
		reset_list(plist);
		// specifier = ft_setflags();
		specifier = get_specifier(input, *i);
		if (specifier == 'c')
		 ft_pchar(va_arg(plist->arg, int), i);
		if (specifier == 's')
		 ft_pstr(va_arg(plist->arg, char *), i);
		if (specifier == 'p')
		 ft_ppoint(va_arg(plist->arg, unsigned long long int), i);
		if(specifier == 'd' || specifier == 'i')
		 ft_pint(va_arg(plist->arg, int), i);
		if(specifier == 'u')
		 ft_punsinged(va_arg(plist->arg, unsigned long), i);
		if(specifier == 'x')
		 ft_phex(va_arg(plist->arg, unsigned int), i);
		if(specifier == 'X')
		ft_pcaphex(va_arg(plist->arg, unsigned int), i);
		if(specifier == '%')
		ft_ppercent(va_arg(plist->arg, int), i); 
}

int	ft_printf(const char *input, ...)
{
	p_list *plist;
	int i;
	
	i = 0;
	plist = (p_list *) malloc(sizeof(p_list) * 1);
	va_start(plist->arg, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
			print_specifier(input, plist, &i);
		else
		{
			write(1,&input[i],1);
			i++;
		}
	}
	va_end(plist->arg);
	return (i);
}
#include <stdio.h>
int main(void)
{
	printf("%%%%%%%%\n");
	ft_printf("%%%%%%%%\n");
}