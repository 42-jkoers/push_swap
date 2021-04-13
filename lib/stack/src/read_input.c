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
	return (true);
}

static long	*split_input(size_t *len, const char *s)
{
	char	**split;
	size_t	i;
	long	*arr;

	split = ft_split_length(s, ' ', len);
	if (!split)
		return (NULL);
	arr = ft_malloc(*len * sizeof(long));
	i = 0;
	while (i < *len)
	{
		if (!read_number(&arr[i], split[i], arr, i))
		{
			free(arr);
			ft_free_until_null_char(split);
			return (NULL);
		}
		i++;
	}
	ft_free_until_null_char(split);
	return (arr);
}

long	*read_input(size_t *len, int argc, char **argv)
{
	size_t	i;
	long	*arr;

	if (argc <= 1)
		return (NULL);
	if (argc == 2)
		return (split_input(len, argv[1]));
	*len = argc - 1;
	arr = ft_malloc(*len * sizeof(long));
	i = 0;
	while (i < *len)
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
