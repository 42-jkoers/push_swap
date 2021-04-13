#include "constants.h"
#define	MAXDEPTH 12

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

bool	next_cmd(char **cmd, size_t *offset)
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

	// if (*offset <= 2 && (all->a.len <= 1 || all->b.len <= 1))
	// 	*offset = 3;
	// if (*offset <= 6 && all->a.len <= 1)
	// 	*offset = 7;
	// if (*offset >= 7 && all->b.len <= 1)
	// 	return (false);
	if (cmds[*offset] == NULL)
		return (false);
	*cmd = cmds[*offset];
	(*offset)++;
	return (true);
}

bool	is_sorted_cmd(char **cmds, const long *arr, size_t len)
{
	t_all	all;
	size_t	i;
	bool	sorted;

	init_all(&all, arr, len);
	i = 0;
	while (i < MAXDEPTH && cmds[i])
	{
		// printf("%s ", cmds[i]);
		execute(&all, cmds[i]);
		i++;
	}
	sorted = is_sorted(all.a.lst) && all.b.len == 0;
	destroy_all(&all);
	// printf("  %i\n", sorted);
	return (sorted);
}

bool	tree(const long *arr, size_t len, char **cmds, size_t depth, size_t *offsets, size_t maxdepth)
{

	while (next_cmd(&cmds[depth], &offsets[depth]))
	{
		if (depth + 1 == maxdepth)
		{
			if (is_sorted_cmd(cmds, arr, len))
				return (true);
		}
		else
		{
			if (tree(arr, len, cmds, depth + 1, offsets, maxdepth))
				return (true);
			offsets[depth + 1] = 0;
		}
	}
	return (false);
}

void	brute_force(const long *arr, size_t len)
{
	size_t	offsets[MAXDEPTH];
	char	*cmds[MAXDEPTH];
	size_t	maxdepth;
	size_t	i;

	maxdepth = 1;
	cmds[0] = NULL;
	if (is_sorted_cmd(cmds, arr, len))
		return ;
	while (true)
	{
		ft_bzero(offsets, sizeof(offsets));
		ft_bzero(cmds, sizeof(cmds));
		if (tree(arr, len, cmds, 0, offsets, maxdepth))
			break ;
		maxdepth++;
		if (maxdepth >= MAXDEPTH)
			ft_exit_err("not found");
	}
	i = 0;
	while (i < MAXDEPTH && cmds[i])
	{
		ft_putstr(cmds[i]);
		ft_putstr("\n");
		i++;
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
