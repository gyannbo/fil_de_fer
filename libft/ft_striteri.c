/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:20:00 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/27 18:53:25 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void	fonction(unsigned int x, char *c)
{
	if ( x % 2)
		*c += 1;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &(s[i]));
		i++;
	}
}
/*
int	main()
{
	char s[]= "aaaaaaa";
	
	ft_striteri(s, &fonction);
	printf("%s\n", s);
	return (0);
}*/
