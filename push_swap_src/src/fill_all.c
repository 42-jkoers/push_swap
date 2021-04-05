#include "constants.h"
#include <limits.h>

bool	contains_i(t_llst *lst, long l)
{
	while (lst)
	{
		if (lst->l == l)
			return (true);
		lst = lst->next;
	}
	return (false);
}

long	str_to_number(const char *s, t_llst *lst)
{
	long	l;

	if (!strtol_clamp(&l, s, INT_MIN, INT_MAX))
		exit_err("Input contains non int value");
	if (!ALLOW_DUPES && contains_i(lst, l))
		exit_err("Input contains duplicates");
	return (l);
}

// push all numbers (preserver order) to stack a
// make stack b empty

void	fill_stacks(t_all *all, int argc, char **argv)
{
	int		i;

	all->a.lst = NULL;
	all->b.lst = NULL;
	i = 0;
	while (i < argc - 1)
	{
		llst_push_back(&all->a.lst, str_to_number(argv[i + 1], all->a.lst));
		i++;
	}
	all->a.len = argc - 1;
	all->b.len = 0;
}

void	fill_sorted(t_all *all, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		strtol_clamp(&all->sorted[i], argv[i + 1], INT_MIN, INT_MAX);
		i++;
	}
	sort_l(all->sorted, argc - 1);
}

void	fill_all(t_all *all, int argc, char **argv)
{
	fill_stacks(all, argc, argv);
	fill_sorted(all, argc, argv);
	all->n_elements = argc - 1;
	all->print = false;
	all->operations = 0;
}
