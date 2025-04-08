/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:21:14 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/17 20:35:08 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_height(char *filename, t_fdf *env)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1, 6, env);
	height = 0;
	while (get_next_line(fd, &line))
	{
		if (!line)
			ft_return_error("get next error", 1, 7, env);
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_return_error("close error", 1, 7, env);
	return (height);
}

int	ft_get_width(char *filename, t_fdf *env)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1, 4, env);
	width = 0;
	get_next_line(fd, &line);
	if (!line)
		ft_return_error("get next error", 1, 5, env);
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	flush_get_next_width(fd, line, env);
	if (close(fd) == -1)
		ft_return_error("close error", 1, 5, env);
	return (width);
}

void	ft_fill_table(int **n, t_fdf *env, int prev_ind)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(env->line, ' ');
	i = -1;
	if (!num)
		ft_free_split(NULL, 0, prev_ind, env);
	while (num[++i] && i < env->map->width)
	{
		n[i] = malloc(sizeof(int) * 2);
		if (!n[i])
			ft_free_split(num, i, prev_ind, env);
		n[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			n[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			n[i][1] = -1;
		free(num[i]);
	}
	free(num);
}

void	ft_get_z_min_max_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

void	ft_fill_map_table(char *filename, t_fdf *env)
{
	int		fd;
	int		i;

	env->map->width = ft_get_width(filename, env);
	env->map->height = ft_get_height(filename, env);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1, 8, env);
	i = -1;
	env->map->array = malloc(sizeof(int **) * env->map->height);
	if (!env->map->array)
		ft_return_error("malloc error", 1, 9, env);
	while (get_next_line(fd, &env->line))
	{
		if (!env->line)
			ft_error_tab("get next error", env, i + 1, 0);
		env->map->array[++i] = malloc(sizeof(int *) * env->map->width);
		if (!env->map->array[i])
			ft_error_tab("malloc error", env, i, 0);
		ft_fill_table(env->map->array[i], env, i);
		free(env->line);
	}
	free(env->line);
	my_close(fd, 1, env);
}
