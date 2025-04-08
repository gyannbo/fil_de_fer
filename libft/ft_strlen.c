/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:57:29 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/29 16:46:06 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*str;

	str = (char *)s;
	while (*str)
		str++;
	return (str - s);
}
/*
int	main(void)
{
	char *s = "salut";

	printf("%ld", ft_strlen(s));
	return(0);
}*/
