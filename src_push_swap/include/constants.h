#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <stddef.h>
# include <stdbool.h>
# include "libft/include/libft.h"
# include "stack/include/all.h"
# include <stdio.h> // illegal

void	map_stack(t_stack *stack);
void	print_stack(const t_all *all);
ssize_t	get_biggest_number_i(const t_llst *lst);
void	sort_chunk(t_all *all, long item_max);
void	sort(t_all *all);
bool	is_sorted(const t_llst *lst);

#endif
