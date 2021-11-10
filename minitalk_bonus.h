/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:48:22 by ashea             #+#    #+#             */
/*   Updated: 2021/07/01 14:48:31 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_memset(void *b, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		send_message(pid_t pid_server, char *str);
#endif
