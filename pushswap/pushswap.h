#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef	struct numdata
{
	int top;
	int size;
	int *ary;
}	t_num;

void	alloc(t_num *temp, int size);
void	cpy_num(int argc, char *argv[], t_num *temp);
void	init(int argc, char *argv[],t_num *a,t_num *b);

#endif