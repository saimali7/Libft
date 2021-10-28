#include <ft_printf.h>

char get_specifier(const char *input, int i)
{
	i++;
	if(input[i] == 'c' || input[i] == 's' || input[i] == 'p' || input[i] == 'd' || input[i] == 'u' || input[i] == 'x' || input[i] == 'X' || input == '%')
		return (input[i]);
	return (0);
}

do_everything(const char *input, p_list *plist, int *i)
{
	char specifier;
	while(input[*i] != '\0')
	{
		reset_list(plist);
		// specifier = ft_setflags();
		specifier = get_specifier(input, *i);
		if (specifier == 'c')
		 ft_pchar(va_arg(plist->arg, i));
		if (specifier == 's')
		 ft_pstr();
		if (specifier == 'p')
		 ft_ppoint(va_arg());
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
		if (input[i] == '%')
			p_specifier(input, plist, &i);
		else
			write(1,&input[i],1);
		i++;
	}
	va_end(plist->arg);
	return (len);
}