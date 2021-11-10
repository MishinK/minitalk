/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:46:38 by ashea             #+#    #+#             */
/*   Updated: 2021/07/01 15:46:39 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_write_answer(char *buf, int len)
{
	write(STDOUT_FILENO, buf, len);
	ft_putchar_fd('\n', STDOUT_FILENO);
	exit(1);
}

static void	client_interpreter(int signo)
{
	static size_t				i;
	static int					bit;
	static char					buf[100];

	if (signo == SIGUSR1)
		buf[i] |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		buf[i] -= 128;
		i++;
		bit = 0;
	}
	if (i == 100)
	{
		write(STDOUT_FILENO, buf, i);
		ft_memset(buf, '\0', 100);
		i = 0;
	}
	else if ((i > 0 && buf[i - 1] == 0))
		ft_write_answer(buf, i);
}

static void	ft_waiting_answer(void)
{
	while (1)
	{
		signal(SIGUSR1, client_interpreter);
		signal(SIGUSR2, client_interpreter);
	}
}

int	main(int argc, char **argv)
{
	int		pid_server;
	char	*pid_client;

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
	pid_client = ft_itoa(getpid());
	send_message(pid_server, pid_client);
	free(pid_client);
	ft_waiting_answer();
	return (0);
}
