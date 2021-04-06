#include "constants.h"
// swap the first 2 elements at the top of stack.
// Do nothing if there is only one or no elements)

void	swap(t_stack *stack)
{
	t_llst	*old_start;

	if (stack->len < 2)
		return ;
	old_start = stack->lst;
	stack->lst = stack->lst->next;
	old_start->next = stack->lst->next;
	stack->lst->next = old_start;
}

// Take the first element at the top of *from and put it at the top of *to.
// Do nothing if *from is empty
void	push(t_stack *from, t_stack *to)
{
	t_llst	*old_to;

	if (from->len == 0)
		return ;
	old_to = to->lst;
	to->lst = from->lst;
	from->lst = from->lst->next;
	to->lst->next = old_to;
	to->len++;
	from->len--;
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one
void	rotate(t_stack *stack)
{
	t_llst	*old_lst;

	if (stack->len <= 1)
		return ;
	old_lst = stack->lst;
	stack->lst = stack->lst->next;
	llst_add_back(&stack->lst, old_lst);
	old_lst->next = NULL;
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one
void	reverse_rotate(t_stack *stack)
{
	t_llst	*current;

	if (stack->len <= 2)
	{
		rotate(stack);
		return ;
	}
	current = stack->lst;
	while (1)
	{
		if (!current->next->next)
		{
			current->next->next = stack->lst;
			stack->lst = current->next;
			current->next = NULL;
			break ;
		}
		current = current->next;
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
	else if (!ft_strcmp("rra", cmd))
		reverse_rotate(&all->a);
	else if (!ft_strcmp("rrb", cmd))
		reverse_rotate(&all->b);
	else if (!ft_strcmp("rrr", cmd))
	{
		reverse_rotate(&all->a);
		reverse_rotate(&all->b);
	}
	else
		exit_err("Invalid command");
	all->operations++;
	if (all->print)
	{
		ft_putstr(cmd);
		ft_putstr("\n");
	}
}

void	execute_n(t_all *all, const char *cmd, size_t n)
{
	while (n > 0)
	{
		n--;
		execute(all, cmd);
	}
}
