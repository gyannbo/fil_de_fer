/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:18:43 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/23 17:39:03 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpybis(void *dest, const void *src)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

static char	*ft_strcatbis(char *s1, char *s2, char *new)
{
	size_t	t1;
	size_t	t2;

	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	ft_memcpybis(new, s1);
	new += t1;
	ft_memcpybis(new, s2);
	new += (t2);
	*new = 0;
	return (new - (t1 + t2));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		t1;
	size_t		t2;

	t1 = ft_strlen((char *)s1);
	t2 = ft_strlen((char *)s2);
	ptr = (char *)malloc(t1 + t2 + 1);
	if (!ptr)
		return (0);
	return (ft_strcatbis((char *)s1, (char *)s2, ptr));
}
/*
int	main()
{
	char *s1 = "allo "; 
	char *s2 = "bonjour";

	printf("%s\n", ft_strjoin(s1, s2));	
	return (0);
}*/
