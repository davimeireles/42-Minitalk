/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalkbonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:44:50 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/05 16:00:42 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALKBONUS_H
#define MINITALKBONUS_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "libft/libft.h"

void	print_pid(int op);
void	print_byte(int *bits);
void	signal_handler(int signal);
void	sig_handler(int signum);
void	comunic_server(int c, pid_t pid);
void	send_bits(pid_t pid, char *str);

#endif