#include "constants.h"
#include <stdlib.h>
// ""			false
// "-" || "+"	false
// "1a"			false
// " 1"			false
// "+1" || "-1" true

bool	is_digitstr(const char *str)
{
	size_t	i;

	if (str[0] == '-' || str[0] == '+')
	{
		if (!ft_isdigit(str[1]))
			return (false);
		i = 2;
	}
	else
		i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i > 0);
}

void	exit_err(const char *msg)
{
	size_t	len;

	ft_putstr((char *)msg);
	len = ft_strlen((char *)msg);
	if (len == 0 || msg[len - 1] != '\n')
		ft_putstr("\n");
	exit(1);
}
