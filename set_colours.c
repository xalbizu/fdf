/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:10:50 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/09/10 19:04:42 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

void	get_max_and_min(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		while (j < data->height)
		{
			if (data->matrix[i][j] > data->max_z)
				data->max_z = data->matrix[i][j];
			else if (data->matrix[i][j] < data->min_z)
				data->min_z = data->matrix[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	data->color_grad = (mod(data->max_z - data->min_z) / 13) * 2;
}

void	set_two_colours(t_fdf *data)
{
	data->colours[1][0] = 0x007aff;
	data->colours[1][1] = 0x0072ff;
	data->colours[1][2] = 0x0067ff;
	data->colours[1][3] = 0x005bff;
	data->colours[1][4] = 0x674bff;
	data->colours[1][5] = 0x9436fe;
	data->colours[1][6] = 0xb40ced;
	data->colours[1][7] = 0xcd00da;
	data->colours[1][8] = 0xe000c5;
	data->colours[1][9] = 0xef00b0;
	data->colours[1][10] = 0xfa009a;
	data->colours[1][11] = 0xff0083;
	data->colours[1][12] = 0xff006d;
}

void	set_colours(t_fdf *data)
{
	get_max_and_min(data);
	data->colours[0][0] = 0xffc31a;
	data->colours[0][1] = 0xffb42b;
	data->colours[0][2] = 0xffa338;
	data->colours[0][3] = 0xff9143;
	data->colours[0][4] = 0xff7d4b;
	data->colours[0][5] = 0xff6851;
	data->colours[0][6] = 0xf25353;
	data->colours[0][7] = 0xd94053;
	data->colours[0][8] = 0xc23054;
	data->colours[0][9] = 0xae2455;
	data->colours[0][10] = 0x9d1c56;
	data->colours[0][11] = 0x8e1859;
	data->colours[0][12] = 0x81195d;
	set_two_colours(data);
}

void	change_colour(t_fdf *data, int col)
{
	data->sc = col;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data, &data->dr);
}

void	pixel_colour(t_fdf *data, float *z)
{
	if ((int)(*z / data->color_grad) > 12)
			data->color = data->colours[data->sc][12];
	else if ((int)(*z / data->color_grad) < 0)
		data->color = data->colours[data->sc][0];
	else
		data->color = data->colours[data->sc][(int)(*z / data->color_grad)];
	*z += data->z_step;
}
