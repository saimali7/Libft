#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1,&c,1);
}

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}


void    ft_putbase(unsigned long long num, char *base)
{
    int baselen;

    baselen = 0;
    baselen = ft_strlen(base);
    if(num > 0)
    {
        ft_putbase(num / baselen, base);
        ft_putchar(base[num % baselen]);
    }
}

int main() {
    // Write C code here
   printf("%lX\n",705060521525511235);
   ft_putbase(705060521525511235, "0123456789ABCDEF");
    // printf("%d", x);
    return 0;
}