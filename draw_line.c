/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:48:33 by gbonis            #+#    #+#             */
/*   Updated: 2024/05/19 16:50:59 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int	ft_get_color(int x, t_point s, t_point e, double factor)
{
	int		r;
	int		g;
	int		b;
	double	percent;

	percent = ft_abs(x - s.x) / ft_abs(e.x - s.x);
	if (s.reverse)
	{
		r = ft_lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_draw_line_loop(t_point s, t_point e, double gradient, t_fdf *env)
{
	double	inter_y;
	int		x;

	inter_y = (double)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (env->steep)
		{
			ft_put_pixel(env, ft_ipart(inter_y), x,
				ft_get_color(x, s, e, ft_rfpart(inter_y)));
			ft_put_pixel(env, ft_ipart(inter_y) + 1, x,
				ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		else
		{
			ft_put_pixel(env, x, ft_ipart(inter_y),
				ft_get_color(x, s, e, ft_rfpart(inter_y)));
			ft_put_pixel(env, x, ft_ipart(inter_y) + 1,
				ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		inter_y += gradient;
		x++;
	}
}

void	ft_draw_line(t_point s, t_point e, t_fdf *env)
{
	double	dy;
	double	dx;
	double	gradient;

	env->steep = ft_abs(e.y - s.y) > ft_abs(e.x - s.x);
	if (env->steep)
	{
		ft_swap(&s.x, &s.y);
		ft_swap(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x);
		ft_swap(&s.y, &e.y);
		s.reverse = 1;
	}
	dy = (double)(e.y - s.y);
	dx = (double)(e.x - s.x);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.0f;
	ft_draw_line_loop(s, e, gradient, env);
}
