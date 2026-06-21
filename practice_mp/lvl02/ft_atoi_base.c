/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/21 11:27:37 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/21 11:38:49 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	convert_base_c(char c, unsigned int base);

int	ft_atoi_base(const char	*nbr, unsigned int base)
{
	unsigned int	i;
	int				sign;
	int				decimal;

	i = 0;
	sign = 1;
	decimal = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i] && convert_base_c(nbr[i], base) != -1)
	{
		decimal = decimal * base + convert_base_c(nbr[i], base);
		i++;
	}
	return (decimal * sign);
}

int	convert_base_c(char c, unsigned int base)
{
	unsigned int	i;
	char			*lower_c_base;
	char			*upper_c_base;

	i = 0;
	lower_c_base = "0123456789abcdef";
	upper_c_base = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == lower_c_base[i] || c == upper_c_base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("-1011", 2));
	printf("%d\n", ft_atoi_base("1011", 2));
	printf("%d\n", ft_atoi_base("1A", 16));
	printf("%d\n", ft_atoi_base("7F", 16));
	printf("%d\n", ft_atoi_base("11", 16));
	return (0);
}
