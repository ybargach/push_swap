/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:56:04 by ybargach          #+#    #+#             */
/*   Updated: 2023/04/17 23:46:34 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first(char const *s1, char const *s2)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s1[a] && s2[b])
	{
		if (s1[a] == s2[b])
		{
			b = 0;
			a++;
		}
		else if (s1[a] != s2[b])
			b++;
	}
	return (a);
}

int	last(char const *s1, char const *s2)
{
	int	a;
	int	b;

	a = (int)ft_strlen(s1) - 1;
	b = 0;
	while (s1[a] && s2[b])
	{
		if (s1[a] == s2[b])
		{
			b = 0;
			a--;
		}
		else if (s1[a] != s2[b])
			b++;
	}
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	int		c;
	int		size;
	char	*p;

	if (!s1 || !set)
		return (0);
	a = first(s1, set);
	b = last(s1, set);
	c = 0;
	if (a == (int)ft_strlen(s1))
		return (ft_strdup(""));
	else
		size = b - a + 1;
	p = malloc((size + 1) * sizeof(char));
	if (!p)
		return (0);
	while (a <= b)
		p[c++] = s1[a++];
	p[c] = '\0';
	return (p);
}

int	word(char const *str, char c)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		while (str[a] == c && str[a])
		{
			a++;
		}
		while (str[a] != c && str[a])
		{
			a++;
		}
		count++;
	}
	return (count);
}

int	start(char *str, char c, int i)
{
	while (str[i] == c && str[i])
	{
		i++;
	}
	return (i);
}
