/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalkbonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:44:50 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/07 23:11:47 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALKBONUS_H
# define MINITALKBONUS_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft/libft.h"

void			send_bits_to_server(int c, pid_t PID);
void			client_signal_handler(int sig, siginfo_t *info, void *context);
void			send_byte(pid_t PID, char *string);
void			fill_global_string(int *byte, siginfo_t *info);
void			signal_handler(int signal, siginfo_t *info, void *context);
void			print_pid(int op);
unsigned char	*ft_str_join(unsigned char *global_str, unsigned char c);
void			print_pid(int op);

#endif