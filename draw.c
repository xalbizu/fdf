/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:59:47 by marvin            #+#    #+#             */
/*   Updated: 2022/09/08 20:08:12 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	num_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	bresenham(t_draw *dr, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	float	z;
	float	z1;

	z = data->matrix[(int)dr->y][(int)dr->x];
	z1 = data->matrix[(int)dr->y1][(int)dr->x1];
	fit_to_screen(data, dr);
	z *= 10;
	z1 *= 10;
	isometric(&dr->x, &dr->y, z);
	isometric(&dr->x1, &dr->y1, z1);
	x_step = dr->x1 - dr->x;
	y_step = dr->y1 - dr->y;
	max = num_max(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(dr->x - dr->x1) || (int)(dr->y - dr->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, dr->x, dr->y, data->color);
		dr->x += x_step;
		dr->y += y_step;
	}
}

void	draw(t_fdf *data, t_draw *dr)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				dr->x = x;
				dr->y = y;
				dr->x1 = x + 1;
				dr->y1 = y;
				bresenham(dr, data);
			}
			if (y < data->height - 1)
			{
				dr->x = x;
				dr->y = y;
				dr->x1 = x;
				dr->y1 = y + 1;
				bresenham(dr, data);
			}
			x++;
		}
		y++;
	}
}

void	fit_to_screen(t_fdf *data, t_draw *dr)
{
	dr->x *= data->zoom;
	dr->y *= data->zoom;
	dr->x1 *= data->zoom;
	dr->y1 *= data->zoom;
	dr->y += data->y_offset;
	dr->y1 += data ->y_offset;
	dr->x += (data->height / data->zoom) + 500 + data->x_offset;
	dr->x1 += (data->height / data->zoom) + 500 + data->x_offset;
}
