/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:49:01 by wlo               #+#    #+#             */
/*   Updated: 2021/08/04 14:39:57 by wlo              ###   ########.fr       */
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
	exit(0);
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
				ft_putstr("Error happens while sending sig to ser");
				exit(-1);
			}	
			*message = *message << 1;
			usleep(100);
		}
		++message;
	}
}

int	main(int argc, char *argv[])
{
	char	*message;

	if (argc != 3)
	{
		ft_putstr("Please enter a PID and a message\n");
		return (1);
	}
	message = argv[2];
	send_message(message, ft_atoi(argv[1]));
	message_end(ft_atoi(argv[1]));
	return (0);
}
