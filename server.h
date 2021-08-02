/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:48:50 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 17:49:54 by wlo              ###   ########.fr       */
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
int					exponentInt(int n);
int					convertToDecimal(char *s);
void				handle_message(char *message, int id);
void				handler_new(int signum, siginfo_t *siginfo, void *context);
struct sigaction	settingSigation(struct sigaction action);

#endif
