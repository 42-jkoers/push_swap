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

static void	step_2(t_all *all)
{
	ssize_t	biggest_i;

	biggest_i = get_biggest_number_i(all->b.lst);
	while (biggest_i != -1)
	{
		if (biggest_i < all->b.len / 2)
			execute_n(all, "rb", biggest_i);
		else
			execute_n(all, "rrb", all->b.len - biggest_i);
		execute(all, "pa");
		biggest_i = get_biggest_number_i(all->b.lst);
	}
}

void	sort(t_all *all)
{
	long	max;

	if (is_sorted(all->a.lst))
		return ;
	max = 0;
	while (max <= (long)all->n_elements)
	{
		max += all->chunksize;
		sort_chunk(all, max);
	}
	step_2(all);
}
