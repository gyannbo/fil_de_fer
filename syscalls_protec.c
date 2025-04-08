/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscalls_protec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:31:00 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/17 20:43:13 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int	my_open(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1, 0, NULL);
	return (fd);
}

void	my_close(int fd, int er_code, t_fdf *env)
{
	if (close(fd) == -1)
	{
		if (er_code == 1)
			ft_error_tab("error close", env,
				env->map->height - 1, env->map->width);
		ft_return_error("close error", 1, 0, NULL);
	}
}
