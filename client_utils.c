/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:42:53 by wlo               #+#    #+#             */
/*   Updated: 2021/08/04 12:29:48 by wlo              ###   ########.fr       */
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