#include "pushswap.h"

void	swap(t_num *temp)
{
	int top;
	int hold;

	hold = 0;
	if (temp != NULL)
	{
		top = temp->top;
		hold = temp->ary[top];
		temp->ary[top] = temp->ary[top - 1];
		temp->ary[top - 1] = hold;
	}
}

void	push(t_num *list_one, t_num *list_two)
{
	if ((list_two->top > -1) && (list_one != NULL && list_two != NULL))
	{
		list_one->ary[list_one->top + 1] = list_two->ary[list_two->top];
		list_one->top = list_one->top + 1;
		list_two->top = list_two->top - 1;
	}
}

void	rotate(t_num *list)
{
	int hold;
	int top;

	hold = 0;
	top = list->top;
	if (list != NULL && list->top > 0)
	{
		hold = list->ary[top];
		while(top > 0)
		{
			list->ary[top] = list->ary[top - 1];
			top--;
		}
		list->ary[0] = hold;
	}
}

void	rev_rotate(t_num *list)
{
	int hold;
	int bot;

	bot = 0;
	hold = 0;
	if (list != NULL && list->top > 0)
	{
		hold = list->ary[bot];
		while (bot < list->top)
		{
			list->ary[bot] = list->ary[bot + 1];
			bot++;
		}
		list->ary[list->top] = hold;
	}
}

void	rrr(t_num *a,t_num *b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}