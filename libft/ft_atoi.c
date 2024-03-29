/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:58:12 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/08/29 11:47:13 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	result;
	int	isnegative;

	result = 0;
	isnegative = 0;
	count = 0;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '\r'
		|| str[count] == '\f' || str[count] == '\t' || str[count] == '\v')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			isnegative = 1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9' && str[count])
	{
		result *= 10;
		result += str[count] - '0';
		count++;
	}
	if (isnegative == 1)
		result *= -1;
	return (result);
}
