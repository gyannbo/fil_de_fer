/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:04:45 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/16 20:49:45 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom_cut(int x)
{
	if (x < 2)
		return (2);
	if (x > 30)
		return (30);
	else
		return (x);
}

int	ft_close_win(void *param)
{
	t_fdf	*env;
	int		x;
	int		y;

	env = param;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->camera);
	y = -1;
	while (++y < env->map->height)
	{
		x = -1;
		while (++x < env->map->width)
			free(env->map->array[y][x]);
		free(env->map->array[y]);
	}
	free(env->map->array);
	free(env->map);
	free(env->mlx);
	free(env);
	exit(0);
}

int	esc_key(int keycode, void *param)
{
	if (keycode == 0xff1b)
		ft_close_win(param);
	return (0);
}

void	ft_hook_controls(t_fdf *env)
{
	mlx_key_hook(env->win, esc_key, env);
	mlx_hook(env->win, 17, 0, ft_close_win, env);
}
