/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:32:05 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/17 19:37:29 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_10(t_fdf *env)
{
	free(env->map->array);
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->map);
	free(env->mlx);
	free(env);
}

void	flush_get_next(int fd, char *line)
{
	while (get_next_line(fd, &line))
	{
		if (!line)
			ft_return_error("error get_next_line", 0, -1, NULL);
		free(line);
	}
	free(line);
}

void	flush_get_next_width(int fd, char *line, t_fdf *env)
{
	while (get_next_line(fd, &line))
	{
		if (!line)
			ft_return_error("close error", 1, 5, env);
		free(line);
	}
	free(line);
}

void	is_map_only_space(char *filepath)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1, -1, NULL);
	width = 0;
	get_next_line(fd, &line);
	if (!line)
		ft_return_error("error get_next_line", 0, -1, NULL);
	while (line[++i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	}
	free(line);
	flush_get_next(fd, line);
	if (width == 0)
		ft_return_error("map width = 0 (only spaces in maps)", 0, -1, NULL);
	if (close(fd) == -1)
		ft_return_error("close error", 1, -1, NULL);
}
