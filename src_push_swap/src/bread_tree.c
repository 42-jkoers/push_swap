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

bool	is_sorted_cmd(t_cmd *cmds, t_larr arr, size_t depth)
{
	t_all	all;
	size_t	i;
	bool	sorted;

	init_all(&all, arr.arr, arr.len);
	i = 0;
	while (i < depth)
	{
		execute(&all, cmds[i]);
		i++;
	}
	sorted = llst_issorted(all.a.lst) && all.b.len == 0;
	destroy_all(&all);
	return (sorted);
}

bool	tree(t_larr arr, t_cmd *cmds, size_t depth, size_t maxdepth)
{
	while (next_cmd(cmds, depth))
	{
		if (depth + 1 == maxdepth)
		{
			if (is_sorted_cmd(cmds, arr, depth))
				return (true);
		}
		else
		{
			if (tree(arr, cmds, depth + 1, maxdepth))
				return (true);
			cmds[depth + 1] = 0;
		}
	}
	return (false);
}

void	brute_force(t_larr arr)
{
	t_cmd	cmds[MAXDEPTH];
	size_t	depth;
	size_t	i;

	depth = 1;
	if (is_sorted_cmd(cmds, arr, 0))
		return ;
	while (true)
	{
		ft_bzero(cmds, sizeof(cmds));
		if (tree(arr, cmds, 0, depth))
			break ;
		depth++;
		if (depth >= MAXDEPTH)
			ft_exit_err("not found");
	}
	i = 0;
	while (i + 1 < depth)
	{
		ft_putstr(cmd_to_str(cmds[i]));
		ft_putstr("\n");
		i++;
	}
}
