#include "../include/all.h"
#include <limits.h>

// push all numbers (preserver order) to stack a
// make stack b empty

static void	fill_stacks_ab(t_stack *a, t_stack *b, const long *arr, size_t len)
{
	size_t	i;

	a->lst = NULL;
	b->lst = NULL;
	i = 0;
	while (i < len)
	{
		llst_push_back(&a->lst, arr[i]);
		i++;
	}
	a->len = len;
	b->len = 0;
}

// initialize *all struct with standard values
void	init_all(t_all *all, const long *arr, size_t len)
{
	fill_stacks_ab(&all->a, &all->b, arr, len);
	all->n_elements = len;
	all->chunksize = len / 2;
	all->print = false;
	all->operations = 0;
}

void	destroy_all(t_all *all)
{
	llst_clear(&all->a.lst);
	llst_clear(&all->b.lst);
}

char	*cmd_to_str(t_cmd cmd)
{
	static char	*cmds[] = {
		"ss",
		"rr",
		"rrr",
		"ra",
		"sa",
		"pb",
		"rra",
		"rb",
		"sb",
		"pa",
		"rrb",
		NULL
	};
	return (cmds[cmd]);
}

t_cmd	str_to_cmd(const char *str)
{
	static char	*cmds[] = {
		"ss",
		"rr",
		"rrr",
		"ra",
		"sa",
		"pb",
		"rra",
		"rb",
		"sb",
		"pa",
		"rrb",
		NULL
	};
	ssize_t		i;

	i = ft_arrchr((char **)cmds, (char *)str);
	if (i == -1)
		return (INVALID);
	else
		return (i);
}