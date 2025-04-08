/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:02:41 by gbonis            #+#    #+#             */
/*   Updated: 2023/12/09 12:18:50 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	bytes = nmemb * size;
	if ((bytes / size) != nmemb)
		return (0);
	ptr = malloc(nmemb * size);
	if (ptr)
	{
		ft_bzero(ptr, (nmemb * size));
		return (ptr);
	}
	return (0);
}
/*
int	main()
{
	printf("%p\n", calloc(0, 0));
	printf("%p\n", ft_calloc(0, 0));
	return(0);
}*/
