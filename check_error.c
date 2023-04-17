#include "push_swap.h"

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
				write(1, "error\n", 6);
				exit(0);
			}
		}
		a++;
	}
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
				write(1, "error\n", 6);
				exit(0);
			}
		}
		if (!((str[a] >= '0' && str[a] <= '9') || str[a] == ' ' || str[a] == '+' || str[a] == '-'))
		{
			write(1, "error\n", 6);
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
			write(1, "error\n", 6);
			exit(0);
		}
}
