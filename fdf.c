/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:36:19 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/16 16:26:22 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib.h"
#include <stdio.h>
#include <fcntl.h>

int	**open_map(char *dir);
int	ft_numlen(const char *str);
int	**int_matrix(int dim);
int	**asign_matrix(int **mat, char *buf);

int	main(int argc, char *argv[])
{
	int	**map;

	if (argc == 2)
	{
		map = open_map(argv[1]);
	}
	else
		write(1, "Error: 1 arguments expected (./fdf <file with map>)", 52);
	return (0);
}

int	**open_map(char *dir)
{
	int		fd;
	int		i;
	int		j;
	int		**matrix;
	char	*buf;

	fd = open(dir, O_RDONLY);
	j = ft_numlen(get_next_line(fd));
	i = 1;
	while (get_next_line(fd))
		i++;
	matrix = int_matrix(i);
	buf = malloc(10);
	close(fd);
	fd = open(dir, O_RDONLY);
	read(fd, buf, 10);
	buf[9] = '\0';
	printf ("%s\n", buf);
	return (asign_matrix(matrix, buf));
}

int	**asign_matrix(int **mat, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (buf[i])
	{
		if (buf[i] <= '9' && buf[i] >= '0')
		{
			mat[j][k] = buf[i] - '0';
			k++;
		}
		else if (buf[i] == '\n')
		{
			k = 0;
			j++;
		}
		i++;
	}
	free(buf);
	return (mat);
}

int	**int_matrix(int dim)
{
	int	i;
	int	**matrix;

	i = 0;
	matrix = malloc(dim * sizeof(int *));
	while (i < dim)
	{
		matrix[i] = malloc(dim * sizeof(int));
		i++;
	}
	return (matrix);
}

int	ft_numlen(const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		i++;
	}	
	return (count);
}
