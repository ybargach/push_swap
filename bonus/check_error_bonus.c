/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:24:18 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/17 14:24:18 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	put_error(char **arr)
{
	if (arr[0] == NULL)
	{
		ft_free_arr(arr);
		write(1, "error\n", 6);
		exit(0);
	}
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
