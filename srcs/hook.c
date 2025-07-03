/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:27:38 by alvanaut          #+#    #+#             */
/*   Updated: 2025/06/28 13:12:38 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	zoom(t_data *data, double zoom_factor, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	range_re;
	double	range_im;

	mouse_re = data->min.re + (double)x / WIDTH * (data->max.re - data->min.re);
	mouse_im = data->min.im + (double)y / HEIGHT * (data->max.im
			- data->min.im);
	range_re = data->max.re - data->min.re;
	range_im = data->max.im - data->min.im;
	data->min.re = mouse_re - (mouse_re - data->min.re) * zoom_factor;
	data->max.re = data->min.re + range_re * zoom_factor;
	data->min.im = mouse_im - (mouse_im - data->min.im) * zoom_factor;
	data->max.im = data->min.im + range_im * zoom_factor;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		exit_clean(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_UP)
		zoom(data, 0.8, x, y);
	else if (button == SCROLL_DOWN)
		zoom(data, 1.25, x, y);
	else
		return (0);
	if (ft_strcmp2(data->fractal_name, "mandelbrot") == 0)
		draw_mandelbrot(data);
	else if (ft_strcmp2(data->fractal_name, "julia") == 0)
		draw_julia(data);
	else if (ft_strcmp2(data->fractal_name, "alexis") == 0)
		draw_alexis(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
