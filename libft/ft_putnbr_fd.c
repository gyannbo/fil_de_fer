/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:08:34 by gbonis            #+#    #+#             */
/*   Updated: 2023/11/28 15:57:32 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	x;

	x = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		x *= -1;
	}
	i = x % 10 + '0';
	if (x > 9)
		ft_putnbr_fd(x / 10, fd);
	write(fd, &i, 1);
}
/*
int	main()
{
	int n = 0;
	ft_putnbr_fd(n, 1);
	return (0);
}*/
