/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:23:11 by gbonis            #+#    #+#             */
/*   Updated: 2023/12/01 20:20:00 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (0);
	while (n)
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
	return (dest);
}
/*
int     main() 
{ 
        char array[]= "0123456789"; 
	char array2[]= "zzzzzzzzzzzzzzzzaaaaa";
        char *p1 = &array[10]; 
        char *p2 = &array[10]; 
 
        printf("%s\n", array2); 
        printf("%s\n", &array[10]); 
        ft_memcpy(p2, p1, 3); 
        printf("%s\n", &array[10]); 
        return (0); 
} 
*/
