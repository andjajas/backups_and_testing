/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alts_strlen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/21 11:00:41 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/21 11:05:36 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	iterative_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ptr_arthm_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

int	main(void)
{
	char	*str;
	int		count;

	str = "Codam is the best";
	count = iterative_strlen(str);
	printf("%d\n", count);
	count = ptr_arthm_strlen(str);
	printf("%d\n", count);
	return (0);
}
