#include "constants.h"

// small to big
bool	is_sorted(const t_llst *lst)
{
	t_llst	*l;

	l = (t_llst *)lst;
	while (l && l->next)
	{
		if (l->l > l->next->l)
			return (false);
		l = l->next;
	}
	return (true);
}

long	biggest(t_llst *lst, size_t len)
{
	long	biggest;

	if (len == 0)
		return (0);
	biggest = lst->l;
	while (lst)
	{
		if (lst->l > biggest)
			biggest = lst->l;
		lst = lst->next;
	}
	return (biggest);
}

long	smallest(t_llst *lst, size_t len)
{
	long	smallest;

	if (len == 0)
		return (0);
	smallest = lst->l;
	while (lst)
	{
		if (lst->l < smallest)
			smallest = lst->l;
		lst = lst->next;
	}
	return (smallest);
}

void	sort(t_all *all)
{
	long	max;

	max = 0;
	while (max < (long)all->n_elements)
	{
		sort_chunk(all, max);
		max += all->chunk_size;
	}
	step_2(all);
}
