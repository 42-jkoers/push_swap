#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_exit_err(const char *msg)
{
	size_t	len;

	ft_putstr((char *)msg);
	len = ft_strlen((char *)msg);
	write(STDERR_FILENO, msg, len);
	if (len != 0 && msg[len - 1] != '\n')
		write(STDERR_FILENO, "\n", 1);
	exit(1);
}
