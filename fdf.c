/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:36:19 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/27 12:08:37 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	main(int argc, char *argv[])
{
	t_fdf	*data;

	if (argc == 2)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(data, argv[1]);
	}
	else
		write(1, "Error: 1 arguments expected (./fdf <file with map>)", 52);
	return (0);
}
