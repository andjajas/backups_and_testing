int	ft_atoi_base(const char	*nbr, unsigned int base)
{
	unsigned int	i;
	int		sign;
	int		decimal;

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

int	convert_base_c(char c, base)
{}
