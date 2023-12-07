/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:42:08 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/07 23:26:02 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

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

void	client_signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		ft_printf("===== Received Signal =====\n");
	exit(EXIT_SUCCESS);
}

void	send_byte(pid_t PID, char *string)
{
	int	i;
	int	str_len_null_included;

	i = 0;
	str_len_null_included = ft_strlen(string);
	while (i <= str_len_null_included)
		send_bits_to_server((unsigned char)string[i++], PID);
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("You need to put [PID]&[MSG]\n");
		return (0);
	}
	act.sa_sigaction = &client_signal_handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("Erro to send signal back to client.");
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (1);
	send_byte(pid, argv[2]);
	return (0);
}
