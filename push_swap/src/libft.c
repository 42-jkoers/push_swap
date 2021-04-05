#include "constants.h"
#include <stdlib.h>

void	exit_err(const char *msg)
{
	size_t	len;

	ft_putstr((char *)msg);
	len = ft_strlen((char *)msg);
	if (len == 0 || msg[len - 1] != '\n')
		ft_putstr("\n");
	exit(1);
}

// @return
// ""						false
// "-" | "+"				false
// " 1"						false
// "1a"						false
// "9999999999999999999999"	false
// "1 2"					false
// "+1" | "-1" 				true
// "01"		 				true

bool	strtol_safe(long *num, const char *str)
{
	size_t	i;
	long	num_prev;

	if (str[0] == '-' || str[0] == '+')
	{
		if (!ft_isdigit(str[1]))
			return (false);
		i = 1;
	}
	else
		i = 0;
	*num = 0;
	while (ft_isdigit(str[i]))
	{
		num_prev = *num;
		*num -= str[i] - '0';
		if (*num > num_prev)
			return (false);
		i++;
	}
	if (str[0] != '-')
		*num *= -1;
	return (i > 0);
}

bool	strtol_clamp(long *num, const char *str, long min, long max)
{
	if (!strtol_safe(num, str))
		return (false);
	return (*num >= min && *num <= max);
}
