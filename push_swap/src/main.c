#include "constants.h"
#include "libft/include/libft.h"
#include <stdlib.h>

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

long	to_number(const char *s, t_llst *stack)
{
	long	l;

	if (!is_digitstr(s))
		exit_err("Input contains non digit value");
	l = ft_strtonum((char *)s);
	if (!ALLOW_DUPES && contains_i(stack, l))
		exit_err("Input contains duplicates");
	return (l);
}

void	fill_all(t_all *all, int argc, char **argv)
{
	int		i;
	long	l;

	all->a.lst = NULL;
	all->b.lst = NULL;
	all->sorted = ft_malloc((argc - 1) * sizeof(long));
	i = 0;
	while (i < argc - 1)
	{
		l = to_number(argv[i + 1], all->a.lst);
		llst_push_back(&all->a.lst, l);
		all->sorted[i] = l;
		i++;
	}
	sort_l(all->sorted, argc - 1);
	all->n_elements = argc - 1;
	all->a.len = argc - 1;
	all->b.len = 0;
}

int	main(int argc, char **argv)
{
	t_all	stacks;

	fill_all(&stacks, argc, argv);
	sort(&stacks);
	print_stack(&stacks);
	print_arr(&stacks);
	exit(0);
	return (0);
}
