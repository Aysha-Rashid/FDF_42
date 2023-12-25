/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:38:22 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/12/23 16:11:18 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *y, float *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, float *z, double alpha)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(alpha) + *z * sin(alpha);
	*z = -previous_x * sin(alpha) + *z * cos(alpha);
}

void	rotate_z(float *x, float *y, double alpha)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(alpha) - previous_y * sin(alpha);
	*y = previous_x * sin(alpha) + previous_y * cos(alpha);
}
