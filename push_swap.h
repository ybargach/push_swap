# ifndef PUSH_SWAP
# define PUSH_SWAP


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct stack {
	int	x;
	struct stack*	next;
} stack;

typedef struct data {
	int		a;
	int		b;
	int		*number;
	int		arr_size;
	int		new_arr_size;
	int		chunk_size;
	int		mid_number;
	int		max_number;
	int		move;
	int		index_1;
	int		index_2;
	int 	save1;
	int 	save2;
	long	high_number1;
	long	high_number2;
	stack	*newnode;
	stack	*secondnode;
} data;

//stack

void	check_sorb_b(stack **elem, stack **node);

void	chunk_array(stack **elem, stack **node, data arr);
void	push_data_to_B(stack **a, stack **b, data arr);
void	check_less(stack **elem, stack **node, data arr);
void	max_number(stack **elem, stack **node, data arr);
void	check_higher_lower(stack **a, stack **b, data arr);
void	top_number_in_lower(stack **a, stack **b, data arr);
void	top_number_in_higher(stack **a, stack **b, data arr);
void	higher_half(stack **a, stack **b, data arr);
void	lower_half(stack **a, stack **b, data arr);
void	add_back(stack **elem, int value);
void	add_first(stack **elem, int value);
void	free_node(stack **elem);
void	sort_three(stack **elem);
void	sort_five(stack **elem, stack **node);
void	sort_one_hundred(stack **elem, stack **node, int index);
void	sort_five_hundred(stack **elem, stack **node, int index);
int		stack_size(stack *elem);
void	push(stack **src, stack **dst);
void	rra(stack **elem);
void	ra(stack **data);
void	sa(stack **elem);
void	push_B_to_A(stack **elem, stack **node, data arr);
void	push_b(stack **src, stack **dst);
void	rb(stack **data);
void	rrb(stack **elem);
void	sb(stack **elem);
stack	*last_node(stack **elem);
stack	*create_node(int value);

//check

int		ft_strlent(char *str);
void	check_all(char **av, int ac, int f);
int		lenght_array(char **av);
void	check_count(int count);
void	check_sort(int *res, int index);
void	check_op(const char *str);
void	ft_isdigit(char *str);
void	check_repeated(int *number, int i);
int		check_int(long res);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

//split

int		ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
// static int	first(char const *s1, char const *s2);
// static int	last(char const *s1, char const *s2);
// char	*ft_strtrim(char const *s1, char const *set);
// static int	word(char const *str, char c);
// static int	start(char *str, char c, int i);
// static int	end(char *str, char c, int i);
// static char	*trim(char const *s, char c);

# endif