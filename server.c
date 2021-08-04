/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:48:36 by wlo               #+#    #+#             */
/*   Updated: 2021/08/04 12:09:48 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_message(int signum, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static char	word = 0;

	(void)context;
	(void)siginfo;
	if (signum == SIGUSR1)
		word = (1<<(7 - i)) + word;
	++i;
	if (i == 8)
	{
		write(1, &word, 1);
		i = 0;
		word = 0;
	}
}

struct sigaction	settingSigation(struct sigaction action)
{
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	return (action);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;	

	pid = getpid();
	ft_putstr("PID :");
	ft_putnbr((int)pid);
	ft_putstr("\n");
	action.sa_sigaction = handle_message;
	action = settingSigation(action);
	if (sigaction(SIGUSR1, &action, 0) < 0)
	{
		ft_putstr("sigaction1 error!");
		return (1);
	}
	if (sigaction(SIGUSR2, &action, 0) < 0)
	{
		ft_putstr("sigaction2 error!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
