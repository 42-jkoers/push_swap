#include "constants.h"
// swap the first 2 elements at the top of stack a.
// Do nothing if thereis only one or no elements)

// void	(t_stacks *stacks)

void	sa(t_stacks *stacks)
{
	t_llst	*old_start;

	if (stacks->a_len < 2)
		return ;
	old_start = stacks->a;
	stacks->a = stacks->a->next;
	old_start->next = stacks->a->next;
	stacks->a->next = old_start;
}

// swap the first 2 elements at the top of stack b.
// Do nothing if thereis only one or no elements)

void	sb(t_stacks *stacks)
{
	t_llst	*old_start;

	if (stacks->b_len < 2)
		return ;
	old_start = stacks->b;
	stacks->b = stacks->b->next;
	old_start->next = stacks->b->next;
	stacks->b->next = old_start;
}

// sa and sb at the same time.
void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

// push a - take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty
void	pa(t_stacks *stacks)
{
	t_llst	*old_a;

	if (stacks->b_len == 0)
		return ;
	old_a = stacks->a;
	stacks->a = stacks->b;
	stacks->b = stacks->b->next;
	stacks->a->next = old_a;
	stacks->a_len++;
	stacks->b_len--;
}

// push b - take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty
void	pb(t_stacks *stacks)
{
	t_llst	*old_b;

	if (stacks->a_len == 0)
		return ;
	old_b = stacks->b;
	stacks->b = stacks->a;
	stacks->a = stacks->a->next;
	stacks->b->next = old_b;
	stacks->b_len++;
	stacks->a_len--;
}

// rotate a - shift up all elements of stack a by 1.
// The first element becomes the last one
void	ra(t_stacks *stacks)
{
	t_llst	*old_a;

	if (stacks->a_len <= 1)
		return ;
	old_a = stacks->a;
	stacks->a = stacks->a->next;
	llst_add_back(&stacks->a, old_a);
	old_a->next = NULL;
}

// rotate b - shift up all elements of stack b by 1.
// The first element becomes the last one
void	rb(t_stacks *stacks)
{
	t_llst	*old_b;

	if (stacks->b_len <= 1)
		return ;
	old_b = stacks->b;
	stacks->b = stacks->b->next;
	llst_add_back(&stacks->b, old_b);
	old_b->next = NULL;
}

// ra and rb at the same time
void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}

// reverse rotate a - shift down all elements of stack a by 1.
// The last element becomes the first one
void	rra(t_stacks *stacks) // min 3 element
{
	t_llst	*current;

	if (stacks->a_len <= 2)
	{
		ra(stacks);
		return ;
	}
	current = stacks->a;
	while (1)
	{
		if (!current->next->next) // second to last
		{
			current->next->next = stacks->a;
			stacks->a = current->next;
			current->next = NULL;
			break ;
		}
		current = current->next;
	}
}

// reverse rotate b - shift down all elements of stack b by 1.
// The last element becomes the first one
void	rrb(t_stacks *stacks)
{
	t_llst	*current;

	current = stacks->b;
	while (1)
	{
		if (!current->next->next) // second to last
		{
			current->next->next = stacks->b;
			stacks->b = current->next;
			current->next = NULL;
			break ;
		}
		current = current->next;
	}
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
