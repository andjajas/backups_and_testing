/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/29 19:50:17 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/29 19:53:47 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	*s1 = "";
// 	char	*s2 = "abcdeg";
// 	int		x = 0;
//
// 	x = my_strcmp(s2, s1);
// 	printf("%d", x);
// 	return (0);
// }
