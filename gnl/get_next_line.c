/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:55:25 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/15 14:33:46 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			nr_bytes;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	line = ft_strndup(buf, ft_strlengnl(buf));
	nr_bytes = 1;
	while (nr_bytes && !ft_findchar(buf) && !ft_findchar(line))
	{
		nr_bytes = read(fd, buf, 1);
		if (nr_bytes < 0)
			return (0);
		if (nr_bytes == 0 && !line)
			return (0);
		buf[nr_bytes] = '\0';
		tmp = ft_strjoingnl(line, buf);
		free(line);
		line = tmp;
	}
	buffer(buf, BUFFER_SIZE);
	updateline(line, ft_strlengnl(line));
	return (line);
}

void	updateline(char *line, int size)
{
	int	cont;

	cont = 0;
	if (!line)
		return ;
	while (line[cont] && line[cont] != '\n')
		cont++;
	if (line[cont] == '\n')
		cont++;
	while (cont < size && line[cont])
	{
		line[cont] = '\0';
		cont++;
	}
}

void	buffer(char *buf, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[j] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		buf[j] = buf[++i];
		j++;
		i++;
	}
	while (i < size && buf[j])
	{
		buf[j] = buf[i];
		i++;
		j++;
	}
	while (j < size && buf[j])
	{
		buf[j] = '\0';
		j++;
	}
}

/* int	main(void)
{
	ssize_t	fd = open("fd.txt", O_RDONLY);
	size_t	i = 3;
	char	*line;
	while (i--)
	{
		line = get_next_line(fd);
		printf("line %zu = %s", i, line);
		free(line);
	}
	close(fd);
	return (0);
} */