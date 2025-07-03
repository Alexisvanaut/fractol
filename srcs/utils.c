/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvanaut <alvanaut@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:00:00 by alvanaut          #+#    #+#             */
/*   Updated: 2025/07/03 13:48:27 by alvanaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	validate_float_chars(const char *str, int start, int *has_digit,
		int *has_dot)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			*has_digit = 1;
		else if (str[i] == '.' && !*has_dot)
			*has_dot = 1;
		else if (str[i] == '+' || str[i] == '-')
			return (0);
		else if (!ft_isspace(str[i]))
			return (0);
		else
			break ;
		i++;
	}
	return (i);
}

int	is_valid_float(const char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	if (!str || !*str)
		return (0);
	i = 0;
	has_digit = 0;
	has_dot = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	i = validate_float_chars(str, i, &has_digit, &has_dot);
	if (!i)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	return (has_digit && str[i] == '\0');
}

static int	parse_sign_and_skip_spaces(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static double	parse_decimal_part(const char *str, int *i)
{
	double	result;
	double	fraction;

	result = 0.0;
	fraction = 0.1;
	(*i)++;
	while (ft_isdigit(str[*i]))
	{
		result += (str[(*i)++] - '0') * fraction;
		fraction *= 0.1;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;

	if (!str)
		return (0.0);
	result = 0.0;
	sign = 1;
	i = parse_sign_and_skip_spaces(str, &sign);
	while (ft_isdigit(str[i]))
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		result += parse_decimal_part(str, &i);
	return (result * sign);
}
