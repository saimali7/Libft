#include "pushswap.h"

void	alloc(t_num *temp, int size)
{
	temp->ary =(int *) malloc(size * sizeof(int));
	temp->top = size - 1;
	temp->size = size;
}

void	cpy_num(int argc, char *argv[], t_num *temp)
{
	int i;
	int size;

	size = temp->size;
	i = 0;
	while(argc > 1)
	{
		temp->ary[i] = ft_atoi(argv[size]);
		i++;
		size--;
		argc--;
	}
}

void	init(int argc, char *argv[],t_num *a, t_num *b)
{
	
	alloc(a, argc - 1);
	alloc(b, argc - 1);
	b->top = -1;
	cpy_num(argc, argv, a);
}