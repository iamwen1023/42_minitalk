/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:49:01 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 13:47:20 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

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
void message_end(int id)
{
	int i;

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
	int i;
	
	while (*message)
	{
		i = 0;
		while( i < 8)
		{
			if ((*message) & (0x80))
			{
				kill(id, SIGUSR1);
				printf("1");
			}
			else
			{
				kill(id, SIGUSR2);
				printf("0");
			}
			*message = *message << 1;
			usleep(15);
			++i;
		}
		printf("\n");
		++message;
	}
}

int main(int argc, char *argv[])
{
	int id;
	char *message;
	
	if (argc != 3)
	{
		ft_putstr("Please enter the PID and the context that you would like to send to this PID\n");
		return (1);
	}
	id = ft_atoi(argv[1]);
	message = argv[2];
	handle_message(message, id);
	message_end(id);
	printf("id : %d\n", id);
	while (1)
		pause();
	return (0);
}