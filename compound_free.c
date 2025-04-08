/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:32:21 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/17 20:55:25 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_return_error_tab2(int i, int y, t_fdf *env)
{
	if (i > 0 && (y == 0 || y == -1))
	{
		i--;
		if (y != -1)
			y = env->map->width;
		else
			y = 0;
	}
	while (i >= 0)
	{	
		while (y > 0)
			free(env->map->array[i][--y]);
		y = env->map->width;
		free(env->map->array[i]);
		i--;
	}
}

void	compound_free(int free_code, t_fdf *env)
{
	if (free_code == 0)
		free_0(env);
	if (free_code == 1)
		free_1(env);
	if (free_code == 2)
		free_2(env);
	if (free_code == 3)
		free_3(env);
	if (free_code == 4 || free_code == 5 || free_code
		== 6 || free_code == 7 || free_code == 8 || free_code == 9)
		free_4(env);
}

void	ft_free_split(char **num, int i, int prev_ind, t_fdf *env)
{
	int	temp;

	temp = i;
	if (!num)
	{
		i = -1;
		prev_ind++;
		ft_error_tab("malloc error", env, prev_ind, i);
	}
	while (num[temp])
	{
		free(num[temp]);
		temp++;
	}
	free(num);
	ft_error_tab("malloc error", env, prev_ind, i);
}

void	return_error_check_valid(char *err_msg, char *line)
{
	free(line);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit (-1);
}

void	ft_error_tab(char *err_msg, t_fdf *env, int i, int y)
{
	if (i == 0 && y == 0)
	{
		free(env->line);
		free_10(env);
		exit (-1);
	}
	ft_return_error_tab2(i, y, env);
	if (*err_msg != 'e')
		free(env->line);
	free_10(env);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(-1);
}
