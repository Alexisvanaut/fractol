/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:41:27 by alvanaut          #+#    #+#             */
/*   Updated: 2025/06/28 13:12:54 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	mandelbrot_iterations(double c_re, double c_im, int max_iter)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		iter;

	z_re = 0;
	z_im = 0;
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		iter;
	double	c_re;
	double	c_im;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c_re = data->min.re + (double)x / WIDTH * (data->max.re
					- data->min.re);
			c_im = data->min.im + (double)y / HEIGHT * (data->max.im
					- data->min.im);
			iter = mandelbrot_iterations(c_re, c_im, data->max_iter);
			if (iter == data->max_iter)
				put_pixel(data, x, y, 0x000000);
			else
				put_pixel(data, x, y, get_color(iter, data->max_iter));
			x++;
		}
		y++;
	}
}
