/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:13:14 by ashea             #+#    #+#             */
/*   Updated: 2021/07/01 15:13:15 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	send_ascii(pid_t pid, unsigned char c)
{
	int	bit;

	if (c < 32 || c > 127)
		return (1);
	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit--;
	}
	return (0);
}

int	send_message(pid_t pid_server, char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (send_ascii(pid_server, c))
			break ;
		++i;
	}
	c = 127;
	send_ascii(pid_server, c);
	return (0);
}
