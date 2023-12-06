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

void    define_handler(void);
void	signal_handler(int signal);
unsigned char   *ft_str_join(unsigned char *str1, unsigned char *str2);
void	send_bits(pid_t pid, char *str);
void	send_bit_to_server(unsigned char c, pid_t pid);
void	print_pid(int op);


#endif