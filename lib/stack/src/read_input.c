#include "../include/all.h"
#include <limits.h>
#include <stdlib.h>

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

static bool	read_number(long *l, const char *s, const long *arr, size_t len)
{
	if (!ft_strtol_clamp(l, s, INT_MIN, INT_MAX))
		return (false);
	if (!ALLOW_DUPES && contains_i(arr, len, *l))
		return (false);
	return (l);
}

long	*read_input(int argc, char **argv)
{
	long	*arr;
	int		i;

	if (argc <= 1)
		return (NULL);
	arr = ft_malloc((argc - 1) * sizeof(long));
	i = 0;
	while (i < argc - 1)
	{
		if (!read_number(&arr[i], argv[i + 1], arr, i))
		{
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
