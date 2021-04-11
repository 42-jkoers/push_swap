#include "../include/all.h"

static void	execute2(t_all *all, const char *cmd)
{
	if (!ft_strcmp("rra", cmd))
		reverse_rotate(&all->a);
	else if (!ft_strcmp("rrb", cmd))
		reverse_rotate(&all->b);
	else if (!ft_strcmp("rrr", cmd))
	{
		reverse_rotate(&all->a);
		reverse_rotate(&all->b);
	}
	all->operations++;
	if (all->print)
	{
		ft_putstr(cmd);
		ft_putstr("\n");
	}
}

void	execute(t_all *all, const char *cmd)
{
	if (!ft_strcmp("sa", cmd))
		swap(&all->a);
	else if (!ft_strcmp("sb", cmd))
		swap(&all->b);
	else if (!ft_strcmp("ss", cmd))
	{
		swap(&all->a);
		swap(&all->b);
	}
	else if (!ft_strcmp("pa", cmd))
		push(&all->b, &all->a);
	else if (!ft_strcmp("pb", cmd))
		push(&all->a, &all->b);
	else if (!ft_strcmp("ra", cmd))
		rotate(&all->a);
	else if (!ft_strcmp("rb", cmd))
		rotate(&all->b);
	else if (!ft_strcmp("rr", cmd))
	{
		rotate(&all->a);
		rotate(&all->b);
	}
	execute2(all, cmd);
}

void	execute_n(t_all *all, const char *cmd, size_t n)
{
	while (n > 0)
	{
		n--;
		execute(all, cmd);
	}
}
