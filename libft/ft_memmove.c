/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:12:48 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/23 17:27:34 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*copy_backward(void *dest, const void *src, size_t n)
{
	const char	*from;
	char		*to;

	from = src;
	to = dest;
	to += (n - 1);
	from += (n - 1);
	while (n)
	{
		*to = *from;
		n--;
		to--;
		from--;
	}
	return (dest);
}

static void	*copy_forward(void *dest, const void *src, size_t n)
{
	const char	*from;
	char		*to;

	from = src;
	to = dest;
	while (n)
	{
		*to = *from;
		n--;
		to++;
		from++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*from;
	char		*to;

	from = src;
	to = dest;
	if (to == from || n == 0)
		return (dest);
	if (from < to && to - from < (unsigned int)n)
		return (copy_backward(to, from, n));
	if (from > to && from - to < (unsigned int)n)
		return (copy_forward(to, from, n));
	ft_memcpy(to, from, n);
	return (to);
}
/*
int	main()
{

	char array[]= "0123456789";

	printf("%s\n", array);
	ft_memmove(array, &array[2], 8);
	printf("%s\n", array);
return (0);
}*/
