#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(char *s, ...)
{
	va_list ptr;
	char b;
	int i;

	i = 0;
	while (s[i] != '%')
	{
		write(1,&s[i],1);
		i++;
	}

	va_start(ptr, s);

	b = va_arg(ptr, int);
	write(1,&b,1);
	i++;
	i++;

	while(s[i] != '%')
	{
		write(1,&s[i],1);
		i++;
	}

	b = va_arg(ptr, int);
	write(1,&b,1);
	i++;
	i++;
	
	va_end(ptr);
	return (1);
}

int main(void)
{
	int a;

	a = ft_printf("this is =%c and this is =%c", 's', 'f');
}
