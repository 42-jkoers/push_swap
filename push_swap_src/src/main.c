#include "constants.h"
#include "libft/include/libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_all	all;

	fill_all(&all, argc, argv);
	all.print = true;
	sort(&all);
	// print_stack(&all);
	// print_arr(&all);
	// printf("operations %li\n", all.operations);
	exit(0);
	return (0);
}
