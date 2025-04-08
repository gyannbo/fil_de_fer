/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:27:41 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/30 21:10:39 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*(unsigned char *)s1 == *(unsigned char *)s2) && (n > 1) && *s1)
	{
		s1++;
		s2++;
		n--;
	}
	return ((*(unsigned char *)s1 - *(unsigned char *)s2));
}
/*
int	main(void)
{
	printf("%d \n", strncmp("test\200", "test\0", 6));
	printf("%d \n", ft_strncmp("test\200", "test\0", 6));
	return (0);
}*/