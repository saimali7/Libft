#include "pushswap.h"
#include "sort_utils.c"

void	sa(t_num *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_num *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_num *a , t_num *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_num *a, t_num *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_num *b, t_num *a)
{
	push(b, a);
	write(1, "pb\n", 3);
}