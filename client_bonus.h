/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:49:09 by wlo               #+#    #+#             */
/*   Updated: 2021/08/05 11:17:18 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_atoi(const char *str);
void				ft_putstr(char *s);
void				message_end(int id);
void				send_message(char *message, int id);
void				sig_serv(int signum, siginfo_t *siginfo, void *context);

#endif
