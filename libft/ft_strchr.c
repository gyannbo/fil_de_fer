/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:01:33 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/23 17:32:09 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	c = (char)c;
	while (*ptr)
	{
		if (*ptr == c)
			return ((char *)ptr);
		ptr++;
	}
	if (*ptr == c)
		return ((char *) ptr);
	else if (*ptr == 0)
		return (0);
	return (0);
}
/*
int	main(void)
{
	char *s = "ananas0";
	char *vide = "";

	printf("%p\n", (s + 6));
	printf("%p\n", ft_strchr(s, 'r'));
	printf("%p \n", ft_strchr(s, 's'));
	printf("%p \n", ft_strchr(s, 'w'));
	printf("%p \n", ft_strchr(vide, 'Z'));
	printf("%p \n", strchr(s, 'r'));
	printf("%p \n", strchr(s, 's'));
	printf("%p \n", strchr(s, 'w'));
	printf("%p \n", strchr(vide, 'Z'));
	return (0);
}*/
