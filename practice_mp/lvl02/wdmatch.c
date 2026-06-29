#include <unistd.h>

int	valid_argv(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] != '\0' && s1[i] != s2[j])
			j++;
		if (s2[j] == '\0')
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (valid_argv(argv[1], argv[2]))
	{
		j = 0;
		while (argv[1][j])
		{
			write(1, &argv[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
