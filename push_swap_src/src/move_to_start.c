#include "constants.h"
#include <limits.h>

// unsigned long	move_to_top_operations(const t_all *all, size_t i)
// {
// 	if (i <= all->n_elements / 2)
// 		return (i);
// 	return ((all->n_elements - i) - 1);
// }

// find the first number from the top of the stack that is inside the chunk
ssize_t	top(
	const t_llst *lst, long max)
{
	size_t	i;
	t_llst	*current;

	i = 0;
	current = (t_llst *)lst;
	while (current)
	{
		if (current->l <= max)
			return (i);
		i++;
		current = current->next;
	}
	return (-1);
}

// find the first number from the bottom of the stack that is inside the chunk
ssize_t	bottom(
	const t_llst *lst, long max)
{
	size_t	i;
	t_llst	*current;
	ssize_t	best;

	i = 0;
	current = (t_llst *)lst;
	best = -1;
	while (current)
	{
		if (current->l <= max)
			best = i;
		i++;
		current = current->next;
	}
	return (best);
}

bool	move_to_start(t_all *all, long item_max)
{
	ssize_t	top_i;
	ssize_t	bottom_i;

	top_i = top(all->a.lst, item_max);
	bottom_i = bottom(all->a.lst, item_max);
	if (top_i == -1 || bottom_i == -1)
		return (false);
	if (top_i < all->a.len)
		execute_n(all, "ra", top_i);
	else
		execute_n(all, "rra", all->a.len - bottom_i);
	return (true);
}

ssize_t	get_biggest_number_i(const t_llst *lst)
{
	size_t	i;
	t_llst	*current;
	size_t	best_i;
	long	biggest;

	i = 0;
	current = (t_llst *)lst;
	best_i = -1;
	biggest = LONG_MIN;
	while (current)
	{
		if (current->l > biggest)
		{
			biggest = current->l;
			best_i = i;
		}
		i++;
		current = current->next;
	}
	return (best_i);
}

void	step_2(t_all *all)
{
	ssize_t	biggest_i;

	biggest_i = 0;
	while (biggest_i != -1)
	{
		biggest_i = get_biggest_number_i(all->b.lst);
		if (biggest_i < all->b.len)
			execute_n(all, "rb", biggest_i);
		else
			execute_n(all, "rrb", all->b.len - biggest_i);

		execute(all, "pa");
	}
}

void	sort_chunk(t_all *all, long item_max)
{
	while (move_to_start(all, item_max))
	{
		execute(all, "pb");
	}
}
