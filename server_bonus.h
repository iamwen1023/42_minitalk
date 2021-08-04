/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:48:50 by wlo               #+#    #+#             */
/*   Updated: 2021/08/04 13:59:33 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
void				send_message(int signum, siginfo_t *siginfo, void *context);
struct sigaction	settingSigation(struct sigaction action);

#endif
