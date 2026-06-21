/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   recur_rev_wstr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/21 20:37:59 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/21 20:51:15 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_wstr_recursive(char *str)
{
	int	i;
	int	next;

	if (!str || *str == '\0')
		return;
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	if (str[i] != '\0')
	{
		next = i;
		while (str[next] == ' ' || str[next] == '\t')
			next++;
		if (str[next] != '\0')
		{
			rev_wstr_recursive(&str[next]);
			write(1, " ", 1);
		}
	}
	write(1, str, i);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		rev_wstr_recursive(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
