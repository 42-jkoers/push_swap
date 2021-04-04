#include "constants.h"

void	swap_l(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_l(long *arr, size_t len)
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
