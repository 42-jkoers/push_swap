#include "constants.h"
#include "libft/include/libft.h"
#include <stdlib.h>
#include <limits.h>

static size_t	count_operations(const long *arr, size_t len, size_t chunksize)
{
	t_all	all;
	size_t	operations;

	init_all(&all, arr, len);
	all.print = false;
	all.chunksize = chunksize;
	sort(&all);
	operations = all.operations;
	if (!is_sorted(all.a.lst))
		operations = ULONG_MAX;
	destroy_all(&all);
	return (operations);
}

static size_t	compute_best_chunksize(const long *arr, size_t len)
{
	size_t	chunksize;
	size_t	best_operations;
	size_t	best_chunksize;
	size_t	operations;

	best_operations = SIZE_MAX;
	best_chunksize = 1;
	chunksize = 1;
	while (chunksize < len)
	{
		operations = count_operations(arr, len, chunksize);
		if (operations < best_operations)
		{
			best_operations = operations;
			best_chunksize = chunksize;
		}
		chunksize++;
	}
	return (best_chunksize);
}

int	main(int argc, char **argv)
{
	long	*arr;
	size_t	best_chunksize;
	t_all	all;

	arr = read_input(argc, argv);
	if (arr == NULL)
		ft_exit_err("Invalid input");
	if (argc - 1 <= 5)
		brute_force(arr, argc - 1);
	else
	{
		init_all(&all, arr, argc - 1);
		all.chunksize = compute_best_chunksize(arr, argc - 1);
		all.print = true;
		sort(&all);
		destroy_all(&all);
	}
	free(arr);
	exit(0);
	return (0);
}
