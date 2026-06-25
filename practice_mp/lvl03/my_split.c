/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/25 19:17:33 by andjajas      #+#    #+#                 */
/*   Updated: 2026/06/25 19:20:27 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// VERSION WITHOUT FREE() = FULL OF MEMORY LEAKS!!!
int my_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int count_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && my_space(str[i]))
			i++;
		if (str[i])
		{
			words++;
			while (str[i] && !my_space(str[i]))
				i++;
		}
	}
	return (words);
}

int	word_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] && !my_space(str[i]))
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char *str)
{
	int		i;	// iterator for original str
	int		j;	// iterator for new wordstr
	int		k;	// iterator for copying the letters in each word
	int		len;	// calculate len of a word, returned from word_len
	char	**arr;	// define new array of pointers to the wordstr's

	arr = malloc(sizeof(char *) * (count_words(str) + 1));	// allocate memory for array, add extra +1 room for the NULL pointer
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])	// go through the original str
	{
		while (str[i] && my_space(str[i]))	// skip the space chars
			i++;
		if (str[i])	// if there is a character after space, it is the start of word, get into this block
		{
			len = word_len(str, i);	// calculate the length of the word
			arr[j] = malloc(sizeof(char) * (len + 1));	// allocate memory for word
			if (!arr[j])
				return (NULL);
			k = 0;
			while (k < len)	// loop to write the letters of the word in arr[j]
			{
				arr[j][k] = str[i];
				k++;
				i++;
			}
			arr[j][k] = '\0';
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

#include <stdio.h>

int	main(void)	// compile with -g flag, then run within valgrind or other memory checker!!
{
	char	*str = "  3334 Hello World. &&& .. hello    and bye   ";

	printf("input string: %s\n", str);

	char	**arr = ft_split(str);
	int		i;

	i = 0;
	while (arr[i])
	{
		printf("array string @index [%d]: %s\n", i, arr[i]);
		i++;
	}
	return (0);
}
