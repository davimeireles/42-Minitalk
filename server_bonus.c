/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:41:34 by dmeirele          #+#    #+#             */
/*   Updated: 2023/12/07 23:20:35 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	fill_global_string(int *byte, siginfo_t *info)
{
	int						i;
	unsigned char			character;
	static unsigned char	*global_string = NULL;

	i = 7;
	character = 0;
	while (i >= 0)
		character = character * 2 + byte[i--];
	if (character == '\0')
	{
		ft_printf("%s", global_string);
		free(global_string);
		global_string = NULL;
		kill(info->si_pid, SIGUSR1);
	}
	else
		global_string = ft_str_join(global_string, character);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	byte[8];
	static int	bits = 0;

	(void)context;
	if (signal == SIGUSR1)
		byte[bits++] = 0;
	else
		byte[bits++] = 1;
	if (bits == 8)
	{
		fill_global_string(byte, info);
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = &signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	print_pid(1);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("failed handler\n");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		ft_printf("failed handler\n");
	while (1)
	{
		pause();
	}
}
