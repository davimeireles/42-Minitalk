/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:01:22 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/04 18:17:00 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include "libft/libft.h"

void    send_byte(pid_t PID, char *string);
void	send_bits_to_server(int c, pid_t PID);
void	signal_handler(int signal, siginfo_t *info, void *context);
void    fill_global_string(int *byte);
void	print_pid(int op);
unsigned char *ft_str_join(unsigned char *global_string, unsigned char character);


#endif