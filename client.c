/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:46:38 by ashea             #+#    #+#             */
/*   Updated: 2021/07/01 15:46:39 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int argc, char **argv)
{
	int	pid_server;

	if (argc != 3)
	{
		ft_putstr_fd("expected: ./client [pid server] [message]\n", 2);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server == 0)
	{
		ft_putstr_fd("bad pid server.\n", 2);
		return (1);
	}
	send_message(pid_server, argv[2]);
	return (0);
}
