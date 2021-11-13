#include "pushswap.h"

void	ra(t_num *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_num *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_num *a, t_num *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_num *a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_num *b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}