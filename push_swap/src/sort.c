#include "constants.h"
#include "swap.h"

// small to big
bool	is_sorted(t_llst *lst)
{
	while (lst && lst->next)
	{
		if (lst->l > lst->next->l)
			return (false);
		lst = lst->next;
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

void	sort(t_stacks *stacks)
{
	long	smallest_a;

	while (stacks->a_len > 0)
	{
		smallest_a = smallest(stacks->a, stacks->a_len);
		while (stacks->a->l != smallest_a)
			ra(stacks);
		pb(stacks);
	}
	while (stacks->b_len > 0)
		pa(stacks);
}
