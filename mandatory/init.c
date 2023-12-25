/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:45:06 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:11:58 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_fdf *data)
{
	if (!data)
		return ;
	data->z_scale = 10;
	data->scale = 20;
	data->yes_isometric = 1;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->x1 = W_WIDTH / 2;
	data->y1 = W_WIDTH / 2;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, W_WIDTH, W_LENGTH, "fdf");
	data->img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_LENGTH);
	data->img_add = mlx_get_data_addr(data->img, &data->bpp,
			&data->size_line, &data->endian);
}

void	zoom(t_fdf *current, t_fdf *next, t_fdf *data)
{
	current->matrix.x *= data->scale;
	current->matrix.y *= data->scale;
	next->matrix.x *= data->scale;
	next->matrix.y *= data->scale;
	current->matrix.z *= data->z_scale;
	next->matrix.z *= data->z_scale;
}

void	ft_set(t_fdf *current, t_fdf *next, t_fdf *data)
{
	zoom(current, next, data);
	if (data->yes_isometric)
	{
		isometric(current);
		isometric(next);
	}
	current->matrix.x += data->x1;
	current->matrix.y += data->y1;
	next->matrix.x += data->x1;
	next->matrix.y += data->y1;
}

int	ft_color(t_fdf *current, t_fdf *next)
{
	int	color;

	color = 0;
	if (current->matrix.color == -1)
	{
		if (next->matrix.z)
			color = NEON_BLUE;
		else if (next->matrix.z != current->matrix.z)
			color = 0xffffff;
		else if (current->matrix.z == next->matrix.z)
			color = GREEN;
		return (color);
	}
	color = current->matrix.color;
	return (color);
}

void	put_pixel(int x, int y, int color, t_fdf *current)
{
	int	i;

	if (x >= 0 && x < W_WIDTH && y < W_LENGTH && y >= 0)
	{
		i = (x * (current->bpp / 8)) + (y * current->size_line);
		current->img_add[i] = color;
		current->img_add[++i] = color >> 8;
		current->img_add[++i] = color >> 16;
	}
}
