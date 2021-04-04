#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <stddef.h>
# include <stdbool.h>
# include "llst.h"
# include "libft/include/libft.h"
# include <stdio.h> // illegal

# define ALLOW_DUPES 1

typedef struct s_stacks
{
	t_llst	*a;
	t_llst	*b;
	size_t	a_len;
	size_t	b_len;
	long	*sorted;
}		t_stacks;

bool	is_digitstr(const char *str);
void	exit_err(const char *msg);
void	print_stack(const t_stacks *stacks);
void	sort_l(long *arr, size_t len);
void	print_arr(const t_stacks *stacks);
long	biggest(t_llst *lst, size_t len);
long	smallest(t_llst *lst, size_t len);
void	sort(t_stacks *stacks);

#endif
