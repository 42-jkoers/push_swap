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

	arr = read_input(argc, argv);
	if (arr == NULL)
		exit_with_error();
	init_all(all, arr, argc - 1);
	free(arr);
}

void	execute_commands(t_all *all)
{
	char	**commands;;
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

// small to big
bool	is_sorted(const t_llst *lst)
{
	t_llst	*l;

	l = (t_llst *)lst;
	while (l && l->next)
	{
		if (l->l > l->next->l)
			return (false);
		l = l->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_stack(&all, argc, argv);
	execute_commands(&all);
	if (is_sorted(all.a.lst) && all.b.len == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	exit(0);
	return (0);
}
