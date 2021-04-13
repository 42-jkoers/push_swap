#include "checker.h"

#include "libft/include/libft.h"
#include "stack/include/all.h"
#include <stdlib.h>

static char	*read_input_buf(void)
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
	size_t	input_len;

	input = read_input_buf();
	if (input == NULL)
		exit_with_error();
	input_len = ft_strlen(input);
	if (input_len > 0 && input[input_len - 1] != '\n')
		exit_with_error();
	commands = ft_split(input, '\n');
	free(input);
	i = 0;
	while (commands[i])
	{
		if (str_to_cmd(commands[i]) == INVALID)
			exit_with_error();
		i++;
	}
	return (commands);
}
