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
	long	smallest_a;

	while (all->a.len > 0)
	{
		smallest_a = smallest(all->a.lst, all->a.len);
		while (all->a.lst->l != smallest_a)
			execute(all, "ra");
		execute(all, "pb");
	}
	while (all->b.len > 0)
		execute(all, "pa");
}
