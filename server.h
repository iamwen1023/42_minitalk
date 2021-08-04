/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:48:50 by wlo               #+#    #+#             */
/*   Updated: 2021/08/04 15:44:31 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
void				handle_sig(int signum, siginfo_t *siginfo, void *context);
struct sigaction	settingSigation(struct sigaction action);

#endif
