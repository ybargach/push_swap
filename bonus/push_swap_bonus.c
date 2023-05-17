/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:23:14 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/17 14:23:14 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	put_in_stack(int *number, int c)
{
	t_stack	*a;
	t_stack	*b;
	int		g;

	a = NULL;
	b = NULL;
	g = 0;
	check_repeated(number, c);
	while (g < c)
	{
		add_back(&a, number[g]);
		g++;
	}
	main_checker(&a, &b);
	free_node(&a);
}

void	check_all(char **av, int ac, int f)
{
	t_data	arr;
	char	**afva;
	long	b_number;

	arr.a = 1;
	arr.c = 0;
	arr.number = malloc(f * sizeof(int));
	while (arr.a < ac)
	{
		ft_isdigit(av[arr.a]);
		afva = ft_split(av[arr.a], ' ');
		put_error(afva);
		arr.b = 0;
		while (afva[arr.b])
		{
			check_op(afva[arr.b]);
			b_number = ft_atoi(afva[arr.b]);
			arr.number[arr.c] = check_int(b_number);
			arr.c++;
			arr.b++;
		}
		ft_free_arr(afva);
		arr.a++;
	}
	put_in_stack(arr.number, arr.c);
}

int	lenght_array(char **av)
{
	int	a;
	int	b;
	int	c;

	a = 1;
	b = 0;
	c = 0;
	while (av[a])
	{
		b = ft_strlent(av[a]);
		c = c + b;
		a++;
	}
	return (c);
}

int	main(int ac, char **av)
{
	int	a;

	if (ac > 1)
	{
		a = lenght_array(av);
		check_all(av, ac, a);
	}
	else
		write(1, "error\n", 6);
	return (0);
}
