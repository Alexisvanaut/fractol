/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:16:51 by alvanaut          #+#    #+#             */
/*   Updated: 2025/06/28 13:12:46 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	julia_iterations(t_complex z, t_complex c, int max_iter)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (iter < max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		if ((z.re * z.re + z.im * z.im) > 4)
			break ;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_data *data)
{
	t_complex	z;
	int			iter;
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = data->min.re + (double)x / WIDTH * (data->max.re
					- data->min.re);
			z.im = data->min.im + (double)y / HEIGHT * (data->max.im
					- data->min.im);
			iter = julia_iterations(z, data->c, data->max_iter);
			if (iter == data->max_iter)
				put_pixel(data, x, y, 0x000000);
			else
				put_pixel(data, x, y, get_color(iter, data->max_iter));
			x++;
		}
		y++;
	}
}
