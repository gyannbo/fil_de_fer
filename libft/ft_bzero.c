/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:33:24 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/16 12:19:58 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*str;
	int					b;

	b = 0;
	str = s;
	while (n)
	{
		*str = b;
		str++;
		n--;
	}
}
/*
int	main(void)
{
	char s[]= "allobonjourallobonjourallobonjour";
	
	printf("%s \n", s);
	ft_bzero(s, sizeof(char));
	printf("%s \n", s);
	return(0);
}*/
