#include "constants.h"
#include "libft/include/libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_all	stacks;

	fill_all(&stacks, argc, argv);
	sort(&stacks);
	print_stack(&stacks);
	print_arr(&stacks);
	exit(0);
	return (0);
}
