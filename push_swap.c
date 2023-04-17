#include "push_swap.h"

int ft_strlent(char *str)
{
    int a = 0;
    int b = 0;
	if (str[0] == ' ')
		b--;
    while (str[a])
    {
        if(str[a] == ' ')
            b++;
        a++;
    }
	if (str[a - 1] == ' ')
		b--;
    b++;
    return (b);
}

void	check_all(char **av, int ac, int f)
{
	int a = 1;
	int b;
	int c = 0;
	char **afva;
	long b_number;
	int number[f];
	while (a < ac)
	{
		ft_isdigit(av[a]);
		afva = ft_split(av[a], ' ');
		if (afva[0] == NULL)
		{
			write(1, "error\n", 6);
			exit(0);
		}
		b = 0;
		while (afva[b])
		{
			check_op(afva[b]);
			b_number = ft_atoi(afva[b]);
			number[c] = check_int(b_number);
			c++;
			b++;
		}
		a++;
	}
	//check_sort(number, f);
	check_repeated(number, c);
	stack	*A = NULL;
	stack	*B = NULL;
	int g = 0;
	while (g < c)
	{
		add_back(&A, number[g]);
		g++;
	}

	//sort_three(&A);
	//sort_five(&A, &B);
	//sortStack(&test);
	//printf("stack ---- A -----\n");
	sort_five_hundred(&A,&B,f);
	// printf("stack ---- A2 -----\n");
	// while (A != NULL)
	// {
	// 	printf("%d\n", A->x);
	// 	A = A->next;
	// }
	// printf("stack ---- B -----\n");
	// while (B != NULL)
	// {
	// 	printf("%d\n", B->x);
	// 	B = B->next;
	// }
	
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
	if (ac > 1)
	{
		int	a;

		a = lenght_array(av);
		check_all(av, ac, a);
	}
	else
		write(1, "error\n", 6);
}