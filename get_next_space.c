#include "push_swap.h"
static int	first(char const *s1, char const *s2)
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

static int	last(char const *s1, char const *s2)
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

static int	word(char const *str, char c)
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

static int	start(char *str, char c, int i)
{
	while (str[i] == c && str[i])
	{
		i++;
	}
	return (i);
}

static int	end(char *str, char c, int i)
{
	while (str[i] != c && str[i])
	{
		i++;
	}
	return (i);
}

static char	*trim(char const *s, char c)
{
	char	*t;
	char	*str;

	if (!s)
		return (0);
	t = (char *)malloc(2 * sizeof(char));
	if (!t)
		return (0);
	t[0] = c;
	t[1] = '\0';
	str = ft_strtrim(s, t);
	free(t);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	char	*str;
	int		b;
	int		x;
	int		y;

	if (!s)
		return (0);
	str = trim(s, c);
	b = 0;
	x = 0;
	y = 0;
	p = (char **)malloc((word(str, c) + 1) * sizeof(char *));
	if (!p || !str)
		return (0);
	while (b < word(str, c))
	{
		x = start(str, c, y);
		y = end(str, c, x);
		p[b] = ft_substr(str, x, (y - x));
		b++;
	}
	p[b] = NULL;
	free(str);
	return (p);
}