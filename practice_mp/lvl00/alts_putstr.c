/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alts_putstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/21 11:00:28 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/21 11:02:50 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	iterative_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ptr_arthm_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(void)
{
	char	*str;

	str = "best putstr ever";
	ptr_arthm_putstr(str);
	write(1, "\n", 1);
	iterative_putstr(str);
	write(1, "\n", 1);
	return (0);
}
