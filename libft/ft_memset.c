/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:40:27 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/16 13:33:11 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned int		b;

	str = s;
	b = c;
	while (n)
	{
		*str = b;
		str++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char s1[] = "";
	int n = 'n';

	printf("%s \n", s1);	
	ft_memset(s1, n, 5);
	printf("%s \n", s1);	
	
	return (0);
}*/
