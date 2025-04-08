/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:59:44 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/17 19:33:36 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_suffix(char *filepath)
{
//	int	i;     //prob useless
	int	file_len;

//	i = 0;
	file_len = ft_strlen(filepath);
	if (file_len < 4)
		ft_return_error("invalid file path", 0, -1, NULL);
	if (ft_strncmp(&filepath[file_len - 4], ".fdf", 4) != 0)
		ft_return_error("invalid file path", 0, -1, NULL);
}

void	is_map_empty(char *filepath)
{
	int		fd;
	char	*line;
	int		err_read_get_next;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		ft_return_error("open error", 1, -1, NULL);
	err_read_get_next = get_next_line(fd, &line);
	if (err_read_get_next == -1)
		ft_return_error("read error", 1, -1, NULL);
	if (*line == '\0')
	{
		free(line);
		ft_return_error("invalid map (empty)", 0, -1, NULL);
	}
	free(line);
	flush_get_next(fd, line);
	if (close(fd) == -1)
		ft_return_error("close error", 1, -1, NULL);
}

int	get_width(char *filepath)
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
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	flush_get_next(fd, line);
	if (close(fd) == -1)
		ft_return_error("close error", 1, -1, NULL);
	return (width);
}

void	check_width(char *filepath, int check_width)
{
	int		fd;
	int		width;
	char	*line;
	int		i;

	i = -1;
	fd = my_open(filepath);
	while (get_next_line(fd, &line))
	{
		if (!line)
			ft_return_error("error get_next_line", 0, -1, NULL);
		width = 0;
		while (line[++i])
		{
			if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
				width++;
		}
		if (check_width != width)
			return_error_check_valid("invalid map formatting", line);
		free(line);
		i = -1;
	}
	free(line);
	my_close(fd, 0, NULL);
}

void	check_valid(char *filepath)
{
	int	fd;
	int	width;

	if (filepath == NULL)
		ft_return_error("invalid file path", 0, -1, NULL);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		ft_return_error("invalid file path", 1, -1, NULL);
	parse_suffix(filepath);
	is_map_empty(filepath);
	width = get_width(filepath);
	is_map_only_space(filepath);
	check_width(filepath, width);
}
