#include "checker.h"

#include "libft/include/libft.h"
#include "stack/include/all.h"
#include <stdlib.h>

void	exit_with_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	init_stack(t_all *all, int argc, char **argv)
{
	long	*arr;
	size_t	len;

	arr = read_input(&len, argc, argv);
	if (!arr)
		exit_with_error();
	init_all(all, arr, len);
	free(arr);
}

void	execute_commands(t_all *all)
{
	char	**commands;
	size_t	i;

	commands = read_commands();
	i = 0;
	while (commands[i])
	{
		execute(all, str_to_cmd(commands[i]));
		i++;
	}
	ft_free_until_null_char(commands);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_stack(&all, argc, argv);
	if (!llst_issorted(all.a.lst))
		execute_commands(&all);
	if (llst_issorted(all.a.lst) && all.b.len == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	exit(0);
	return (0);
}
