#include "../include/all.h"

static void	execute2(t_all *all, t_cmd cmd)
{
	if (cmd == RRA)
		reverse_rotate(&all->a);
	else if (cmd == RRB)
		reverse_rotate(&all->b);
	else if (cmd == RRR)
	{
		reverse_rotate(&all->a);
		reverse_rotate(&all->b);
	}
	all->operations++;
	if (all->print)
	{
		ft_putstr(cmd_to_str(cmd));
		ft_putstr("\n");
	}
}

void	execute(t_all *all, t_cmd cmd)
{
	if (cmd == SA)
		swap(&all->a);
	else if (cmd == SB)
		swap(&all->b);
	else if (cmd == SS)
	{
		swap(&all->a);
		swap(&all->b);
	}
	else if (cmd == PA)
		push(&all->b, &all->a);
	else if (cmd == PB)
		push(&all->a, &all->b);
	else if (cmd == RA)
		rotate(&all->a);
	else if (cmd == RB)
		rotate(&all->b);
	else if (cmd == RR)
	{
		rotate(&all->a);
		rotate(&all->b);
	}
	execute2(all, cmd);
}

void	execute_n(t_all *all, t_cmd cmd, size_t n)
{
	while (n > 0)
	{
		n--;
		execute(all, cmd);
	}
}
