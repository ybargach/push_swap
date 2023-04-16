#ifndef GET_NEXT_SPACE_H
# define GET_NEXT_SPACE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>


char	*get_next_line(char *ar);
int		count_world(char const *str, char c);
int		start_word(char const *str, char c, int a);
int		end_word(char const *str, char c, int a);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *str);
int		ft_strlen(const char *str);
void	ft_isdigit(char *str);
void	check_repeated(int *number);


#endif
