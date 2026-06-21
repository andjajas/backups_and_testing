/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_union.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/21 17:00:12 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/21 17:51:42 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_char(char	*str, char c, int ndx)
{
	int	i;

	i = 0;
	while (i < ndx && str[i])
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int j;
	int k;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	j = 0;
	while (argv[1][j])
	{
		if (check_char(argv[1], argv[1][j], j) == 1)
			write(1, &argv[1][j], 1);
		j++;
	}
	k = 0;
	while (argv[2][k])
	{
		if ((check_char(argv[1], argv[2][k], j) == 1)
			&& (check_char(argv[2], argv[2][k], k) == 1))
			write(1, &argv[2][k], 1);
		k++;
	}
	return (0);	
}
