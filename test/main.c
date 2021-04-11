#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	char buf[1000];
	while (1)
	{
		int i = 0;
		int n = 1;
		while (n > 0)
		{
			n = read(STDIN_FILENO, buf + i, 1);
			if (buf[i] == '\n' || n == 0)
				break ;
			i++;
		}
		write(1, buf, i);
		write(1, "\n---\n", 5);
		if (n == 0)
			return 0;
	}
	return 0;
}
