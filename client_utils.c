/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:42:53 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 17:45:26 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_bonus.h"

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

int	exponentInt(int n)
{
	int	i;
	int	result;

	i = 1;
	result = 2;
	while (i < n)
	{
		result = result * 2 ;
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
