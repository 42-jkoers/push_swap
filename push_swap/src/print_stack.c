#include "constants.h"

// void	print_value(const t_llist *current)
// {
// }

void	print_arr(const t_stacks *stacks)
{
	size_t	i;

	i = 0;
	printf("\nsorted ");
	while (i < stacks->a_len + stacks->b_len)
	{
		printf("%li ", stacks->sorted[i]);
		i++;
	}
	printf("\n");
}

void	print_stack(const t_stacks *stacks)
{
	t_llst	*current_a;
	t_llst	*current_b;

	current_a = stacks->a;
	current_b = stacks->b;
	while (current_a || current_b)
	{
		if (current_a)
		{
			printf("%-5li", current_a->l);
			current_a = current_a->next;
		}
		printf(" | ");
		if (current_b)
		{
			printf("%-5li", current_b->l);
			current_b = current_b->next;
		}
		printf("\n");
	}
}
