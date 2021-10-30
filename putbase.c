#include <stdio.h>
#include <unistd.h>
#include <string.h>

void    ft_putchar(char a)
{
    write(1,&a,1);
}

void    ft_putbase(int a, char *base)
{
    int lenbase;
    int hold;

    lenbase = strlen(base);
    if (a > 0)
    {
        ft_putbase (a / lenbase, base);
        ft_putchar (base[a % lenbase]);
    }
}

int main() {
    // Write C code here
ft_putbase(969669676, "0123456789ABCDEF");
    ft_putchar('\n');
   printf("%x\n", 969669676);
    return 0;
}