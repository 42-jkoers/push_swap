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
	if (!llst_issorted(all.a.lst) || all.b.len > 0)
		operations = SIZE_MAX;
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
	size_t	best_chunksize;
	t_all	all;
	t_larr	arr;

	arr.arr = read_input(&arr.len, argc, argv);
	if (!arr.arr)
		ft_exit_err("Invalid input");
	if (arr.len <= 5)
		brute_force(arr);
	else
	{
		init_all(&all, arr.arr, arr.len);
		all.chunksize = compute_best_chunksize(arr.arr, arr.len);
		all.print = true;
		sort(&all);
		destroy_all(&all);
	}
	free(arr.arr);
	exit(0);
	return (0);
}
