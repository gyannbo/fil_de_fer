/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:09 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/23 17:34:16 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void	*ptr;
	size_t	len;

	len = ft_strlen((char *)s) + 1;
	ptr = malloc(len);
	if (ptr == 0)
		return (0);
	return ((char *)ft_memcpy(ptr, s, len));
}
/*
int	main()
{
	char s[]= "al0obonjour";
	char *ptr= 0;

	ptr = ft_strdup(s);
	printf("%s\n", ptr); 
	printf("%lu\n", sizeof(s));
	return (0);
}*/
