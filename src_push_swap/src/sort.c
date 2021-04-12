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

bool	next_cmd(char **cmd, size_t *offset, const t_all *all)
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

	if (*offset <= 2 && (all->a.len <= 1 || all->b.len <= 1))
		*offset = 3;
	if (*offset <= 6 && all->a.len <= 1)
		*offset = 7;
	if (*offset >= 7 && all->b.len <= 1)
		return (false);
	if (cmds[*offset] == NULL)
		return (false);
	*cmd = cmds[*offset];
	(*offset)++;
	return (true);
}

bool	tree(const long *arr, size_t len, char **cmds, size_t depth, size_t *offsets)
{
	char	*cmd;
	t_all	all;

	init_all(&all, arr, len);
	while (next_cmd(&cmds[depth], &offsets[depth], &all))
	{
		execute(&all, cmds[depth]);
		if (is_sorted(all.a.lst))
		{
			destroy_all(&all);
			return (true);
		}
		if (depth + 1 < MAXDEPTH)
		{
			if (tree(arr, len, cmds, depth + 1, offsets))
				return (true);
		}
	}
	destroy_all(&all);
	return (false);
}

void	brute_force(const long *arr, size_t len)
{
	size_t	offsets[MAXDEPTH];
	char	*cmds[MAXDEPTH];
	size_t	depth;
	size_t	i;

	ft_bzero(offsets, sizeof(offsets));
	ft_bzero(cmds, sizeof(cmds));
	tree(arr, len, cmds, 0, offsets);
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
