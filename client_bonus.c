/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:49:01 by wlo               #+#    #+#             */
/*   Updated: 2021/08/04 14:39:36 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	message_end(int id)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(id, SIGUSR2);
		++i;
		usleep(100);
	}
}

void	send_message(char *message, int id)
{
	int	i;
	int	ret;

	while (*message)
	{
		i = -1;
		while (++i < 8)
		{
			if ((*message) & (0x80))
				ret = kill(id, SIGUSR1);
			else
				ret = kill(id, SIGUSR2);
			if (ret == -1)
			{
				ft_putstr("Error happens while sending sig");
				exit(-1);
			}
			*message = *message << 1;
			usleep(100);
		}
		++message;
	}
}

void	receive_message_service(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (signum == SIGUSR2)
		ft_putstr("message from server!\n");
	exit (0);
}

int	main(int argc, char *argv[])
{
	char				*message;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_putstr("Please enter a PID and a message\n");
		return (1);
	}
	act.sa_sigaction = receive_message_service;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR2);
	message = argv[2];
	send_message(message, ft_atoi(argv[1]));
	message_end(ft_atoi(argv[1]));
	if (sigaction(SIGUSR2, &act, 0) < 0)
	{
		ft_putstr("sigaction2 error!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
