/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:07:21 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/30 18:47:50 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	const char	*found;

	found = NULL;
	ptr = s;
	c = (char)c;
	if (c == 0)
	{
		ptr = ft_strchr(s, c);
		return ((char *) ptr);
	}
	if (*ptr == 0)
		return (0);
	while (*ptr)
	{
		if (*ptr == c)
			found = ptr;
		ptr++;
	}
	if (found == NULL)
		return (NULL);
	else
		return ((char *)found);
}
/*
int	main(void)
{
	const char *str = "tripouille";
	printf("%p \n", ft_strchr(str, 'z'));
	printf("%p \n", strchr(str, 'z'));
	return(0);
}*/
