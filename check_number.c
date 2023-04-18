/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:55:45 by ybargach          #+#    #+#             */
/*   Updated: 2023/04/18 01:37:10 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlent(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (str[0] == ' ')
		b--;
	while (str[a])
	{
		if (str[a] == ' ')
			b++;
		a++;
	}
	if (str[a - 1] == ' ')
		b--;
	b++;
	return (b);
}

void	check_repeated(int *number, int i)
{
	int	a;
	int	b;
	int	count;

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

int	check_int(long res)
{
	if (res < -2147483648 || res > 2147483647)
	{
		write(1, "error\n", 6);
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

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}
