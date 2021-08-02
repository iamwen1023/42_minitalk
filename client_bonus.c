/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:49:01 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 18:19:50 by wlo              ###   ########.fr       */
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
		usleep(15);
	}
}

void	handle_message(char *message, int id)
{
	int	i;

	while (*message)
	{
		i = 0;
		while (i < 8)
		{
			if ((*message) & (0x80))
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			*message = *message << 1;
			usleep(15);
			++i;
		}
		++message;
	}
}

void	handler_new(int signum)
{
	static int	i = 0;
	static char	ch[9];
	char		word;

	ch[8] = '\0';
	if (signum == SIGUSR1)
	{
		ch[i] = '1';
		++i;
	}
	if (signum == SIGUSR2)
	{
		ch[i] = '0';
		++i;
	}
	if (i == 8)
	{
		word = convertToDecimal(ch);
		write(1, &word, 1);
		i = 0;
	}
}

struct sigaction	settingSigation(struct sigaction action)
{
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	return (action);
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
	message = argv[2];
	handle_message(message, ft_atoi(argv[1]));
	message_end(ft_atoi(argv[1]));
	act.sa_handler = handler_new;
	act = settingSigation(act);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	if (sigaction(SIGUSR1, &act, 0) < 0 || sigaction(SIGUSR2, &act, 0) < 0)
	{
		ft_putstr("sigaction error!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
