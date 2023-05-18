/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:57:06 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/18 10:53:09 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_save(char *str)
{
	int		a;
	int		b;
	char	*p;

	if (!str)
		return (NULL);
	a = 0;
	b = 0;
	while (str[a] && str[a] != '\n')
		a++;
	if (!str[a] || !str[a + 1])
		return (free(str), NULL);
	p = malloc((ft_strlen(str) - a) * sizeof(char));
	if (!p)
		return (NULL);
	a++;
	while (str[a])
		p[b++] = str[a++];
	p[b] = '\0';
	free(str);
	return (p);
}

char	*ft_line(char *str)
{
	int		a;
	int		b;
	char	*p;

	if (!str)
		return (NULL);
	a = 0;
	b = 0;
	while (str[a] && str[a] != '\n')
		a++;
	if (str[a] == '\n')
		a++;
	p = malloc((a + 1) * sizeof(char));
	if (!p)
		return (NULL);
	a = 0;
	while (str[a] && str[a] != '\n')
		p[b++] = str[a++];
	if (str[a] == '\n')
	{
		p[b] = str[a];
		b++;
	}
	p[b] = '\0';
	return (p);
}

char	*ft_read(char *stock, int fd)
{
	int		a;
	char	*p;

	a = 1;
	p = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (!ft_strchr(stock, '\n') && a != 0)
	{
		a = read(fd, p, BUFFER_SIZE);
		if (a == 0)
			break ;
		if (a == -1)
			return (free(p), free(stock), NULL);
		p[a] = '\0';
		stock = ft_strjoin(stock, p);
	}
	free(p);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*str;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	stock = ft_read(stock, fd);
	if (!stock)
		return (NULL);
	str = ft_line(stock);
	stock = ft_save(stock);
	return (str);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (n > a)
	{
		if (!((*(unsigned char *)(s1 + a)) == (*(unsigned char *)(s2 + a))))
			return ((*(unsigned char *)(s1 + a))
					- (*(unsigned char *)(s2 + a)));
		a++;
	}
	return (0);
}
