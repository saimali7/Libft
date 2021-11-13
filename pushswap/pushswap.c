#include "pushswap.h"
#include "./libft/ft_atoi.c"
#include "./libft/ft_strncmp.c"
#include "errorcheck.c"
#include "initialize.c"
#include "sort_cmds.c"
#include "sort_cmds_more.c"
#include "bubblesort.c"
#include <stdio.h>

int	check_flag(t_num *temp,int min, int max)
{
	int i;
	i = 0;
	while(i <= temp->top)
	{
		if (temp->ary[i] >= min && temp->ary[i] <= max)
		{
			return (1);
		}
		i++;
	}
	return (0);
}


int	check_flag_two(t_num *temp,int min, int max)
{
	int i;
	i = 0;
	while(i <= temp->top)
	{
		if (temp->ary[i] >= min && temp->ary[i] < max)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	biggest_num(t_num *temp)
{
	int i;
	int hold;

	hold = -2147483648;
	i = 0;
	while (i < temp->size && i <= temp->top)
	{
		if (temp->ary[i] > hold)
			hold = temp->ary[i];
		i++;
	}
	return (hold);
}

int *make_copy(t_num *temp)
{
	int i;
	int *copy;

	i = 0;
	copy = malloc(temp->size * sizeof(int));
	while(i < temp->size)
	{
		copy[i] = temp->ary[i];
		i++;
	}
	return (copy);
}

int	check_rvrotate(t_num *temp, int min, int max)
{
	int count;

	count = 0;
	while (!(temp->ary[temp->top] >= min && temp->ary[temp->top] <= max))
	{
		rev_rotate(temp);
		count++;
	}
	return (count);
}

int	check_rotate(t_num *temp, int min, int max)
{
	int count;

	count = 0;
	while (!(temp->ary[temp->top] >= min && temp->ary[temp->top] <= max))
	{
		rotate(temp);
		count++;
	}
	return (count);
}

void	smart_arrange(t_num *temp, int min, int max)
{
	int revrotate;
	int rotate;
	t_num copystruct;

	revrotate = 0;
	rotate = 0;
	copystruct.ary = make_copy(temp);
	copystruct.top = temp->top;
	copystruct.size = temp->size;
	revrotate = check_rvrotate(&copystruct, min, max);
	free(copystruct.ary);
	copystruct.ary = make_copy(temp);
	rotate = check_rotate(&copystruct, min, max);
	free(copystruct.ary);
	if (revrotate < rotate)
	{
		while (!(temp->ary[temp->top] >= min && temp->ary[temp->top] <= max))
		rrb(temp);
	}
	else
	{
		while (!(temp->ary[temp->top] >= min && temp->ary[temp->top] <= max))
		rb(temp);
	}
}

void	sort_chunk(t_num *a, t_num *b, int min, int max)
{
	int	flag;

	flag = 1;
	while (flag == 1)
	{
		if (a->ary[a->top] >= min && a->ary[a->top] <= max)
			pb(b, a);
		else
			smart_arrange(a, min, max);
		flag = check_flag(a, min, max);
	}
}



void	set_min_max(t_num *a,int *min, int *max)
{
	int size;

	size =  a->size;
	if (size <= 50)
	{
		*max = a->size - 1;
		*min = 0;
	}
	else if (size > 50)
	{
		if (*max == 0)
		{
			*max = a->size - 1;
			*min = *max - 49;
		}
		else if (max > 0)
		{
			*max = *min - 1;
			*min = *max - 49;
		}
	}
}

void	sort_atempt(t_num *a, t_num *b)
{
	while (b->top >= 0)
	{
		if ((b->ary[b->top]) == biggest_num(b))
			pa(a, b);
		else
			smart_arrange(b, biggest_num(b), biggest_num(b));
	}
}

void	sort_hundred(t_num *a, t_num *b)
{
	int min;
	int max;
	int chunks;
	int *ptr;

	ptr = bubble_sort(a);
	chunks = 5;
	min = 0;
	max = 0;
	while (chunks > 0)
	{
		set_min_max(a, &min, &max);
		sort_chunk(a, b, ptr[min], ptr[max]);
		chunks--;
	}
	sort_atempt(a, b);
	free (ptr);
}

void	sort_fivehun(t_num *a, t_num *b)
{
	int min;
	int max;
	int chunks;
	int *ptr;

	ptr = bubble_sort(a);
	chunks = 10;
	min = 0;
	max = 0;
	while (chunks > 0)
	{
		set_min_max(a, &min, &max);
		sort_chunk(a, b, ptr[min], ptr[max]);
		chunks--;
	}
	sort_atempt(a, b);
	free (ptr);
}

void	sort(int argc, char *argv[])
{
	t_num a;
	t_num b;
	init(argc, argv, &a, &b);
	if (a.size == 1)
		return ;
	// else if (a.size == 2)
	// {
	// 	sort_two(a);
	// 	return ;
	// }
	// else if (a.size ==  3)
	// {
	// 	sort_three();
	// 	return ;
	// }
	// else if (a.size <= 5)
	// 	sort_five();
	// 	return ;
	// if (a.size >= 100)
	// 	sort_hundred(&a, &b);
	if (a.size >= 500)
		sort_fivehun(&a, &b);
	// for (int i = 100; i > -1; i--)
	// 	printf("%d\n", a.ary[i]);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		errorcheck(argc, argv);
		sort(argc, argv);
	}
	return (0);
}