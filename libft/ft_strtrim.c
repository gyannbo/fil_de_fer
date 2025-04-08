/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <gbonis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:42:19 by gbonis            #+#    #+#             */
/*   Updated: 2023/12/01 21:11:47 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmpforward(char s, char *s2)
{
	while (*s2)
	{
		if (*s2 == s)
			return (1);
		s2++;
	}
	return (0);
}

static int	ft_strcmpbackward(char s, char *s2)
{
	while (*s2)
	{
		if (*s2 == s)
			return (1);
		s2++;
	}
	return (0);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*ptr1;
	char	*ptr2;
	char	*new;
	size_t	len;

	if (!s1 && !set)
		return (0);
	ptr1 = (char *)s1;
	ptr2 = (char *)s1 + (ft_strlen((char *)s1) - 1);
	while (ft_strcmpforward(*ptr1, (char *)set))
		ptr1++;
	while (ft_strcmpbackward(*ptr2, (char *)set) && !(ptr2 == (s1 - 1)))
		ptr2--;
	len = (ptr2 - ptr1) + 1;
	if (ptr2 == (s1 -1))
		len = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, ptr1, (len + 1));
	return (new);
}
/*
int	main()
{
	char *s1 = "abccaabccaababcc";
	char *s2 = "cab";
	printf("%s\n", ft_strtrim(s1, s2));
	return (0);
}
*/
