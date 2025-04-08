/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:02:33 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/30 08:49:30 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*ft_init(const char *path)
{
	t_fdf	*env;

	env = malloc(sizeof(t_fdf));
	if (!env)
		ft_return_error("malloc error", 1, -1, NULL);
	env->mlx = mlx_init();
	if (!env->mlx)
		ft_return_error("error connecting to X11 server", 1, 0, env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, (char *)path);
	if (!env->win)
		ft_return_error("error init window", 1, 1, env);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img)
		ft_return_error("error init mlx image", 1, 2, env);
	env->data_addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line,
			&env->endian);
	env->map = NULL;
	env->camera = NULL;
	env->line = NULL;
	return (env);
}

static t_camera	*ft_camera_init(t_fdf *env)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		ft_error_tab("err cam", env, env->map->height - 1, env->map->width);
	camera->zoom = zoom_cut(ft_min(WIDTH / env->map->width / 2,
				HEIGHT / env->map->height / 2));
	camera->x_angle = 0.885398;
	camera->y_angle = -0.677865238;
	camera->z_angle = -0.490865238;
	return (camera);
}

static t_map	*ft_map_init(t_fdf *env)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_return_error("error init map", 1, 3, env);
	map->height = 0;
	map->width = 0;
	map->array = NULL;
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

/*
a corriger dans ce projet, les calculs matriciels doivent etre fait avant l'assignation dans la variable.
En somme il faut faire comme ce que recommande les livres, d'ailleurs avant de faire le prochain projet
de graphique il faudra relire ces passages des livres.
Mais pour réexpliquer il faut faire tous les calculs matriciels dans un tableau avant de faire l'assignation
dans la variable. Mais justement j'ai pas trop compris. En fait j'ai surtout pas trop compris comment on fait
justement pour mettre plusieurs transformation dans un seul tableau, surtout pour faire une rotation (donc 
des multiplications) puis apres une translation (donc des additions ou soustractions). Enfin voila je dois
clarifier tout ça.
Et aussi le header avaut une faute de norminette, que je vais corriger maintenant.
*/

int	main(int argc, char *argv[])
{
	t_fdf	*env;

	if (argc == 2)
	{
		check_valid(argv[1]);
		env = ft_init(argv[1]);
		env->map = ft_map_init(env);
		ft_fill_map_table(argv[1], env);
		ft_get_z_min_max_map(env->map);
		env->camera = ft_camera_init(env);
		ft_hook_controls(env);
		ft_draw(env->map, env);
		mlx_loop(env->mlx);
	}
	else
		ft_return_error("Usage: ./fdf <filename>", 0, -1, NULL);
	return (0);
}
