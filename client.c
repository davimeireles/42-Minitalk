/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:00:19 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/07 22:50:55 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits_to_server(int c, pid_t PID)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c % 2 == 0)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		c /= 2;
		bits++;
		usleep(150);
	}
}

void	send_byte(pid_t PID, char *string)
{
	int	i;
	int	str_len_null_included;

	i = 0;
	str_len_null_included = ft_strlen(string);
	while (i <= str_len_null_included)
		send_bits_to_server(string[i++], PID);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("You need to put [PID]&[MSG]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (1);
	send_byte(pid, argv[2]);
	return (0);
}
