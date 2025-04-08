/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:12:30 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/30 19:28:45 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			len;
	unsigned char	a;

	a = (unsigned char)c;
	len = 0;
	ptr = (unsigned char *)s;
	while (n)
	{
		if (*(ptr + len) == a)
			return (ptr + len);
		len++;
		n--;
	}
	return (0);
}
/*
int	main ()
{
	char *array = 	"/|\x12\xff\x09\x42\2002\42|\\";

	printf("%d\n",*(char *)memchr(array, '\200', 10));	
	printf("%d\n",*(char *)ft_memchr(array, '\200', 10));	
	return (0);
}*/
