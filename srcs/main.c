/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut <alvanaut@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:43:13 by alvanaut          #+#    #+#             */
/*   Updated: 2025/07/03 13:48:16 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	exit_clean(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

static void	draw_fractal(t_data *data)
{
	if (!data->fractal_name)
		return ;
	if (ft_strcmp2(data->fractal_name, "mandelbrot") == 0)
		draw_mandelbrot(data);
	else if (ft_strcmp2(data->fractal_name, "julia") == 0)
		draw_julia(data);
	else if (ft_strcmp2(data->fractal_name, "alexis") == 0)
		draw_alexis(data);
	else
	{
		exit(EXIT_FAILURE);
	}
}

static void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia [real] [imaginary]\n");
	ft_printf("  ./fractol alexis\n");
	ft_printf("\nExamples:\n");
	ft_printf("  ./fractol julia -0.7 0.27015\n");
	ft_printf("  ./fractol julia -0.8 0.156\n");
	ft_printf("  ./fractol julia 0.285 0.01\n");
}

static int	validate_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (ft_strcmp2(argv[1], "mandelbrot") == 0)
		return (argc == 2);
	else if (ft_strcmp2(argv[1], "julia") == 0)
		return (argc == 2 || argc == 4);
	else if (ft_strcmp2(argv[1], "alexis") == 0)
		return (argc == 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate_args(argc, argv))
	{
		print_usage();
		return (1);
	}
	if (init_data(&data, argv))
	{
		ft_printf("Error: Invalid arguments for Julia set\n");
		ft_printf("Real and imaginary parts must be valid floating point numbers\n");
		print_usage();
		return (1);
	}
	draw_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 17, 0, exit_clean, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
