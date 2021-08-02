/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:48:36 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 14:18:41 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{	
	long	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		write(1, "-", 1);
		n_long = n_long * (-1);
	}
	if (n_long >= 10)
	{
		ft_putnbr(n_long / 10);
		ft_putchar(n_long % 10 + '0');
	}
	else
		ft_putchar(n_long % 10 + '0');
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

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*s)
	{
		++length;
		s++;
	}
	return (length);
}

char	*ft_strdup(const char *s)
{
	int	len;
	int	i;
	char	*arr;

	len = ft_strlen(s);
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

void handler_new(int signum, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static char ch[9];
	char		word;
	char	*re_message;
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
			re_message = ft_strdup("recerived from server!");
			handle_message(re_message, pid);
		}
		i = 0;
	}
}

int	main()
{
	pid_t pid;
	struct sigaction action;
	siginfo_t siginfo;	

	pid = getpid();
	ft_putstr("PID :");
	ft_putnbr((int)pid);
	ft_putstr("\n");
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
	while (1)
		pause();
	return (0);
}
