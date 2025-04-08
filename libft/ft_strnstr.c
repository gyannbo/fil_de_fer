/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:25:57 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/30 22:42:53 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strcmpbis(const char *s1, const char *s2)
{
	const char	*ptr1;
	const char	*ptr2;
	size_t		len;

	ptr1 = s1;
	ptr2 = s2;
	len = ft_strlen((char *)s2);
	while (*ptr1 == *ptr2)
	{
		ptr1++;
		ptr2++;
		len--;
		if (len == 0)
			return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*p1;
	char		*p2;
	size_t		litlen;

	p1 = (char *)big;
	p2 = (char *)little;
	litlen = ft_strlen((char *)p2);
	if (big == little || !litlen)
		return ((char *)p1);
	while (*p1 && len)
	{
		if (*(char *)p1 == *(char *)p2)
		{
			if (ft_strcmpbis(p1, p2) && len >= litlen)
				return ((char *)p1);
		}
		p1++;
		len--;
	}
	return (0);
}
/*
int	main()
{
	printf("%p\n", ft_strnstr("", "", 3));
	return (0);
}
*/
