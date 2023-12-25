/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:48:51 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:11:38 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	line(t_fdf current, t_fdf next, t_fdf *data)
{
	float	max;
	t_fdf	delta;
	int		color;

	color = ft_color(&current, &next);
	ft_set(&current, &next, data);
	delta.matrix.x = next.matrix.x - current.matrix.x;
	delta.matrix.y = next.matrix.y - current.matrix.y;
	max = ft_max(ft_abs(delta.matrix.x), ft_abs(delta.matrix.y));
	delta.matrix.y /= max;
	delta.matrix.x /= max;
	while ((int)(current.matrix.x - next.matrix.x)
		|| (int)(current.matrix.y - next.matrix.y))
	{
		put_pixel(current.matrix.x, current.matrix.y, color, data);
		current.matrix.x += delta.matrix.x;
		current.matrix.y += delta.matrix.y;
		if (current.matrix.x > W_WIDTH || current.matrix.y > W_LENGTH
			|| current.matrix.y < 0 || current.matrix.x < 0)
			break ;
	}
}

void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	image = (int *)(fdf->img_add);
	i = 0;
	while (i < W_WIDTH * W_LENGTH)
	{
		image[i] = BACKGROUND;
		i++;
	}
}

void	draw(t_fdf **matrix)
{
	int		x;
	int		y;
	t_fdf	*data;

	data = *matrix;
	ft_error(*matrix);
	draw_background(*matrix);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], *matrix);
			if (!matrix[y][x].is_end)
				line(matrix[y][x], matrix[y][x + 1], *matrix);
			if (matrix[y][x].is_end)
				break ;
			x++;
		}
		y++;
	}
	image_menu(data);
}
