#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <stddef.h>
# include <stdbool.h>
# include "llst.h"
# include "libft/include/libft.h"
# include <stdio.h> // illegal

# define ALLOW_DUPES 0

typedef struct s_stack
{
	t_llst	*lst;
	size_t	len;
}		t_stack;

typedef struct s_all
{
	t_stack	a;
	t_stack	b;
	long	*sorted;
	size_t	n_elements;
	bool	print;
	size_t	operations;
}		t_all;

bool	strtol_clamp(long *num, const char *str, long min, long max);
void	exit_err(const char *msg);
void	print_stack(const t_all *stacks);
void	fill_all(t_all *all, int argc, char **argv);
void	print_arr(const t_all *stacks);
long	biggest(t_llst *lst, size_t len);
long	smallest(t_llst *lst, size_t len);
void	sort(t_all *stacks);
void	execute(t_all *all, const char *cmd);

#endif
