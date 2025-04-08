/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:23:53 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/18 16:13:53 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr;
	const unsigned char	*ptr2;

	ptr = s1;
	ptr2 = s2;
	while (n)
	{
		if (*ptr != *ptr2)
			return (*ptr - *ptr2);
		n--;
		ptr++;
		ptr2++;
	}
	return (0);
}
/*
int	main()
{
	char array1[]= "aaaabbbb";
	char array2[]= "";

	printf("%d\n", ft_memcmp(array1, array2, 34));
	return (0);
}
*/
