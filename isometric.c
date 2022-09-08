/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:45:57 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/09/07 16:52:25 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.92);
	*y = (*x + *y) * sin(0.862) - z;
}
