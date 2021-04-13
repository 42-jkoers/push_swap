#ifndef ALL_H
# define ALL_H

# include <stddef.h>
# include <stdbool.h>
# include <stdio.h> // illegal
# include "../../libft/include/libft.h"

# define ALLOW_DUPES 0

typedef struct s_llst
{
	long			l;
	struct s_llst	*next;
}		t_llst;

t_llst	*llst_new(long l);
void	llst_push_back(t_llst **lst, long l);
void	llst_push_front(t_llst **lst, long l);
void	llst_add_front(t_llst **lst, t_llst *new);
void	llst_add_back(t_llst **lst, t_llst *new);
void	llst_clear(t_llst **lst);
void	llst_delone(t_llst *lst);
void	llst_iter(t_llst *lst, void (*f)(long));
size_t	llst_length(t_llst *lst);
t_llst	*llst_last(t_llst *lst);
bool	llst_issorted(const t_llst *lst); // small to big

typedef enum e_cmd
{
	SS,
	RR,
	RRR,
	RA,
	SA,
	PB,
	RRA,
	RB,
	SB,
	PA,
	RRB,
	INVALID,
}		t_cmd;
char	*cmd_to_str(t_cmd cmd);
t_cmd	str_to_cmd(const char *str);

typedef struct s_stack
{
	t_llst	*lst;
	size_t	len;
}		t_stack;

typedef struct s_all
{
	t_stack	a;
	t_stack	b;
	size_t	n_elements;
	size_t	chunksize;
	bool	print;
	size_t	operations;
}		t_all;

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	execute(t_all *all, t_cmd cmd);
void	execute_n(t_all *all, t_cmd cmd, size_t n);

void	init_all(t_all *all, const long *arr, size_t len);
void	destroy_all(t_all *all);
long	*read_input(int argc, char **argv);

#endif
