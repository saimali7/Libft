#include "pushswap.h"
#include "errorcheck_utils.c"

void	dup_check_num(int *arry, int i)
{
	int	k;
	
	k = 0;
	i = i - 1;
	while (i > 0)
	{
		k = i - 1;
		while (k >= 0)
		{
			if (arry[i] == arry[k])
			{
				free (arry);
				write(2, "ERROR\n", 6);
				exit (0);
			}
			k--;
		}
		i--;
	}
}

void	dup_check(int argc, char *argv[])
{
	int *arry;
	int i;

	i = 0;
	arry = (int *) malloc((argc - 1) * (sizeof(int)));
	while (argc > 1)
	{
		arry[i] = ft_atoi(argv[argc - 1]);
		i++;
		argc--;
	}
	dup_check_num(arry, i);
	free (arry);
}


void	limit_check(int argc, char *argv[])
{
	int num;

	num = 0;
	while (argc > 1)
	{
		num = ft_atoi(argv[argc - 1]);
		if ((num == 0 || num == -1) && zero_one(argv[argc - 1]) == 0)
		{
			write(2,"ERROR\n",6);
			exit(0);
		}
		argc--;
	}
}

void	number_check(int argc, char *argv[])
{
	int s;
	int j;

	j = 0;
	s = argc;
	while (s > 1)
	{
		j = 0;
		while (argv[s - 1][j] != '\0')
		{
			
			if (digit(argv[s - 1][j]) == 0 && !(argv[s - 1][0] == '-' && digit(argv[s - 1][1]) == 1))
			{
				write(2,"ERROR\n",6);
				exit(0);
			}
			j++;
		}
		s--;
	}
}

void	errorcheck(int argc, char *argv[])
{
	number_check(argc, argv);
	limit_check(argc, argv);
	dup_check(argc, argv);
}