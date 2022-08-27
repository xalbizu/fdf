/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:54:46 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/27 15:21:27 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;
	int		i;

	width = 0;
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '9')
			&& (line[i + 1] == ' ' || line[i + 1] == '\n'))
			width++;
		i++;
	}
	free(line);
	close(fd);
	return (width);
}

void	read_file(t_fdf *data, char *file_name)
{
	data->height = get_height(file_name);
	data->width = get_width(file_name);
}
