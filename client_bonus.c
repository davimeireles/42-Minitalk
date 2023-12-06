/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:42:08 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/05 15:55:27 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	sig_handler(int signum)
{
	(void)signum;
	ft_printf("The server send back a signal to the client.");
	exit(0);
}

void	comunic_server(int c, pid_t pid)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c / 2;
		bits++;
		usleep(50);
	}
}

void	send_bits(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		comunic_server((unsigned char)str[i], pid);
		i++;
	}
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
	send_bits(pid, argv[2]);
	return(EXIT_SUCCESS);
}
