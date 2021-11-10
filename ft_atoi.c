/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:51:29 by ashea             #+#    #+#             */
/*   Updated: 2021/07/01 14:51:31 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	long	result;
	char	sign;
	long	i;

	i = 0;
	result = 0;
	sign = '+';
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = str[i++];
	if (str[i] == '+' && sign == '-')
		return (0);
	i += (str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (result < 0)
		return ((sign != '-') * -1);
	if (sign == '-')
		result *= -1;
	return ((int)result);
}
