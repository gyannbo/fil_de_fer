/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:21:50 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/30 12:14:34 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIDTH 3840 
# define HEIGHT 2160 

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}				t_point;

typedef struct s_map
{
	int	height;
	int	width;
	int	***array;
	int	z_max;
	int	z_min;
}				t_map;

typedef struct s_camera
{
	int		zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
}				t_camera;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	t_map		*map;
	t_camera	*camera;
	char		*line;
}				t_fdf;

void	ft_fill_map_table(char *filename, t_fdf *env);
void	ft_draw(t_map *map, t_fdf *env);
void	ft_put_pixel(t_fdf *env, int x, int y, int color);
void	ft_draw_line(t_point s, t_point e, t_fdf *env);
t_point	project(int x, int y, t_fdf *env);
int		ft_min(int a, int b);
int		get_default_color(int z, t_map *map);
double	ft_reset_angles(double angle);
double	ft_abs(double n);
int		ft_ipart(double n);
double	ft_fpart(double n);
double	ft_rfpart(double n);
void	ft_hook_controls(t_fdf *env);
int		ft_close_win(void *params);
int		esc_key(int keycode, void *params);
int		mlx_destroy_display(void *mlx);
int		zoom_cut(int x);
int		my_open(char *filepath);
void	check_valid(char *filepath);
void	parse_suffix(char *filepath);
void	compound_free(int free_code, t_fdf *env);
void	return_error_check_valid(char *err_msg, char *line);
void	ft_return_error(char *err_msg, int sys_func, int free_code, t_fdf *env);
void	ft_error_tab(char *err_msg, t_fdf *env, int i, int j);
void	free_0(t_fdf *env);
void	free_1(t_fdf *env);
void	free_2(t_fdf *env);
void	free_3(t_fdf *env);
void	free_4(t_fdf *env);
void	free_10(t_fdf *env);
void	ft_free_split(char **num, int i, int prev_ind, t_fdf *env);
void	is_map_only_space(char *filepath);
void	flush_get_next_width(int fd, char *line, t_fdf *env);
void	flush_get_next(int fd, char *line);
void	ft_get_z_min_max_map(t_map *map);
void	my_close(int fd, int er_code, t_fdf *env);
#endif
