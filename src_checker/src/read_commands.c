#include "checker.h"

#include "libft/include/libft.h"
#include <stdlib.h>

static bool	is_valid_command(const char *cmd)
{
	static const char	*cmds[] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr",
		NULL,
	};

	return (ft_arrchr((char **)cmds, (char *)cmd) != -1);
}

static char	*read_input(void)
{
	t_readbuf	buf;
	ssize_t		read;

	ft_buf_init(&buf, 4096, STDIN_FILENO);
	while (true)
	{
		read = ft_buf_read(&buf);
		if (read < 0)
		{
			ft_buf_free(&buf);
			return (NULL);
		}
		if (read == 0)
			break ;
	}
	return (ft_buf_merge(&buf));
}

char	**read_commands(void)
{
	char	*input;
	char	**commands;
	size_t	i;

	input = read_input();
	if (input == NULL)
		exit_with_error();
	commands = ft_split(input, '\n');
	free(input);
	i = 0;
	while (commands[i])
	{
		if (!is_valid_command(commands[i]))
			exit_with_error();
		i++;
	}
	return (commands);
}
