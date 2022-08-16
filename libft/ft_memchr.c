/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:22:17 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/04/15 17:41:40 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			count;
	unsigned char	*result;
	unsigned char	ch;

	ch = (unsigned char)c;
	count = 0;
	result = (unsigned char *)str;
	while (count < n)
	{
		if (result[count] == ch)
		{
			return (&result[count]);
		}
		count++;
	}
	return (0);
}
