#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int main(void)
{
	char	str[] = "best ft_putstr ever";
	ft_putstr(str);
	write(1, "\n", 1);
	return (0);
}

