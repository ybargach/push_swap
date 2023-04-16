#include "push_swap.h"

int	check_int(long res)
{
	if (res < -2147483648 || res > 2147483647)
	{
		printf("error");
		exit(0);
	}
	return (res);
}

void	check_count(int count)
{
	if (count == 0)
	{
		exit(0);
	}
}

void	check_sort(int *res, int index)
{
	int	a;
	int	b;
	int	tmp;
	int count;

	a = 0;
	count = 0;
	while (a < index)
	{
		b = a + 1;
		while (b < index)
		{
			if (res[a] > res[b])
			{
				tmp = res[a];
				res[a] = res[b];
				res[b] = tmp;
				count++;
			}
			b++;
		}
		a++;
	}
	check_count(count);
}

// int	check_midpoint(int *res, int index)
// {
// 	int	b = sizeof(res) / sizeof(int);
// 	printf("index --- %d \n", index);
// 	printf("b --- %d \n", b);
// 	int c = b/2;
// 	printf("c --- %d \n", c);
// 	return (c);
// }

void	check_op(const char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if(str[a] == '+' || str[a] == '-')
		{
			if (!(str[a + 1] >= '0' && str[a + 1] <= '9'))
			{
				printf("error");
				exit(0);
			}
		}
		a++;
	}
}

long	ft_atoi(const char *str)
{
	long			a;
	unsigned long	res;
	long			neg;

	a = 0;
	res = 0;
	neg = 1;
	while (str[a] == ' ')
		a++;
	if (str[a] == '-')
	{
		neg = -1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		res = res * 10 + str[a] - '0';
		a++;
	}
	return (res * neg);
}

void	ft_isdigit(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			if (str[a + 1] == '+' || str[a + 1] == '-')
			{
				printf("error");
				exit(0);
			}
		}
		if (!((str[a] >= '0' && str[a] <= '9') || str[a] == ' ' || str[a] == '+' || str[a] == '-'))
		{
			printf("error");
			exit(0);
		}
		a++;
	}   
}

void	check_repeated(int *number, int i)
{
	int	a;
	int b;
	int count;

	a = 0;
	count = 0;
	while (a < i)
	{
		b = a + 1;
		while (b < i)
		{
			if (number[a] == number[b])
				count++;
			b++;
		}
		a++;
	}
	if (count != 0)
		{
			printf("error");
			exit(0);
		}
}
