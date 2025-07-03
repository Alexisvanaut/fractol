/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:11:09 by alvanaut          #+#    #+#             */
/*   Updated: 2025/06/28 13:11:24 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->win)
		return (1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (0);
}

static void	init_view(t_data *data)
{
	data->min.re = -2.0;
	data->min.im = -2.0;
	data->max.re = 2.0;
	data->max.im = 2.0;
	data->max_iter = 50;
}

static void	init_julia_params(t_data *data, char **argv)
{
	if (ft_strcmp2(argv[1], "julia") == 0 && argv[2] && argv[3])
	{
		data->c.re = atof(argv[2]);
		data->c.im = atof(argv[3]);
	}
	else
	{
		data->c.re = -0.7;
		data->c.im = 0.27015;
	}
}

int	init_data(t_data *data, char **argv)
{
	if (init_mlx(data))
		return (1);
	data->fractal_name = argv[1];
	init_view(data);
	init_julia_params(data, argv);
	return (0);
}
