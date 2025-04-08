/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:26:51 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/06 15:48:25 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_word(char **str, size_t size)
{
	while (size)
	{
		size--;
		free(*(str + size));
	}
	free(str);
	return (-1);
}

static size_t	count_words(const char *str, char charset)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == charset || str[i + 1] == '\0') == 1
			&& (str[i] == charset || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, const char *from, char charset)
{
	size_t	i;

	i = 0;
	while ((from[i] == charset || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_split(char **split, const char *str, char charset)
{
	size_t		i;
	size_t		j;
	size_t		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == charset)
			i++;
		else
		{
			j = 0;
			while (!(str[i + j] == charset || str[i + j] == '\0'))
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (free_word(split, word));
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char		**res;
	size_t		words;

	if (!s)
		return (0);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	if (write_split(res, s, c) == -1)
		return (NULL);
	res[words] = 0;
	return (res);
}
/*
int	main()
{
	const char *s = ".....allo..bonjour..";
	char **tableau;

	tableau = ft_split(s, '.');
	printf("%s\n", tableau[0]);
	printf("%s\n", tableau[1]);
	printf("%p\n", &tableau[2]);
	return (0);
}
*/
