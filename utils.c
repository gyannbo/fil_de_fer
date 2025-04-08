/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:40:48 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/15 18:51:07 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_fdf *env, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * env->bpp / 8) + (y * env->size_line);
		env->data_addr[i] = color;
		env->data_addr[++i] = color >> 8;
		env->data_addr[++i] = color >> 16;
	}
}

void	ft_return_error(char *err_msg, int sys_func, int free_code, t_fdf *env)
{
	if (free_code >= 0)
		compound_free(free_code, env);
	if (!sys_func)
		ft_putendl_fd(err_msg, STDERR_FILENO);
	else
		perror(err_msg);
	exit(-1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->z_max - map->z_min;
	if (max == 0)
		return (0x0D5721);
	percent = ((double)(z - map->z_min) / max);
	if (percent < 0.2)
		return (0x0D5721);
	else if (percent < 0.4)
		return (0X12A33A);
	else if (percent < 0.6)
		return (0x0EEB4B);
	else if (percent < 0.8)
		return (0x52FF81);
	else
		return (0xBFF2CD);
}
