/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:55:34 by ybargach          #+#    #+#             */
/*   Updated: 2023/04/17 18:55:34 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_count(int count)
{
	if (count == 0)
	{
		exit(0);
	}
}

void	put_error(char **arr)
{
	if (arr[0] == NULL)
	{
		ft_free_arr(arr);
		write(1, "error\n", 6);
		exit(0);
	}
}

void	check_sort(t_data res, int index)
{
	int	a;
	int	b;
	int	tmp;
	int	count;

	a = 0;
	count = 0;
	while (a < index)
	{
		b = a + 1;
		while (b < index)
		{
			if (res.number[a] > res.number[b])
			{
				tmp = res.number[a];
				res.number[a] = res.number[b];
				res.number[b] = tmp;
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
		if (str[a] == '+' || str[a] == '-')
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
		if (!((str[a] >= '0' && str[a] <= '9')
				|| str[a] == ' ' || str[a] == '+' || str[a] == '-'))
		{
			write(1, "error\n", 6);
			exit(0);
		}
		a++;
	}
}
