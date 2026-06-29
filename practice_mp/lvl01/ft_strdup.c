/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/29 20:05:43 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/29 20:13:25 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	int		d_len;
	char	*dest;
	int		i;

	d_len = ft_strlen(src);
	dest = malloc(sizeof(char) * (d_len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	*str1 = "Hello";
// 	char	*str2 = strdup(str1);
// 	char	*str3 = ft_strdup(str1);
//
// 	printf("ORIGINAL: %s\n", str2);
// 	printf("MY FUNCTION: %s", str3);
//
// 	return (0);
// }
