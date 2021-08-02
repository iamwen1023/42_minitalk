/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:54:55 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 17:57:32 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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

int	exponentInt(int n)
{
	int	i;
	int	result;

	i = 1;
	result = 2;
	while (i < n)
	{
		result = result * 2;
		++i;
	}
	if (n == 0)
		return (1);
	return (result);
}

int	convertToDecimal(char *s)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] != '0')
			num = exponentInt(7 - i) + num;
		i++;
	}
	return (num);
}