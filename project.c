/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:37:08 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/20 15:11:11 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	double	prev_y;
	double	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = round(prev_y * cos(x_angle)) - round(prev_z * sin(x_angle));
	*z = round(prev_y * sin(x_angle)) + round(prev_z * cos(x_angle));
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	double	prev_x;
	double	prev_z;

	y_angle = -y_angle;
	prev_x = *x;
	prev_z = *z;
	*z = round(prev_z * cos(y_angle)) - round(prev_x * sin(y_angle));
	*x = round(prev_z * sin(y_angle)) + round(prev_x * cos(y_angle));
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = round(prev_x * cos(z_angle)) - round(prev_y * sin(z_angle));
	*y = round(prev_x * sin(z_angle)) + round(prev_y * cos(z_angle));
}

t_point	project(int x, int y, t_fdf *env)
{
	t_point	point;

	point.z = env->map->array[y][x][0];
	if (env->map->array[y][x][1] >= 0)
		point.color = env->map->array[y][x][1];
	else
		point.color = get_default_color(env->map->array[y][x][0], env->map);
	point.x = x * env->camera->zoom;
	point.y = y * env->camera->zoom;
	point.z *= env->camera->zoom;
	point.x -= (env->map->width * env->camera->zoom) / 2;
	point.y -= (env->map->height * env->camera->zoom) / 2;
	ft_rotate_x(&point.y, &point.z, env->camera->x_angle);
	ft_rotate_y(&point.x, &point.z, env->camera->y_angle);
	ft_rotate_z(&point.x, &point.y, env->camera->z_angle);
	point.x += round(WIDTH / 2);
	point.y += round(HEIGHT / 1.45);
	point.reverse = 0;
	return (point);
}
