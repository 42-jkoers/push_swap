#ifndef ALL_H
# define ALL_H

# include <stddef.h>
# include <stdbool.h>
# include <stdio.h> // illegal
# include "../../libft/include/libft.h"

# define ALLOW_DUPES 1

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

void	init_all(t_all *all, const long *arr, size_t len);
void	destroy_all(t_all *all);
long	*read_input(int argc, char **argv);
void	execute(t_all *all, const char *cmd);
void	execute_n(t_all *all, const char *cmd, size_t n);

#endif
