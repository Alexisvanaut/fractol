/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut < alvanaut@student.s19.be >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:04:49 by alvanaut          #+#    #+#             */
/*   Updated: 2025/06/28 13:19:27 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 1000
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC_KEY 65307

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*fractal_name;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	int			max_iter;

}				t_data;

int				init_data(t_data *data, char **argv);
void			put_pixel(t_data *data, int x, int y, int color);
void			draw_mandelbrot(t_data *data);
int				exit_clean(t_data *data);
int				ft_strcmp2(const char *s1, const char *s2);
void			draw_julia(t_data *data);
int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
int				get_color(int iter, int max_iter);
void			draw_alexis(t_data *data);

#endif
