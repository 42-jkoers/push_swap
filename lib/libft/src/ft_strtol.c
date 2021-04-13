#include "libft.h"

// @return
// ""						false
// "-" | "+"				false
// " 1"						false
// "1a"						false
// "9999999999999999999999"	false (overflow)
// "1 2"					false
// "1 "						false
// "+1" | "-1" 				true
// "01"		 				true

bool	ft_strtol_safe(long *num, const char *str)
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
		*num *= 10;
		*num -= str[i] - '0';
		if (*num > num_prev)
			return (false);
		i++;
	}
	if (str[0] != '-')
		*num *= -1;
	return (i > 0 && str[i] == '\0');
}

bool	ft_strtol_clamp(long *num, const char *str, long min, long max)
{
	if (!ft_strtol_safe(num, str))
		return (false);
	return (*num >= min && *num <= max);
}
