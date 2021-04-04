#include "constants.h"
#include "libft/include/libft.h"
#include <stdlib.h>
#include "swap.h"

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

void	fill_stacks(t_stacks *stacks, int argc, char **argv)
{
	int		i;
	long	l;

	stacks->a = NULL;
	stacks->b = NULL;
	stacks->sorted = ft_malloc((argc - 1) * sizeof(long));
	i = 0;
	while (i < argc - 1)
	{
		l = to_number(argv[i + 1], stacks->a);
		llst_push_back(&stacks->a, l);
		stacks->sorted[i] = l;
		i++;
	}
	sort_l(stacks->sorted, argc - 1);
	stacks->a_len = argc - 1;
	stacks->b_len = 0;
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	fill_stacks(&stacks, argc, argv);
	sort(&stacks);
	print_stack(&stacks);
	print_arr(&stacks);
	exit(0);
	return (0);
}
