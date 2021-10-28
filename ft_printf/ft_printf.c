#include <ft_printf.h>

do_everything(const char *input, p_list *plist, int i)
{
	char specifier;
	while(input[i] != '\0')
	{
		reset_list(plist);
		specifier = ft_setflags();
		if (specifier == 'c')
		 ft_pchar(input, plist);
		if (specifier == 's')
		 ft_pstr();
		if (specifier == 'p')
		 ft_ppoint();
		if(specifier == 'd' || specifier == 'i')
		 ft_pint();
		if(specifier == 'u')
		 ft_punsinged();
		if(specifier == 'x')
		 ft_phex();
		if(specifier == 'X')
		ft_pcaphex();
		if(specifier == '%')
		ft_ppercent();
	}
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
		write(1,&input[i],1);
		if (input[i] == '%')
			p_specifier(input, plist, i);
		i++;
	}
	va_end(plist->arg);
	return (len);
}