#include "constants.h"

static void	step_2(t_all *all)
{
	ssize_t	biggest_i;

	biggest_i = get_biggest_number_i(all->b.lst);
	while (biggest_i != -1)
	{
		if (biggest_i < all->b.len / 2)
			execute_n(all, RB, biggest_i);
		else
			execute_n(all, RRB, all->b.len - biggest_i);
		execute(all, PA);
		biggest_i = get_biggest_number_i(all->b.lst);
	}
}

void	sort(t_all *all)
{
	long	max;

	if (llst_issorted(all->a.lst))
		return ;
	max = 0;
	while (max <= (long)all->n_elements)
	{
		max += all->chunksize;
		sort_chunk(all, max);
	}
	step_2(all);
}
