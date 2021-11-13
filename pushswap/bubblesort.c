#include "pushswap.h"

void	swap_int(int *temp, int j, int k)
{
	int hold;

	hold = temp[j];
	temp[j] = temp[k];
	temp[k] = hold;
}

int	*bubble_sort(t_num *a)
{
	int *temp;
	int i;
	int j;

	i = 0;
	temp = (int *) malloc(a->size * sizeof(int));
	while(i < a->size)
	{
		temp[i] = a->ary[i];
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if (temp[j] > temp[j + 1])
				swap_int(temp, j , j + 1);
			j++;
		}
		i++;
	}
	return (temp);
}

int is_sorted(int *arry, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if(arry[i] > arry[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}