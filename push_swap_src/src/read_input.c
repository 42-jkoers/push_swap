#include "constants.h"
#include <limits.h>

static bool	contains_i(const long *arr, size_t len, long l)
{
	while (len > 0)
	{
		len--;
		if (arr[len] == l)
			return (true);
	}
	return (false);
}

static long	read_number(const char *s, const long *arr, size_t len)
{
	long	l;

	if (!strtol_clamp(&l, s, INT_MIN, INT_MAX))
		exit_err("Input contains non int value");
	if (!ALLOW_DUPES && contains_i(arr, len, l))
		exit_err("Input contains duplicates");
	return (l);
}

long	*read_input(int argc, char **argv)
{
	long	*arr;
	size_t	i;

	if (argc <= 1)
		exit_err("Not enough arguments");
	arr = ft_malloc((argc - 1) * sizeof(long));
	i = 0;
	while (i < argc - 1)
	{
		arr[i] = read_number(argv[i + 1], arr, i);
		i++;
	}
	return (arr);
}
