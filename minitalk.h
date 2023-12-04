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
# include "libft/libft.h"

void	print_byte(int *bits);
void	signal_handler(int signal);
void	comunic_server(int c, pid_t pid);
void	send_bits(pid_t pid, char *str);
#endif