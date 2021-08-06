/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:49:01 by wlo               #+#    #+#             */
/*   Updated: 2021/08/06 11:57:50 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (sign < 0 && result > 2147483648)
			return (0);
		if (sign > 0 && result > 2147483647)
			return (-1);
	}
	return (((int)result) * sign);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i] != '\0')
		i++;
	write(1, s, i);
}

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
	if (argc != 3)
	{
		ft_putstr("Please enter a PID and a message\n");
		return (1);
	}
	send_message(argv[2], ft_atoi(argv[1]));
	message_end(ft_atoi(argv[1]));
	return (0);
}
