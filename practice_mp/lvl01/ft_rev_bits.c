/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_bits.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/21 11:55:07 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/21 16:36:22 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	bits;

	i = 0;
	bits = 0;
	while (i < 8)
	{
		if (octet & (1 << i))
			bits = bits | (1 << (7 - i));
		i++;
	}
	return (bits);
}

void	print_bits(unsigned char octet)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		if (octet & 1 << i)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

// Helper to run tests cleanly
void run_test(unsigned char test_value)
{
	unsigned char result;

	write(1, "Original: ", 10);
	print_bits(test_value);
	
	result = reverse_bits(test_value);
	
	write(1, " -> Reversed: ", 14);
	print_bits(result);
	write(1, "\n", 1);
}

int	main(void)
{
	// Test 1: Palindrome byte (Should look exactly the same)
	write(1, "--- Test 1 ---\n", 15);
	run_test(0b10000001); // 129

	// Test 2: Standard asymmetric byte
	write(1, "--- Test 2 ---\n", 15);
	run_test(0b11110000); // 240 (Should become 00001111)

	// Test 3: Single bit at the edge
	write(1, "--- Test 3 ---\n", 15);
	run_test(0b00000001); // 1 (Should become 10000000)

	// Test 4: All zeros
	write(1, "--- Test 4 ---\n", 15);
	run_test(0b00000000); // 0 (Should stay 00000000)

	return (0);
}

// unsigned char	swap_bits(unsigned char octet)
// {
// 	return (octet << 4 | octet >> 4);
// }
