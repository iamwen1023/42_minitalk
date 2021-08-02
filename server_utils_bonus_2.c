/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:00:01 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 18:00:41 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

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
	int		len;
	int		i;
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
