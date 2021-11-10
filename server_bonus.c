/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:46:18 by ashea             #+#    #+#             */
/*   Updated: 2021/07/01 15:46:19 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_send_answer(char *buf, int i)
{
	int	pid_client;

	pid_client = ft_atoi(buf);
	usleep(10000);
	send_message(pid_client, "SERVER: message delivered");
}

static void	ft_write_message(char *buf, int len, int *flag)
{
	if (*flag == 0)
	{
		write(STDOUT_FILENO, buf, len);
		ft_putchar_fd('\n', STDOUT_FILENO);
		*flag = 1;
	}
	else
	{
		ft_send_answer(buf, len);
		*flag = 0;
	}
	ft_memset(buf, '\0', 100);
}

static void	server_interpreter(int signo)
{
	static size_t	i;
	static int		bit;
	static char		buf[100];
	static int		flag;

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
	{
		ft_write_message(buf, i, &flag);
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		write(STDERR_FILENO, "expected: ./server\n", 16);
		return (1);
	}
	pid = getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (1)
	{
		signal(SIGUSR1, server_interpreter);
		signal(SIGUSR2, server_interpreter);
	}
	return (0);
}
