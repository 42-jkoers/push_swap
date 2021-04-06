#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <stddef.h>
# include <stdbool.h>
# include "llst.h"
# include "libft/include/libft.h"
# include <stdio.h> // illegal

# define ALLOW_DUPES 1

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

bool	strtol_clamp(long *num, const char *str, long min, long max);
void	exit_err(const char *msg);
void	sort_l(long *arr, size_t len);
void	print_stack(const t_all *all);
void	init_all(t_all *all, const long *arr, size_t len);
void	map_stack(t_stack *stack);
void	sort(t_all *all);
void	execute(t_all *all, const char *cmd);
void	execute_n(t_all *all, const char *cmd, size_t n);
void	sort_chunk(t_all *all, long item_max);
void	step_2(t_all *all);
void	destroy_all(t_all *all);
ssize_t	get_biggest_number_i(const t_llst *lst);
long	*read_input(int argc, char **argv);
bool	is_sorted(const t_llst *lst);

#endif
