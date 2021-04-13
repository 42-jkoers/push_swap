#include "constants.h"
#define	MAXDEPTH 12

bool	is_useless_operation(t_cmd prev, t_cmd new)
{
	if (prev == SA && new == SA)
		return (true);
	if (prev == SB && new == SB)
		return (true);
	if (prev == SS && new == SS)
		return (true);
	if ((prev == RA && new == RRA) || (prev == RRA && new == RA))
		return (true);
	if ((prev == RB && new == RRB) || (prev == RRB && new == RB))
		return (true);
	if ((prev == RR && new == RRR) || (prev == RRR && new == RR))
		return (true);
	return (false);
}

bool	next_cmd(t_cmd *cmds, size_t depth)
{
	if (depth >= 1 && is_useless_operation(cmds[depth - 1], cmds[depth]))
		cmds[depth]++;
	if (cmds[depth] == INVALID)
		return (false);
	cmds[depth]++;
	if (cmds[depth] == INVALID)
		return (false);
	return (true);
}

bool	is_sorted_cmd(t_cmd *cmds, const long *arr, size_t len)
{
	t_all	all;
	size_t	i;
	bool	sorted;

	init_all(&all, arr, len);
	i = 0;
	while (i < MAXDEPTH && cmds[i] != INVALID)
	{
		execute(&all, cmds[i]);
		i++;
	}
	sorted = is_sorted(all.a.lst) && all.b.len == 0;
	destroy_all(&all);
	return (sorted);
}

bool	tree(const long *arr, size_t len, t_cmd *cmds, size_t depth, size_t maxdepth)
{
	while (next_cmd(cmds, depth))
	{
		if (depth + 1 == maxdepth)
		{
			if (is_sorted_cmd(cmds, arr, len))
				return (true);
		}
		else
		{
			if (tree(arr, len, cmds, depth + 1, maxdepth))
				return (true);
			cmds[depth + 1] = 0;
		}
	}
	return (false);
}

void	brute_force(const long *arr, size_t len)
{
	t_cmd	cmds[MAXDEPTH];
	size_t	maxdepth;
	size_t	i;

	maxdepth = 1;
	cmds[0] = 0;
	if (is_sorted_cmd(cmds, arr, len))
		return ;
	while (true)
	{
		ft_bzero(cmds, sizeof(cmds));
		if (tree(arr, len, cmds, 0, maxdepth))
			break ;
		maxdepth++;
		if (maxdepth >= MAXDEPTH)
			ft_exit_err("not found");
	}
	i = 0;
	while (i < MAXDEPTH && cmds[i])
	{
		ft_putstr(cmd_to_str(cmds[i]));
		ft_putstr("\n");
		i++;
	}
}
