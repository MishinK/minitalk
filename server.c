/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:46:18 by ashea             #+#    #+#             */
/*   Updated: 2021/07/01 15:46:19 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		i++;
		bit = 0;
	}
	if ((i == 100 ) || (i > 0 && buf[i - 1] == 127))
	{
		write(STDOUT_FILENO, buf, i);
		if (i != 100)
			ft_putchar_fd('\n', STDOUT_FILENO);
		ft_memset(buf, '\0', 100);
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
