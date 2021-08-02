/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:49:01 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 14:02:44 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
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

int exponentInt(int n)
{
    int i;
	int result;

	i = 1;
	result = 2;
	while (i < n)
	{
		result = result*2;
		++i;
	}
	if (n == 0)
		return (1);
    return result;
}

int convertToDecimal(char *s)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while(s[i])
	{
		if (s[i] != '0')
			num = exponentInt(7-i) + num;
		i++;
	}
	return (num);
}

void handler_new(int signum, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static char ch[9];
	char		word;
	pid_t pid;
	
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
		if (word == 0)
		{
			pid = siginfo->si_pid;
			printf("si_pid: %d\n", pid);
			handle_message("recerived from server!", pid);
		}
		i = 0;
	}
}

int main(int argc, char *argv[])
{
	int id;
	char *message;
	struct sigaction action;
	siginfo_t siginfo;
	
	if (argc != 3)
	{
		ft_putstr("Please enter the PID and the context that you would like to send to this PID\n");
		return (1);
	}
	id = ft_atoi(argv[1]);
	message = argv[2];
	handle_message(message, id);
	message_end(id);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler_new;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &action, 0) < 0)
	{
		ft_putstr("sigaction1 error!");
		return 1;
	};
	if (sigaction(SIGUSR2, &action, 0) < 0)
	{
		ft_putstr("sigaction2 error!");
		return 1;
	};
	printf("id : %d\n", id);
	while (1)
		pause();
	return (0);
}