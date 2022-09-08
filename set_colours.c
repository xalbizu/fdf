/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:10:50 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/09/08 18:37:29 by xalbizu-         ###   ########.fr       */
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
	data->color_grad = ((data->max_z - data->min_z) / 12);
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
	printf("%d , %d\n", data->min_z, data->max_z);
}
