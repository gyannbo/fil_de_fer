/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:52:23 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/30 19:58:03 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		t1;
	size_t		t2;

	i = 0;
	t1 = ft_strlen(dst);
	t2 = ft_strlen((char *)src);
	if ((unsigned int)size == 0)
		return (t2);
	if (size - 1 <= t1)
	{
		if ((size - 1) == t1)
			return (t2 + (size -1));
		return (t2 + size);
	}
	while ((t1 + i) < (size - 1) && src[i])
	{
		dst[t1 + i] = src[i];
		i++;
	}
	dst[t1 + i] = '\0';
	return (t1 + t2);
}
/*
int	main()
{
	char s2[]= "pqrstuvwxyz"; 
	char s3[]= "abcd";
	char buffer[40];

	printf("%s\n", buffer);
	strcpy(buffer, s2);
	printf("%s\n", buffer);
	printf("%ld\n", ft_strlcat(buffer, s3, 20));
	printf("%s\n", buffer);
	return (0);
}*/
