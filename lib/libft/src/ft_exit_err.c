#include "libft.h"
#include <stdlib.h>

void	ft_exit_err(const char *msg)
{
	size_t	len;

	ft_putstr((char *)msg);
	len = ft_strlen((char *)msg);
	if (len == 0 || msg[len - 1] != '\n')
		ft_putstr("\n");
	exit(1);
}
