/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:56:53 by ybargach          #+#    #+#             */
/*   Updated: 2023/04/17 18:56:53 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_index(t_stack **A, t_stack **B, int index)
{
	if (index > 1 && index <= 3)
		sort_three(A);
	else if (index > 3 && index <= 5)
		sort_five(A, B, index);
	else if (index > 5 && index <= 200)
		sort_one_hundred(A, B, index);
	else if (index > 200)
		sort_five_hundred(A, B, index);
}

void	put_in_stack(int *number, int c, int f)
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
	check_index(&a, &b, c);
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
	put_in_stack(arr.number, arr.c, f);
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
