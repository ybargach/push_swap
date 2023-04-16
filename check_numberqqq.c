#include "push_swap.h"

int	check_int(long res)
{
	if (res < -2147483648 || res > 2147483647)
	{
		write(1, "error\n", 7);
		exit(0);
	}
	return (res);
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
