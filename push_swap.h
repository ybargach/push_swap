# ifndef PUSH_SWAP
# define PUSH_SWAP


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

typedef struct stack {
	int x;
	struct stack* next;
} stack;

typedef struct data {
	int	a;
	int	b;
	int	*number;
	int	arr_size;
	int	new_arr_size;
	int	chunk_size;
	int	mid_number;
	int	max_number;
	long	high_number1;
	long	high_number2;
	int	move;
	int	index_1;
	int	index_2;
	int save1;
	int save2;
	stack	*newnode;
	stack	*secondnode;
} data;


//stack
void	higher_lower(stack **a, stack **b, data arr);
void	sb(stack **elem);
void	top_number_in_high(stack **a, stack **b, data arr);
void	top_number_in_lowe(stack **a, stack **b, data arr);
void	push_A_to_B(stack **elem, stack **node, data arr);
void	higher_half(stack **a, stack **b, data arr);
void	lower_half(stack **a, stack **b, data arr);
void	push_b(stack **src, stack **dst);
void	max_number(stack **elem, stack **node, data arr);
void	check_sorb_b(stack **elem, stack **node);
void	push(stack **src, stack **dst);
void	sort_five(stack **elem, stack **node);
void	sort_three(stack **elem);
void	free_node(stack **elem);
void	ft_node(stack **elem, int value);
void	add_first(stack **elem, int value);
void	add_back(stack **elem, int value);
int		stack_size(stack *elem);
void	ra(stack **elem);
void	rb(stack **data);
void	rra(stack **elem);
void	rrb(stack **elem);
void	sa(stack **elem);
stack	*last_node(stack **elem);
stack	*create_node(int value);

//check
void	check_less(stack **elem, stack **node, data arr);
void	put_array(stack **elem, stack **node, int index);
void	check_sort(int *res, int index);
void	check_count(int count);
int		check_int(long res);
char	*ft_strtrim(char const *s1, char const *set);
long	ft_atoi(const char *str);
void	ft_isdigit(char *str);
void	check_op(const char *str);
void	check_repeated(int *number, int i);
char	**ft_split(char const *str, char c);
int		end_word(char const *str, char c, int a);
int		start_word(char const *str, char c, int a);
int		count_world(char const *str, char c);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);

# endif