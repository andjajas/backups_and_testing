/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/21 18:45:11 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/21 18:51:47 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	long	n;
	int		len;
	char	*str;

	n = nbr;
	len = count_digits(nbr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
	printf("\n");
	printf("%s", ft_itoa(2147483647));
	printf("\n");
	printf("%s", ft_itoa(0));
	printf("\n");
	printf("%s", ft_itoa(-1));
	printf("\n");
	printf("%s", ft_itoa(1));
	printf("\n");
	printf("%s", ft_itoa(42));
	printf("\n");
	return (0);
}
