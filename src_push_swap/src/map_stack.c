#include "constants.h"
#include <stdlib.h>

static void	swap_l(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_arr(long *arr, size_t len)
{
	size_t	i;
	bool	done;

	done = false;
	while (!done)
	{
		i = 0;
		done = true;
		while (i + 1 < len)
		{
			if (arr[i] - arr[i + 1] > 0)
			{
				swap_l(arr + i, arr + i + 1);
				done = false;
			}
			i++;
		}
	}
}

static long	*stack_to_sorted_arr(const t_stack *stack)
{
	size_t	i;
	t_llst	*current;
	long	*sorted;

	sorted = ft_malloc(stack->len * sizeof(long));
	i = 0;
	current = stack->lst;
	while (current)
	{
		sorted[i] = current->l;
		current = current->next;
		i++;
	}
	sort_arr(sorted, stack->len);
	return (sorted);
}

static long	get_index(long *arr, size_t len, long d)
{
	long	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == d)
			return (i);
		i++;
	}
	exit_err("ERR number not in stack");
	return (-1);
}

// eg 3 9 10 --> 0 1 2
//   -1 0 1 --> 0 1 2

void	map_stack(t_stack *stack)
{
	t_llst	*current;
	long	*sorted;

	sorted = stack_to_sorted_arr(stack);
	current = stack->lst;
	while (current)
	{
		current->l = get_index(sorted, stack->len, current->l);
		current = current->next;
	}
	free(sorted);
}
