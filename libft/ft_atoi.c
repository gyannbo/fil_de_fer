/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:25:56 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/14 17:59:38 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(char s)
{
	if ((s >= 9 && s <= 13) || s == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	if (*nptr >= 48 && *nptr <= 57)
	{
		while (*nptr >= 48 && *nptr <= 57)
		{
			number = (number * 10) + *nptr - '0';
			nptr++;
		}
		number *= sign;
		return (number);
	}
	else
		return (0);
}
//
//int	main()
//{
//	char str[]= "10000000000000000000";
//	
//	printf("%d\n", atoi(str));
//
//	printf("%d\n", ft_atoi(str));
//	return (0);
//}
