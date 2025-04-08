/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:23:23 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/26 17:17:15 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t	srclen = ft_strlen((char *)src);

	if ((srclen + 1) < size)
		ft_memcpy(dst, src, (srclen + 1));
	else if (size != 0)
	{
		ft_memcpy(dst, src, (size - 1));
		dst[size - 1] = 0;
	}
	return (srclen);
}
/* 
int	main()
{
	char s[]= "allobonjour";
	char s2[]= "pourquoisalut";

	printf("%ld\n", ft_strlcpy(s, s2, 9));
	printf("%s\n", s); 
	return (0);
}*/
